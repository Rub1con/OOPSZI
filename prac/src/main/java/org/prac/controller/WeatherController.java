package org.prac.controller;


import org.prac.Parser;
import org.prac.dao.WeatherDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.core.io.FileSystemResource;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@RequestMapping("/weather")
@ComponentScan("com.project")
public class WeatherController {

    private final WeatherDao weatherDB;

    @Autowired
    private WeatherDao weatherDao;

    @Autowired
    WeatherController(WeatherDao weatherDao) {
        this.weatherDB = weatherDao;
    }

    @GetMapping()
    public String startPage()
    {
        return "index";
    }

    @GetMapping("/reset-data")
    public String resetData()
    {
        weatherDB.update(Parser.getWeather());
        return "redirect:/weather/first-page";
    }


    @GetMapping("/table")
    public String table(Model model) {
        model.addAttribute("weathers", weatherDao.showTable());
        return "table";

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
        weatherDB.minusItems();
        return "redirect:/weather/mid-page";
    }

    @GetMapping("/download")
    @ResponseBody
    public FileSystemResource download() {
        return new FileSystemResource("C:/Users/porti/IdeaProjects/prac/src/main/resources/weather.json");
    }

}
