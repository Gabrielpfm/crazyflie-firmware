#include "mbed.h"
#include "crazyflie.h"

// Define motor as PWM output object
PwmOut motor ( MOTOR1 ) ;
// Converts desired angular velocity ( rad/s) to PWM signal (%)
float control_motor ( float omega )
{
float PWM = a2* pow(omega,2)+a1*omega;
return PWM;
}

// Main program
int main ()
{
    // Set PWM frequency to 500 Hz
    motor . period (1.0/500.0) ;
    // Turn on motor with 1.000 rad /s for 0.5s
    motor = control_motor (1000.0) ;
    wait (0.5) ;
    // Turn off motor
    motor = 0.0;
    // End of program
    while ( true )
    {
    }
}