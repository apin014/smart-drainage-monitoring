#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic {
  private:
    uint8_t trigPin, echoPin;
    static float SOUND_SPEED; 

  public:
    Ultrasonic(uint8_t trigPin, uint8_t echoPin);
    void init();
    void clearTrig();
    void activateTrig();
    float calculateDist();
};

#endif