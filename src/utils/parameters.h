#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

// PWM Constantes
const float a1 = 5.117e-12;
const float a2 = 1.422e-7;

// Constante de Sustentação
const float kl = 4.0756e-8;  
//Constante de Arrasto
const float kd = 2.2390e-10;

//Delta T
const float dt = 0.002;

//Frequência de Corte rad/s (Grioscópio - 1/Acelerometro - 10)
const float wc = 1;
//Alpha (Fator de Suavização)
const float alpha = (wc*dt/(1+wc*dt));
#endif