#include <Arduino.h>
#include <PWM.h>

PWM PWMControl;
float Duty = 100; 




void setup() {
  Serial.begin(9600);
  PWMControl.PWMSetup();
  PWMControl.PWMDutySet(Duty); 
}

//Test cases -> TODO

void loop() {
  Serial.println(Duty);

  /*
  PWMControl.PWMDutySet(Duty); 
  if(Duty < 100)
  {
    Duty = Duty + 10;
  }
  else 
  {
    Duty = 0;
  }
  */
  delay(1000);
}
