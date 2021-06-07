package org.prac.entity;

import javax.persistence.*;
import java.io.Serializable;

@Entity
@Table(name = "weather")
public class WeatherEntity implements Serializable {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;
    @Column(name = "forecast_type")
    private String forecastType;
    @Column(name = "start_forecast")
    private String startForecast;
    @Column(name = "end_forecast")
    private String endForecast;
    @Column(name = "type_precipitation")
    private String typePrecipitation;
    @Column(name = "min_temperature")
    private String minTemperature;
    @Column(name = "max_temperature")
    private String maxTemperature;
    @Column(name = "note")
    private String note;

    public WeatherEntity() {}

    public WeatherEntity(int id, String forecastType, String startForecast, String endForecast,
                         String typePrecipitation, String minTemperature, String maxTemperature, String note) {
        this.id = id;
        this.forecastType = forecastType;
        this.startForecast = startForecast;
        this.endForecast = endForecast;
        this.typePrecipitation = typePrecipitation;
        this.minTemperature = minTemperature;
        this.maxTemperature = maxTemperature;
        this.note = note;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getForecastType() {
        return forecastType;
    }

    public void setForecastType(String forecastType) {
        this.forecastType = forecastType;
    }

    public String getStartForecast() {
        return startForecast;
    }

    public void setStartForecast(String startForecast) {
        this.startForecast = startForecast;
    }

    public String getEndForecast() {
        return endForecast;
    }

    public void setEndForecast(String endForecast) {
        this.endForecast = endForecast;
    }

    public String getTypePrecipitation() {
        return typePrecipitation;
    }

    public void setTypePrecipitation(String typePrecipitation) {
        this.typePrecipitation = typePrecipitation;
    }

    public String getMinTemperature() {
        return minTemperature;
    }

    public void setMinTemperature(String minTemperature) {
        this.minTemperature = minTemperature;
    }

    public String getMaxTemperature() {
        return maxTemperature;
    }

    public void setMaxTemperature(String maxTemperature) {
        this.maxTemperature = maxTemperature;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }

    @Override
    public String toString() {
        return "WeatherEntity{" +
                "id=" + id +
                ", forecastType='" + forecastType + '\'' +
                ", startForecast='" + startForecast + '\'' +
                ", endForecast='" + endForecast + '\'' +
                ", typePrecipitation='" + typePrecipitation + '\'' +
                ", minTemperature='" + minTemperature + '\'' +
                ", maxTemperature='" + maxTemperature + '\'' +
                ", note='" + note + '\'' +
                '}';
    }
}
