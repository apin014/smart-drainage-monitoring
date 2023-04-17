#include "FlowSensor.h"
#include "WaterLevel.h"
#include "Weather.h"

#define WATER_FLOW_SENSOR_1 35
#define WATER_FLOW_SENSOR_2 34

volatile int pulseCount1 = 0;
volatile int pulseCount2 = 0;
float flowrate1 = 0.0;
float flowrate2 = 0.0;
unsigned long oldTime = 0;

FlowSensor waterflow1(WATER_FLOW_SENSOR_1);
FlowSensor waterflow2(WATER_FLOW_SENSOR_2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(WATER_FLOW_SENSOR_1, INPUT_PULLUP);
  pinMode(WATER_FLOW_SENSOR_2, INPUT_PULLUP);
  attachInterrupt(waterflow1.getInterruptPin(), ISR1, FALLING);
  attachInterrupt(waterflow2.getInterruptPin(), ISR2, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis(); // Get current time
  // Calculate time elapsed since last calculation
  unsigned long elapsedTime = currentTime - oldTime;

  if (elapsedTime >= 1000) {
    detachInterrupt(waterflow1.getInterruptPin());
    detachInterrupt(waterflow1.getInterruptPin());
    flowrate1 = waterflow1.getFlowrate(pulseCount1, elapsedTime);
    pulseCount1 = 0;
    flowrate2 = waterflow2.getFlowrate(pulseCount2, elapsedTime);
    pulseCount2 = 0;
    oldTime = currentTime;
    attachInterrupt(waterflow1.getInterruptPin(), ISR1, FALLING);
    attachInterrupt(waterflow2.getInterruptPin(), ISR2, FALLING);
  }

  if (flowrate1 > 0.0 || flowrate2 > 0.0) {
    Serial.print("Waterflow Sensor 1: ");
    Serial.println(flowrate1);
    Serial.print("Waterflow sensor 2: ");
    Serial.println(flowrate2);
  }

  delay(1000);
}

void ISR1() {
  pulseCount1++;
}

void ISR2() {
  pulseCount2++;
}

