#include "attitude_estimator.h"
#include <cmath>

// Class constructor
AttitudeEstimator ::AttitudeEstimator() : imu(IMU_SDA, IMU_SCL) {
  //Euler angles (rad)
  phi = 0;
  theta = 0;
  psi = 0;
  // Angular velocities ( rad /s)
  p = 0;
  q = 0;
  r = 0;
  //
    pbias = 0;
    qbias = 0;
    rbias = 0;
}

// Initialize class
void AttitudeEstimator ::init() {
    wait(1); 
    imu.init();
    for (int i=0; i<500;i++)
    {
        imu.read();
        pbias += imu.gx/500.0;
        qbias += imu.gy/500.0;
        rbias += imu.gz/500.0;
        wait(dt);
    }
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator ::estimate() {
    imu.read();
    p = imu.gx - pbias;
    q = imu.gy - qbias;
    r = imu.gz - rbias;
    //Phi
    float phi_a = atan2(-imu.ay,-imu.az);
    float theta_a = atan2(imu.ax,-((imu.az>0)-(imu.az<0))*(sqrt(pow(imu.ay,2)+pow(imu.az,2))));
    //
    float phi_g = phi + (p+sin(phi)*tan(theta)*q+cos(phi)*tan(theta)*r)*dt;
    float theta_g = theta + (cos(phi)*q-sin(phi)*r)*dt;
    float psi_g = psi + (sin(phi)/cos(theta)*q+cos(phi)/cos(theta)*r)*dt;
    //
    phi = (1-alpha)*phi_g + alpha*phi_a;
    theta = (1-alpha)*theta_g + alpha*theta_a;
    psi = psi_g;

}
