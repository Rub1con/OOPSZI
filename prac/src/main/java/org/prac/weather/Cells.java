package org.prac.weather;

import java.util.HashMap;
import java.util.Map;
import javax.annotation.Generated;
import com.fasterxml.jackson.annotation.JsonAnyGetter;
import com.fasterxml.jackson.annotation.JsonAnySetter;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.annotation.JsonPropertyOrder;

@JsonInclude(JsonInclude.Include.NON_NULL)
@JsonPropertyOrder({
        "ForecastDate",
        "ForecastType",
        "ForecastStart",
        "ForecastEnd",
        "PrecipitationProbability",
        "WeatherConditions",
        "PrecipitationType",
        "ExpectedPrecipitationAmount",
        "MinimumTemperature",
        "MaximumTemperature",
        "WindDirection",
        "WindSpeed",
        "PrecipitationAmountDay",
        "Notes",
        "global_id"
})
@Generated("jsonschema2pojo")
public class Cells {

    @JsonProperty("ForecastDate")
    private String forecastDate;
    @JsonProperty("ForecastType")
    private String forecastType;
    @JsonProperty("ForecastStart")
    private String forecastStart;
    @JsonProperty("ForecastEnd")
    private String forecastEnd;
    @JsonProperty("PrecipitationProbability")
    private Object precipitationProbability;
    @JsonProperty("WeatherConditions")
    private Object weatherConditions;
    @JsonProperty("PrecipitationType")
    private String precipitationType;
    @JsonProperty("ExpectedPrecipitationAmount")
    private Object expectedPrecipitationAmount;
    @JsonProperty("MinimumTemperature")
    private Integer minimumTemperature;
    @JsonProperty("MaximumTemperature")
    private Integer maximumTemperature;
    @JsonProperty("WindDirection")
    private Object windDirection;
    @JsonProperty("WindSpeed")
    private Object windSpeed;
    @JsonProperty("PrecipitationAmountDay")
    private Object precipitationAmountDay;
    @JsonProperty("Notes")
    private String notes;
    @JsonProperty("global_id")
    private Integer globalId;
    @JsonIgnore
    private Map<String, Object> additionalProperties = new HashMap<String, Object>();

    @JsonProperty("ForecastDate")
    public String getForecastDate() {
        return forecastDate;
    }

    @JsonProperty("ForecastDate")
    public void setForecastDate(String forecastDate) {
        this.forecastDate = forecastDate;
    }

    @JsonProperty("ForecastType")
    public String getForecastType() {
        return forecastType;
    }

    @JsonProperty("ForecastType")
    public void setForecastType(String forecastType) {
        this.forecastType = forecastType;
    }

    @JsonProperty("ForecastStart")
    public String getForecastStart() {
        return forecastStart;
    }

    @JsonProperty("ForecastStart")
    public void setForecastStart(String forecastStart) {
        this.forecastStart = forecastStart;
    }

    @JsonProperty("ForecastEnd")
    public String getForecastEnd() {
        return forecastEnd;
    }

    @JsonProperty("ForecastEnd")
    public void setForecastEnd(String forecastEnd) {
        this.forecastEnd = forecastEnd;
    }

    @JsonProperty("PrecipitationProbability")
    public Object getPrecipitationProbability() {
        return precipitationProbability;
    }

    @JsonProperty("PrecipitationProbability")
    public void setPrecipitationProbability(Object precipitationProbability) {
        this.precipitationProbability = precipitationProbability;
    }

    @JsonProperty("WeatherConditions")
    public Object getWeatherConditions() {
        return weatherConditions;
    }

    @JsonProperty("WeatherConditions")
    public void setWeatherConditions(Object weatherConditions) {
        this.weatherConditions = weatherConditions;
    }

    @JsonProperty("PrecipitationType")
    public String getPrecipitationType() {
        return precipitationType;
    }

    @JsonProperty("PrecipitationType")
    public void setPrecipitationType(String precipitationType) {
        this.precipitationType = precipitationType;
    }

    @JsonProperty("ExpectedPrecipitationAmount")
    public Object getExpectedPrecipitationAmount() {
        return expectedPrecipitationAmount;
    }

    @JsonProperty("ExpectedPrecipitationAmount")
    public void setExpectedPrecipitationAmount(Object expectedPrecipitationAmount) {
        this.expectedPrecipitationAmount = expectedPrecipitationAmount;
    }

    @JsonProperty("MinimumTemperature")
    public Integer getMinimumTemperature() {
        return minimumTemperature;
    }

    @JsonProperty("MinimumTemperature")
    public void setMinimumTemperature(Integer minimumTemperature) {
        this.minimumTemperature = minimumTemperature;
    }

    @JsonProperty("MaximumTemperature")
    public Integer getMaximumTemperature() {
        return maximumTemperature;
    }

    @JsonProperty("MaximumTemperature")
    public void setMaximumTemperature(Integer maximumTemperature) {
        this.maximumTemperature = maximumTemperature;
    }

    @JsonProperty("WindDirection")
    public Object getWindDirection() {
        return windDirection;
    }

    @JsonProperty("WindDirection")
    public void setWindDirection(Object windDirection) {
        this.windDirection = windDirection;
    }

    @JsonProperty("WindSpeed")
    public Object getWindSpeed() {
        return windSpeed;
    }

    @JsonProperty("WindSpeed")
    public void setWindSpeed(Object windSpeed) {
        this.windSpeed = windSpeed;
    }

    @JsonProperty("PrecipitationAmountDay")
    public Object getPrecipitationAmountDay() {
        return precipitationAmountDay;
    }

    @JsonProperty("PrecipitationAmountDay")
    public void setPrecipitationAmountDay(Object precipitationAmountDay) {
        this.precipitationAmountDay = precipitationAmountDay;
    }

    @JsonProperty("Notes")
    public String getNotes() {
        return notes;
    }

    @JsonProperty("Notes")
    public void setNotes(String notes) {
        this.notes = notes;
    }

    @JsonProperty("global_id")
    public Integer getGlobalId() {
        return globalId;
    }

    @JsonProperty("global_id")
    public void setGlobalId(Integer globalId) {
        this.globalId = globalId;
    }

    @JsonAnyGetter
    public Map<String, Object> getAdditionalProperties() {
        return this.additionalProperties;
    }

    @JsonAnySetter
    public void setAdditionalProperty(String name, Object value) {
        this.additionalProperties.put(name, value);
    }

    @Override
    public String toString() {
        return "Cells{" +
                "forecastDate='" + forecastDate + '\'' +
                ", forecastType='" + forecastType + '\'' +
                ", forecastStart='" + forecastStart + '\'' +
                ", forecastEnd='" + forecastEnd + '\'' +
                ", precipitationProbability=" + precipitationProbability +
                ", weatherConditions=" + weatherConditions +
                ", precipitationType='" + precipitationType + '\'' +
                ", expectedPrecipitationAmount=" + expectedPrecipitationAmount +
                ", minimumTemperature=" + minimumTemperature +
                ", maximumTemperature=" + maximumTemperature +
                ", windDirection=" + windDirection +
                ", windSpeed=" + windSpeed +
                ", precipitationAmountDay=" + precipitationAmountDay +
                ", notes='" + notes + '\'' +
                ", globalId=" + globalId +
                ", additionalProperties=" + additionalProperties +
                '}';
    }
}

