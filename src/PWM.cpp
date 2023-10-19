#include <PWM.h>

#define TOP_VALUE 0X07FF;
#define PRESCALE 1;
constexpr float PWM_FREQUENCY = 60e3; //PWM 8~ kHz
constexpr uint16_t PERIOD = round(F_CPU / PWM_FREQUENCY); 


PWM::PWM()
{
    DDRB = B00000000;
    DDRB = B00000000;
}

PWM::~PWM()
{
    DDRB = B00000000;
    DDRB = B00000000;
}

void PWM::PWMSetup()
{
DDRB  |= _BV(PB1);    // set pin as output
    TCCR1B = 0;           // stop timer
    TCCR1A = _BV(COM1A1)  // non-inverting PWN on OC1A
           | _BV(WGM11);  // mode 14: fast PWM, TOP = ICR1
    TCCR1B = _BV(WGM12)   
           | _BV(WGM13)   
           | _BV(CS10);   
    ICR1   = PERIOD - 1;  // period
    OCR1A  = PERIOD / 1.1;  // duty cycle
}

void PWM::PWMDutySet(float DutyProcent)
{
    float Scale = DutyProcent/100; //Float procent scaling
    OCR1A = ICR1*Scale;

    //Port 9 
    DDRB = B00000010;
}

float PWM::PWMFreqency()
{
    float CpuFreq = 16000;
    uint16_t TOP = TOP_VALUE;
    uint8_t N = PRESCALE;
    float Frq = CpuFreq/(N*(1+TOP)); //Atmel 328p formula for PWM freqency(KHz)
    return Frq; 
}

