#include <Arduino.h>
#include <PWM.h>

PWM PWMControl;

void setup() {
  PWMControl.PWMSetup();
  PWMControl.PWMDutySet(50); 
}

void loop() {
  PWMControl.PWMFreqency();
}
