#ifndef WATER_LEVEL_H
#define WATER_LEVEL_H

#include <Arduino.h>

class WaterLevel {
  private:
    uint8_t analogPin;

  public:
    WaterLevel(uint8_t analogPin);
    void init();
    float getWaterLevel(float analogValue);
};

#endif