package org.prac.serialized;


import org.prac.dao.WeatherDao;
import org.prac.entity.WeatherEntity;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Serializer {
    private static List<WeatherEntity> weatherList;
    private static WeatherDao weatherDao = new WeatherDao();

    static {
        weatherList = deserialize();
    }

    public static List<WeatherEntity> getWeatherList() {
        return weatherList;
    }

    public static void setWeatherList(List<WeatherEntity> weatherList) {
        Serializer.weatherList = weatherList;
    }

    public static boolean isUnique(int id) {
        for (WeatherEntity weather : weatherList) {
            if (weather.getId() == id) {
                return false;
            }
        }
        return true;
    }

    public static void saveToFavorite() {
        try (FileOutputStream fos = new FileOutputStream("C:/Users/porti/IdeaProjects/prac/src/main/resources/favorites.txt", false)) {
            ObjectOutputStream outStream = new ObjectOutputStream(fos);
            outStream.writeObject(weatherList);
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    public static void saveToFavoriteById(int id) {
        weatherList.add(weatherDao.getWeatherById(id));
        try (FileOutputStream fos = new FileOutputStream("C:/Users/porti/IdeaProjects/prac/src/main/resources/favorites.txt", false)) {
            ObjectOutputStream outStream = new ObjectOutputStream(fos);
            outStream.writeObject(weatherList);
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    public static List<WeatherEntity> deserialize() {

        try (FileInputStream fis = new FileInputStream("C:/Users/porti/IdeaProjects/prac/src/main/resources/favorites.txt")) {
            ObjectInputStream inputStream = new ObjectInputStream(fis);
            weatherList = (List<WeatherEntity>) inputStream.readObject();
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }

        if (weatherList == null) {
            return new ArrayList<>();
        }

        return weatherList;
    }

    public static void removeFromFavorites(int id) {
        weatherList.removeIf(ch -> ch.getId() == id);
        Serializer.saveToFavorite();
    }

    public static void clearFavorites() {
        weatherList.clear();
        Serializer.saveToFavorite();
    }
}