#include "mbed.h"
#include "crazyflie.h"



PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);
// Converts desired angular velocity ( rad/s) to PWM signal (%)
float control_motor(float omega) {
  float PWM = a2 * pow(omega, 2) + a1 * omega;
  return PWM;
}

// Main program
int main() {
  // Set PWM frequency to 500 Hz
  motor1.period(1.0 / 500.0);
  // Turn on motor with X rad /s for 0.5s
  motor1 = control_motor(1000.0);

  // Set PWM frequency to 500 Hz
  motor2.period(1.0 / 500.0);
  // Turn on motor with X rad /s for 0.5s
  motor2 = control_motor(2000.0);

  // Set PWM frequency to 500 Hz
  motor3.period(1.0 / 500.0);
  // Turn on motor with X rad /s for 0.5s
  motor3 = control_motor(1000.0);

  // Set PWM frequency to 500 Hz
  motor4.period(1.0 / 500.0);
  // Turn on motor with X rad /s for 0.5s
  motor4 = control_motor(2000.0);
  wait(2);
  motor1 = 0;
  motor2 = 0;
  motor3 = 0;
  motor4 = 0;

  // End of program
  while (true) {
  }
}