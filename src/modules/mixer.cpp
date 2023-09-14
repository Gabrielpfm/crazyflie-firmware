#include "mixer.h"

// Class constructor
Mixer ::Mixer()
    : motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4) {
  motor_1.period(1.0 / 500.0);
  motor_2.period(1.0 / 500.0);
  motor_3.period(1.0 / 500.0);
  motor_4.period(1.0 / 500.0);
  motor_1 = 0.0;
  motor_2 = 0.0;
  motor_3 = 0.0;
  motor_4 = 0.0;
}

// Função arm retorna armed = true
Mixer::arm() { armed = true; }
// Função arm retorna armed = false e desliga os motores
Mixer::disarm() {
  armed = false;
  actuate(0, 0, 0, 0);
}
// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer ::actuate(float f_t, float tau_phi, float tau_theta, float tau_psi) {
  if (armed) {
    mixer(f_t, tau_phi, tau_theta, tau_psi);
    motor_1 = control_motor(omega_1);
    motor_2 = control_motor(omega_2);
    motor_3 = control_motor(omega_3);
    motor_4 = control_motor(omega_4);
  }
}

// Convert total trust force (N) and torques (N.m) to angular velocities ( rad
// /s)
void Mixer ::mixer(float f_t, float tau_phi, float tau_theta, float tau_psi) {
  float w_ft = f_t / (4 * kl) - tau_phi / (4 * kl * l) +
               (-tau_theta / (4 * kl * l)) + (-tau_psi / (4 * kd));
  float w_tauphi = f_t / (4 * kl) + (-tau_phi / (4 * kl * l)) +
                   (tau_theta / (4 * kl * l)) + (tau_psi / (4 * kd));
  float w_tautheta = f_t / (4 * kl) + (tau_phi / (4 * kl * l)) +
                     (tau_theta / (4 * kl * l)) + (-tau_psi / (4 * kd));
  float w_taupsi = f_t / (4 * kl) + (tau_phi / (4 * kl * l)) +
                   (-tau_theta / (4 * kl * l)) + (tau_psi / (4 * kd));

  if (w_ft > 0) {
    omega_1 = sqrt(w_ft);
  } else {
    omega_1 = 0;
  }

  if (w_tauphi > 0) {
    omega_2 = sqrt(w_tauphi);
  } else {
    omega_2 = 0;
  }

  if (w_tautheta > 0) {
    omega_3 = sqrt(w_tautheta);
  } else {
    omega_3 = 0;
  }

  if (w_taupsi > 0) {
    omega_4 = sqrt(w_taupsi);
  } else {
    omega_4 = 0;
  }
}

// Convert desired angular velocity ( rad /s) to PWM signal (%)
float Mixer ::control_motor(float omega) {
  float PWM = a2 * pow(omega, 2) + a1 * omega;
  return PWM;
}