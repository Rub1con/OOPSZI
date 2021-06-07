package org.prac.dao;

import org.hibernate.Session;
import org.hibernate.query.Query;
import org.prac.entity.WeatherEntity;
import org.prac.util.HibernateSessionFactoryUtil;
import org.prac.weather.Weather;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BatchPreparedStatementSetter;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;

import java.math.BigInteger;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.List;
import java.util.Objects;

@Component
public class WeatherDao {
    private JdbcTemplate jdbcTemplate;

    private static int cellsPerPage = -20;
    private static int tableSize;
    
    public WeatherDao() {}

    public void setCellsPerPage(int cellsPerPage) {
        WeatherDao.cellsPerPage = cellsPerPage;
    }

    public int getCellsPerPage() {
        return cellsPerPage;
    }

    public int getTableSize() {
        return tableSize;
    }


    static {
        try (Session session = HibernateSessionFactoryUtil.getSessionFactory().getCurrentSession()) {
            session.beginTransaction();
            Query query = session.createSQLQuery("SELECT COUNT(*) FROM weather;");
            List<BigInteger> rows = query.list();
            session.getTransaction().commit();

            tableSize = rows.get(0).intValue();
        }
    }

    @Autowired
    public WeatherDao(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    public void update(Weather[] weathers) {

        tableSize = weathers.length;
        cellsPerPage = -20;
        clearTable();
        resetSequence();

        try (Connection con = Objects.requireNonNull(jdbcTemplate.getDataSource()).getConnection()) {

            jdbcTemplate.batchUpdate("INSERT INTO weather (forecast_type, start_forecast, end_forecast, " +
                            "type_precipitation, min_temperature, max_temperature, note) VALUES(?,?,?,?,?,?,?)",
                    new BatchPreparedStatementSetter() {
                        @Override
                        public void setValues(PreparedStatement ps, int i) throws SQLException {
                            ps.setString(1, weathers[i].getCells().getForecastType());
                            ps.setString(2, weathers[i].getCells().getForecastStart());
                            ps.setString(3, weathers[i].getCells().getForecastEnd());
                            ps.setString(4, weathers[i].getCells().getPrecipitationType());
                            ps.setInt(5, weathers[i].getCells().getMinimumTemperature());
                            ps.setInt(6, weathers[i].getCells().getMaximumTemperature());
                            ps.setString(7, weathers[i].getCells().getNotes());

                        }

                        @Override
                        public int getBatchSize() {
                            return weathers.length;
                        }
                    });

        } catch (SQLException ignore) {
        }
    }

    public void clearTable() {
        try (Session session = HibernateSessionFactoryUtil.getSessionFactory().getCurrentSession()) {
            session.beginTransaction();
            session.createQuery("DELETE WeatherEntity ").executeUpdate();
            session.getTransaction().commit();
        }
    }
    public List<WeatherEntity> showTable() {
        List<WeatherEntity> weatherList;

        try (Session session = HibernateSessionFactoryUtil.getSessionFactory().getCurrentSession()) {
            session.beginTransaction();
            weatherList = session.createQuery("from WeatherEntity").getResultList();
            session.getTransaction().commit();
        }

            return weatherList;
        }

    public void plusItems() {
        cellsPerPage += 20;
    }

    public void minusItems() {
        cellsPerPage -= 20;
    }

    public List<WeatherEntity> getCells() {
        List<WeatherEntity> weatherList;

        try (Session session = HibernateSessionFactoryUtil.getSessionFactory().getCurrentSession()) {
            session.beginTransaction();

            String hql = "FROM WeatherEntity order by id";
            Query query = session.createQuery(hql);
            query.setFirstResult(cellsPerPage);
            query.setMaxResults(20);

            weatherList = query.list();

            session.getTransaction().commit();
        }

        return weatherList;
    }

    public void resetSequence() {
        try (Session session = HibernateSessionFactoryUtil.getSessionFactory().getCurrentSession()) {
            session.beginTransaction();
            session.createSQLQuery("ALTER SEQUENCE weather_tb_number_seq RESTART WITH 1;").executeUpdate();
            session.getTransaction().commit();
        }
    }
    public WeatherEntity getWeatherById(int id) {
        WeatherEntity weather;

        try (Session session = HibernateSessionFactoryUtil.getSessionFactory().getCurrentSession()) {
            session.beginTransaction();

            String hql = "FROM WeatherEntity as weather where weather.id = :id";
            Query query = session.createQuery(hql);
            query.setParameter("id", id);
            weather = (WeatherEntity) query.uniqueResult();
            session.getTransaction().commit();
        }

        return weather;
    }

    }


