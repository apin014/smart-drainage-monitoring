#include "Weather.h"

WeatherSensor::WeatherSensor(uint8_t pin, uint8_t type) : internal(pin, type) {
  this->pin = pin;
  this->type = type;
  init();
}

void WeatherSensor::init() {
  //do nothing just yet
}

void WeatherSensor::begin() {
  this->internal.begin();
}

float WeatherSensor::getTemperature(bool fahrenheit) {
  if (fahrenheit) {
    return this->internal.readTemperature(true);
  }
  return this->internal.readTemperature();
}

float WeatherSensor::getHumidity() {
  return this->internal.readHumidity();
}