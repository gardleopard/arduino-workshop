#include "TM1638.h"
#define SONAR_TRIG 0
#define SONAR_ECHO 1
#define DELAY_TIME 500

TM1638 module(6, 7, 5);

void setup(){
  pinMode(SONAR_TRIG, OUTPUT);
  pinMode(SONAR_ECHO, INPUT);
}

void loop(){
  long duration, distance;
  digitalWrite(SONAR_TRIG, HIGH);

  delayMicroseconds(10);
  digitalWrite(SONAR_TRIG, LOW);
  duration = pulseIn(SONAR_ECHO, HIGH);
  distance = duration/59;
  module.setDisplayToDecNumber(distance, 0, false);

  delay(DELAY_TIME);
}
