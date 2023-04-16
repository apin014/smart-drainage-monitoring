#include "Ultrasonic.h"

float Ultrasonic::SOUND_SPEED;

Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  init();
}

void Ultrasonic::init() {
  pinMode(this->trigPin, OUTPUT);
  pinMode(this->echoPin, INPUT);
  Ultrasonic::SOUND_SPEED = 0.0346;
}

void Ultrasonic::clearTrig() {
  digitalWrite(this->trigPin, LOW);
  delayMicroseconds(2);
}

void Ultrasonic::activateTrig() {
  digitalWrite(this->trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trigPin, LOW);
}

float Ultrasonic::calculateDist() {
  long duration = pulseIn(this->echoPin, HIGH);
  float distanceCm = duration * Ultrasonic::SOUND_SPEED / 2;
  return distanceCm;
}