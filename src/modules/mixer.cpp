#include "mixer.h"

// Class constructor
Mixer ::Mixer()
    : motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4),LED_R_R(LED_RED_R), LED_R_L(LED_RED_L), LED_G_R(LED_GREEN_R),
      LED_G_L(LED_GREEN_L), LED_B_L(LED_BLUE_L) {
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
void Mixer ::arm() {
  for (int contador = 0; contador < 3; contador = contador + 1) {
    LED_R_R = false;
    LED_R_L = false;
    wait(0.5);
    LED_R_R = true;
    LED_R_L = true;
    wait(0.5);
  }

  armed = true;
  LED_R_R = false; // Ligado = False
  LED_R_L = false;
  LED_G_L = true; // Desligado = True
  LED_G_R = true;
}
// Função arm retorna armed = false e desliga os motores
void Mixer ::disarm() {
  actuate(0, 0, 0, 0);
  armed = false;
  LED_R_R = true;
  LED_R_L = true;
  LED_G_L = false;
  LED_G_R = false;
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