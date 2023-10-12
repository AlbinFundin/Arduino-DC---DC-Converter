#ifndef PWM_H
#define PWM_H

#include <Arduino.h>



class PWM {
    PWM();
    ~PWM();
    public:
    void PWMSetup();
    void PWMDutySetup(float DutyProcent); //Set PWM duty as procent 
    float PWMFreqency();

    private:
};




#endif