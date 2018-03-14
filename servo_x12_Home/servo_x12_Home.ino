// Arduino 12 Servo to a "home" of 90 degrees
// Used to set the zero position for all 12 servos
// Mapped as D2 is servo1 
// Mapped as D3 is servo2 
// Etc.

#include <Servo.h>

Servo servo1; // Define our Servo's
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;
Servo servo11;
Servo servo12;

void setup(){
   servo1.attach(2); // servo on digital pin 2
   servo2.attach(3); // servo on digital pin 3
   servo3.attach(4); // servo on digital pin 4
   servo4.attach(5); // servo on digital pin 5
   servo5.attach(6); // servo on digital pin 6
   servo6.attach(7); // servo on digital pin 7
   servo7.attach(8); // servo on digital pin 8
   servo8.attach(9); // servo on digital pin 9
   servo9.attach(10); // servo on digital pin 10
   servo10.attach(11); // servo on digital pin 11
   servo11.attach(12); // servo on digital pin 12
   servo12.attach(13); // servo on digital pin 13
}

void loop(){
   servo1.write(90);   // trim to level
   servo2.write(90);  
   servo3.write(90); 
   servo4.write(90); 
   servo5.write(90); 
   servo6.write(90); 
   servo7.write(90); 
   servo8.write(90); 
   servo9.write(90); 
   servo10.write(90); 
   servo11.write(90); 
   servo12.write(90); 
   delay(1000);          // Wait 1 second
}
