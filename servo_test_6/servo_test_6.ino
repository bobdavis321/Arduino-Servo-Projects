// Arduino 6 Servo Test sketch
// Sequences 6 servos from 10 to 180 degrees

#include <Servo.h>
Servo servo1; // Define our Servo
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

void setup()
{
   servo1.attach(8); // servo on digital pin 8
   servo2.attach(9); // servo on digital pin 9
   servo3.attach(10); // servo on digital pin 10
   servo4.attach(11); // servo on digital pin 11
   servo5.attach(12); // servo on digital pin 12
   servo6.attach(13); // servo on digital pin 13
}

void loop()
{
   servo1.write(10);  // Turn Servo Left to 0 degrees
   delay(500);        // Wait 1 second
   servo2.write(10);  // Turn Servo Left to 45 degrees
   delay(500);        // Wait 1 second
   servo3.write(10);  // Turn Servo back to 90 degrees
   delay(500);        // Wait 1 second
   servo4.write(10);  // Turn Servo Right to 135 degrees
   delay(500);        // Wait 1 second
   servo5.write(10);  // Turn Servo Right to 180 degrees
   delay(500);        // Wait 1 second
   servo6.write(10);  // Turn Servo Left to 0 degrees
   delay(500);        // Wait 1 second
   servo1.write(90);  // Turn Servo Left to 45 degrees
   delay(500);        // Wait 1 second
   servo2.write(90);  // Turn Servo back to 90 degrees
   delay(500);        // Wait 1 second
   servo3.write(90);  // Turn Servo Right to 135 degrees
   delay(500);        // Wait 1 second
   servo4.write(90);  // Turn Servo Right to 180 degrees
   delay(500);        // Wait 1 second
   servo5.write(90);  // Turn Servo Left to 0 degrees
   delay(500);        // Wait 1 second
   servo6.write(90);  // Turn Servo Left to 45 degrees
   delay(500);        // Wait 1 second
   servo1.write(180); // Turn Servo back to 90 degrees
   delay(500);        // Wait 1 second
   servo2.write(180); // Turn Servo Right to 135 degrees
   delay(500);        // Wait 1 second
   servo3.write(180); // Turn Servo Right to 180 degrees
   delay(500);        // Wait 1 second
   servo4.write(180); // Turn Servo Right to 180 degrees
   delay(500);        // Wait 1 second
   servo5.write(180); // Turn Servo Left to 0 degrees
   delay(500);        // Wait 1 second
   servo6.write(180); // Turn Servo Left to 45 degrees
   delay(500);        // Wait 1 second
}
