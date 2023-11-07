#ifndef mixer_h
#define mixer_h

#include "crazyflie.h"
#include "mbed.h"

// Mixer class
class Mixer {
public:
  // Class constructor
  Mixer();
  // Actuate motors with desired total trust force (N) and torques (N.m)
  void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi);
  void arm();
  void disarm();
  
private:
  // Motors PWM outputs
  PwmOut motor_1, motor_2, motor_3, motor_4;
  // Led Outputs
  DigitalOut LED_R_R, LED_R_L, LED_G_R, LED_G_L, LED_B_L;
  // Angular velocities ( rad /s)
  float omega_1, omega_2, omega_3, omega_4;
  // Convert total thrust force (N) and torques (N.m) to angular velocities (rad
  // /s)
  void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi);
  // Convert desired angular velocity ( rad/s) to PWM signal (%)
  float control_motor(float omega);
  bool armed;
};

#endif