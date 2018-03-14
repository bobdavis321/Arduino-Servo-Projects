 // Arduino 12 Servo IR Test sketch
// Mapped as D2 is servo1 is the "1" key on IR remote
// Mapped as D3 is servo2 is the "2" key on IR remote
// Etc.

#include <Servo.h>
#include <IRremote.h>
int RECV_PIN=19;  // used pin 19 for IR input
IRrecv irrecv(RECV_PIN);
decode_results results;

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
   Serial.begin(9600); 
   irrecv.enableIRIn();
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
  if(irrecv.decode(&results)){
   if (results.value==16738455) servo1.write(40); //1 Key
   if (results.value==16750695) servo2.write(40); //2 Key
   if (results.value==16756815) servo3.write(40); //3 Key
   if (results.value==16724175) servo4.write(40); //4 Key
   if (results.value==16718055) servo5.write(40); //5 Key
   if (results.value==16743045) servo6.write(40); //6 Key
   if (results.value==16716015) servo7.write(40); //7 Key    
   if (results.value==16726215) servo8.write(40); //8 Key    
   if (results.value==16734885) servo9.write(40); //9 Key    
   if (results.value==16728765) servo10.write(40); //* Key
   if (results.value==16730805) servo11.write(40); //0 Key
   if (results.value==16732845) servo12.write(40); //# Key
   if (results.value==16712445) Serial.println("OK key");
   if (results.value==16736925) Serial.println("forward key");
   if (results.value==16761405) Serial.println("right key");
   if (results.value==16754775) Serial.println("back key");
   if (results.value==16720605) Serial.println("left key");
    
   delay(500);          // Wait 1 second
   servo1.write(90);   
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

   delay(500);          // Wait 1 second
   irrecv.resume(); // Receive the next value
  }
}
