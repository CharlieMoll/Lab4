// Description: This file implements functions that utilize the timers 3
            //  and 4 PWM.
//----------------------------------------------------------------------//

#include "pwm.h"


// Function to initialized Timer 3 to use PWM
void initPWMTimer3(){

    //Pin 5 - Output Compare Match Flag
    DDRE |= (1<< DDE3); // assigns pin 5 to output
    //configure the output module for waveform generation mode

    // set Fast PWM 10-bit mode, non-inverting
    TCCR3A |= (1 << COM3A1) | (1 << WGM31) | (1 << WGM30);
    TCCR3B |= (1 << WGM32) | (1 <<CS30);

    //set duty cycle by determining OCR3A
    //duty cycle = 25% = 0.25
    //duty cycle = Tpulse/Tperiod = OCR3A/0x3FF
    //OCR3A = 0.25 * 1023 = 255

    OCR3A = 255;
}


// Function to initialized Timer 4 to use PWM
void initPWMTimer4(){

    //Pin 6 - Output Compare Match Flag
    DDRH |= (1<< DDH3); // assigns pin 5 to output
    //configure the output module for waveform generation mode

    // set Fast PWM 10-bit mode, non-inverting
    TCCR4A |= (1 << COM4A1) | (1 << WGM41) | (1 << WGM40);
    TCCR4B |= (1 << WGM42) | (1 <<CS40);

    //set duty cycle by determining OCR4A
    //duty cycle = 25% = 0.25
    //duty cycle = Tpulse/Tperiod = OCR4A/0x3FF
    //OCR4A = 0.25 * 1023 = 255

    OCR4A = 255;
}

void changeDutyCycle(unsigned int result){
    // read in ADCL and ADCH as 10bit result
    // if 2.5 volts, then no PWM to motor
    if (result == (1023 * 0.5)) {
        OCR3A = 0;
        OCR4A = 0;
    }
    // if less than 2.5 volts, clockwise (Timer 3)    
    else if (result < (1023 * 0.5)) {
        OCR3A = result;
        OCR4A = 0;
    }
    // if more than 2.5 volts, counterclockwise (Timer 4)
    else if (result > (1023 * 0.5)) {
        OCR3A = 0;
        OCR4A = result;
    }
    // if 5 volts, max RPM counterclockwise
    else if (result == 1023) {
        OCR3A = 0;
        OCR4A = 1023;
    }
    // if 0 volts, max RPM clockwise
    else if (result == 0) {
        OCR3A = 1023;
        OCR4A = 0;
    }
}
