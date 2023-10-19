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
}

// Initialize class
void AttitudeEstimator ::init() {
    imu.init();
    for (int i=0; i<500;i++)
    {
        imu.read();
        pbias = (1/500)*

        wait(dt);
    }
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator ::estimate() {
    imu.read();
    p = imu.gx;
    float phi_g = phi + p*dt;
    phi = phi_g;
    //float phi_a = atan2(-imu.ay,-imu.az);
    //phi = (1-alpha)*phi+alpha*phi_a;
}
