#ifndef PWM_H
#define PWM_H
#include <Arduino.h>



class PWM {
    public:
    PWM();
    ~PWM();
    void PWMSetup(); //Start function
    void PWMDutySet(float DutyProcent); //Set PWM duty as procent and start on PIN 9
    float PWMFreqency(); //Return PWM frequency

    private:
};




#endif