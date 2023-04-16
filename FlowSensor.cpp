#include "FlowSensor.h"

FlowSensor::FlowSensor(uint8_t pin) {
  this->pin = pin;
  this->interruptPin = pin;
  init();
}

void FlowSensor::init() {
  this->k_factor = 6.6;
}

float FlowSensor::getFlowrate(int pulseCount, unsigned long elapsedTime) {
  float flowrate = ((1000.0/elapsedTime) * pulseCount)/this->k_factor;
  return flowrate;
}

uint8_t FlowSensor::getInterruptPin() {
  return this->interruptPin;
}