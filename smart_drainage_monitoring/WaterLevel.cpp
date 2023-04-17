#include "WaterLevel.h"

WaterLevel::WaterLevel(uint8_t analogPin) {
  this->analogPin = analogPin;
  init();
}

void WaterLevel::init() {
  //do nothing just yet
}

float WaterLevel::getWaterLevel(float analogValue) {
  return (analogValue * (6.5 / 4095));
}