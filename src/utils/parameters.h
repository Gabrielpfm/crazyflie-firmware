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
//const float kl = 4.0756e-8;  
const float kl = 1.7e-8;
//Constante de Arrasto
//const float kd = 2.2390e-10;
const float kd = 1.4e-10;

//Delta T
const float dt = 0.002;

//Frequência de Corte rad/s (Grioscópio - 1/Acelerometro - 10)
const float wc = 1.0;
//Alpha (Fator de Suavização)
const float alpha = (wc*dt/(1.0+wc*dt));

//Ganhos controlador de atitude
const float Ts_phi = 0.3;
const float OS_phi = 0.5/100.0;
const float zeta_phi = abs(log(OS_phi))/sqrt(pow(log(OS_phi),2)+pow(pi,2));
const float wn_phi = 4.0/(zeta_phi*Ts_phi);
const float kd_phi = 2.0*zeta_phi*wn_phi ;
const float kp_phi = pow(wn_phi,2);


const float Ts_psi = 0.6;
const float OS_psi = 0.5/100.0;
const float zeta_psi = abs(log(OS_psi))/sqrt(pow(log(OS_psi),2)+pow(pi,2));
const float wn_psi = 4.0/(zeta_psi*Ts_psi);
const float kd_psi = 2.0*zeta_psi*wn_psi ;
const float kp_psi = pow(wn_psi,2);


//Freqência Range
const float dt_range = 0.05;

//Fator de amortecimento 
const float zeta = sqrt(2)/2;

//Ganhos Vertical Estimator
const float wc_ver = 10.0;
const float l1 = pow(wc_ver,2);
const float l2 = 2*zeta*wc_ver;

//Ganhos controlador vertical 
const float Ts_ver = 2.0;
const float OS_ver = 0.5/100.0;
const float zeta_ver = abs(log(OS_ver))/sqrt(pow(log(OS_ver),2)+pow(pi,2));
const float wn_ver = 4.0/(zeta_ver*Ts_ver);
const float kd_ver = 2.0*zeta_ver*wn_ver ;
const float kp_ver = pow(wn_ver,2);

//Parâmetros Sensor Fluxo Óptico
const float gama = 42.0*pi/180.0;//Graus
const float W = 420.0; //Pixels
const float sigma = 2.0 * tan(gama/2.0)/(W*dt);
const float l_h = 50.0;

//Ganhos controlador horizontal
const float Ts_hor = 2.0;
const float OS_hor = 0.5/100.0;
const float zeta_hor = abs(log(OS_hor))/sqrt(pow(log(OS_hor),2)+pow(pi,2));
const float wn_hor = 4.0/(zeta_hor*Ts_hor);
const float kd_hor = 2.0*zeta_hor*wn_hor ;
const float kp_hor = pow(wn_hor,2);



#endif