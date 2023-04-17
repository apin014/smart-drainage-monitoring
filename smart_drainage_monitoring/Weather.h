#ifndef WEATHER_H
#define WEATHER_H

#include <Arduino.h>
#include <DHT.h>

class WeatherSensor {
  private:
    uint8_t pin;
    uint8_t type;
    DHT internal;

  public:
    WeatherSensor(uint8_t pin, uint8_t type);
    void init();
    void begin();
    float getTemperature(bool fahrenheit = false);
    float getHumidity();
};

#endif