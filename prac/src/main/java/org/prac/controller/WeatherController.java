package org.prac.controller;

import org.prac.Parser;
import org.prac.dao.WeatherDao;
import org.prac.serialized.Serializer;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.core.io.FileSystemResource;
import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

@Controller
@RequestMapping("/weather")
@ComponentScan("org.prac")
public class WeatherController {

    @Autowired
    private WeatherDao weatherDao;

    @PostMapping("/add-to-favorite")
    public String addToFavorite(@RequestParam(value = "favoriteWeatherId") int favoriteWeatherId) {
        if (Serializer.isUnique(favoriteWeatherId)) {
            Serializer.saveToFavoriteById(favoriteWeatherId);
            return "redirect:/weather/first-page";
        } else {
            return "favoritesWarning";
        }
    }

    @PostMapping("/add-to-favorite-for-present-page")
    public String addToFavoritePresentTable(@RequestParam(value = "favoriteWeatherId") int favoriteWeatherId) {
        if (Serializer.isUnique(favoriteWeatherId)) {
            Serializer.saveToFavoriteById(favoriteWeatherId);
            return "redirect:/weather/show";
        } else {
            return "favoritesWarning";
        }
    }

    @PostMapping("/remove-from-favorite")
    public String removeToFavorite(@RequestParam(value = "favoriteWeatherId") int favoriteWeatherId) {
        Serializer.removeFromFavorites(favoriteWeatherId);
        return "redirect:/weather/favorites";
    }

    @GetMapping("/favorites")
    public String showFavorites(Model model) {
        model.addAttribute("weathers", Serializer.deserialize());
        return "favorites";
    }


    @GetMapping()
    public String startPage()
    {
        return "index";
    }


    @GetMapping("/reset-data")
    public String resetData()
    {
        weatherDao.update(Parser.getWeather());
        return "redirect:/weather/first-page";
    }


    @GetMapping("/table")
    public String table(Model model) {
        model.addAttribute("weathers", weatherDao.showTable());
        return "table";

    }
    @GetMapping("/go-to-first")
    public String goToFirst() {
        weatherDao.setCellsPerPage(-20);
        return "redirect:/weather/first-page";
    }
    @GetMapping("/go-to-last")
    public String goToLast() {
        weatherDao.setCellsPerPage(weatherDao.getTableSize()-20);
        return "redirect:/weather/last-page";
    }
    @GetMapping("/first-page")
    public String getFirstPage(Model model) {
        if (weatherDao.getCellsPerPage() == 0) {
            model.addAttribute("weathers", weatherDao.getCells());
            return "firstPage";
        }
        if (weatherDao.getCellsPerPage() >= 20) {
            return "redirect:/weather/mid-page";
        }
        weatherDao.plusItems();
        model.addAttribute("weathers", weatherDao.getCells());
        return "firstPage";
    }

    @GetMapping("/mid-page")
    public String getMidPage(Model model) {
        if (weatherDao.getCellsPerPage() == 0) {
            return "redirect:/weather/first-page";
        }
        if (weatherDao.getCellsPerPage() >= weatherDao.getTableSize() - 20) {
            return "redirect:/weather/last-page";
        }
        model.addAttribute("weathers", weatherDao.getCells());
        return "midPage";
    }

    @GetMapping("/last-page")
    public String getLastPage(Model model) {
        model.addAttribute("weathers", weatherDao.getCells());
        return "lastPage";
    }

    @GetMapping("/add-items")
    public String addItems() {
        weatherDao.plusItems();
        return "redirect:/weather/mid-page";
    }

    @GetMapping("/remove-items")
    public String removeItems() {
        weatherDao.minusItems();
        return "redirect:/weather/mid-page";
    }

    @GetMapping("/download")
    @ResponseBody
    public FileSystemResource download() {
        return new FileSystemResource("C:/Users/porti/IdeaProjects/prac/src/main/resources/weather.json");
    }

}
