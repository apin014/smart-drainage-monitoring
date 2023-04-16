#ifndef FLOWSENSOR_H
#define FLOWSENSOR_H

#include <Arduino.h>

class FlowSensor {
  private:
    uint8_t pin;
    uint8_t interruptPin;
    float k_factor;
  
  public:
    FlowSensor(uint8_t pin);
    void init();
    float getFlowrate(int pulseCount, unsigned long elapsedTime);
    uint8_t getInterruptPin();
};

#endif