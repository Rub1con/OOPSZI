package org.prac;

import org.prac.weather.Weather;
import org.springframework.scheduling.annotation.EnableScheduling;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.web.client.RestTemplate;

@EnableScheduling
public class Parser {
    @Scheduled(fixedDelay = 30000)
    public static Weather[] getWeather() {
        final RestTemplate restTemplate = new RestTemplate();
        Weather[] weather = restTemplate.getForObject("https://apidata.mos.ru/v1/datasets/60667/rows?api_key=05dd21f471b27aecb18532c619d67261", Weather[].class);

        return weather;
    }

}
