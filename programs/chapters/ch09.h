#include "crazyflie.h"
#include "mbed.h"
#include "mixer.h"

// Declare mixer
Mixer mixer;

// Main program
int main() {
  mixer.arm();
  // Actuate motor with total thrust force (N), tau phi, tau theta, tau psi torques
  mixer.actuate(0, 0, 0, -0.001);
  wait(5);
  // Turn off all motors
  mixer.disarm();
  // End of program
  while (true) {
  }
}
