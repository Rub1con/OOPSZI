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
        "global_id",
        "Number",
        "Cells"
})
@Generated("jsonschema2pojo")
public class Weather {

    @JsonProperty("global_id")
    private Integer globalId;
    @JsonProperty("Number")
    private Integer number;
    @JsonProperty("Cells")
    private Cells cells;
    @JsonIgnore
    private Map<String, Object> additionalProperties = new HashMap<String, Object>();

    @JsonProperty("global_id")
    public Integer getGlobalId() {
        return globalId;
    }

    @JsonProperty("global_id")
    public void setGlobalId(Integer globalId) {
        this.globalId = globalId;
    }

    @JsonProperty("Number")
    public Integer getNumber() {
        return number;
    }

    @JsonProperty("Number")
    public void setNumber(Integer number) {
        this.number = number;
    }

    @JsonProperty("Cells")
    public Cells getCells() {
        return cells;
    }

    @JsonProperty("Cells")
    public void setCells(Cells cells) {
        this.cells = cells;
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
        return "Weather{" +
                "globalId=" + globalId +
                ", number=" + number +
                ", cells=" + cells +
                ", additionalProperties=" + additionalProperties +
                '}';
    }
}
