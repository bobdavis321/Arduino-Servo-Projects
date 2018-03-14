// Arduino Servo Test sketch
// Rotates a servo through 45 degree increments

#include <Servo.h>
Servo servo1; // Define our Servo

void setup() {
   servo1.attach(8); // servo on digital pin 8
}

void loop() {
   servo1.write(0);   // Turn Servo Left to 0 degrees
   delay(1000);       // Wait 1 second
   servo1.write(45);  // Turn Servo Left to 45 degrees
   delay(1000);       // Wait 1 second
   servo1.write(90);  // Turn Servo back to 90 degrees
   delay(1000);       // Wait 1 second
   servo1.write(135); // Turn Servo Right to 135 degrees
   delay(1000);       // Wait 1 second
   servo1.write(180); // Turn Servo Right to 180 degrees
   delay(1000);       // Wait 1 second
}
