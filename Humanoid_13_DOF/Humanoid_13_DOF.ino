// Humanoid 13 DOF + IR using arrays
// September 2015 by Bob Davis
// Mapped as D2 is servo1 is the "1" key on IR remote
// Mapped as D3 is servo2 is the "2" key on IR remote
// Etc.
// Servos did not work when attached to the analog pins.

#include <Servo.h>
#include <IRremote.h>
int RECV_PIN=19; // use pin 19 or A5 for IR input
IRrecv irrecv(RECV_PIN);
decode_results results;

// Define our Servo's
Servo servo1; // Left Ankle
Servo servo2; // Left Knee
Servo servo3; // Left Hip
Servo servo4; // Right Ankle
Servo servo5; // Right Knee
Servo servo6; // Right Hip
Servo servo7; // Left Hand
Servo servo8; // Left Elbow
Servo servo9; // Left Shoulder
Servo servo10; // Right Hand
Servo servo11; // Right Elbow
Servo servo12; // Right Shoulder
//Servo servo13; // Head
int twait=100; // Sets time delay between steps

int walkf[6][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 95, 105, 110, 100, 100,  95,  90,  90,  90,  90}, // Left Ankle
{ 90,  90,  90,  85,  80,  75,  70,  70,  75,  80}, // Knee
{ 90,  90,  90,  85,  80,  75,  70,  70,  75,  80}, // Hip
{ 90,  95, 100, 100, 100,  95,  90,  90,  90,  90}, // Right Ankle
{ 90,  90,  90,  85,  80,  75,  70,  75,  80,  85}, // Knee
{ 90,  90,  90,  85,  80,  75,  70,  75,  80,  85}, // Hip
};

int walkb[6][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 95, 100, 110, 110, 100,  95,  90,  90,  85,  85}, // Left Ankle
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Knee
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  85,  85}, // Right Ankle
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Knee
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Hip
};

// Turning is a bit tricky because he has to drag his feet
int turnr[6][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 90,  90,  90,  90,  94,  98,  98,  98,  94,  90}, // Left Ankle
{ 90,  90,  85,  80,  75,  70,  70,  75,  80,  85}, // Knee
{ 90,  90,  85,  80,  75,  70,  70,  75,  80,  85}, // Hip
{ 90,  90,  90,  90,  90,  94,  94,  94,  94,  90}, // Rigt Ankle
{ 90,  90,  90,  90,  85,  80,  75,  75,  80,  85}, // Knee
{ 90,  90,  90,  90,  85,  80,  75,  75,  80,  85}, // Hip
};

int turnl[6][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 90,  90,  90,  90,  90,  90,  90,  90,  90,  90}, // Left Ankle
{ 90,  90,  95, 100, 105, 105, 105, 105, 100,  95}, // Knee
{ 90,  90,  95, 100, 105, 105, 105, 105, 100,  95}, // Hip
{ 90,  90,  90,  90,  90,  90,  90,  90,  90,  90}, // right Ankle
{ 90,  90,  95, 100, 105, 105, 105, 105, 100,  95}, // Knee
{ 90,  90,  95, 100, 105, 105, 105, 105, 100,  95}, // Hip
};
void setup(){
   irrecv.enableIRIn();
   pinMode(15, OUTPUT);
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
//   servo13.attach(0); // servo on digital pin 0
}

void loop(){
  servo1.write(90);   // Return to zero position
  servo2.write(90);  
  servo3.write(90); 
  servo4.write(90); 
  servo5.write(90); 
  servo6.write(90); 
  servo7.write(90); 
  servo8.write(90); 
  servo9.write(160); // Left Shoulder down 
  servo10.write(90); 
  servo11.write(90); 
  servo12.write(20); // Right Shoulder down
//  servo13.write(90); 
  if(irrecv.decode(&results)){
   // Test out the servos 
   if (results.value==16738455) {
     servo1.write(50); //1 Key
     delay(twait*2);
     servo1.write(130); 
     delay(twait*2);
   }
   if (results.value==16750695) {
     servo2.write(50); //2 Key
     delay(twait*2);
     servo2.write(130); 
     delay(twait*2);
   }
   if (results.value==16756815) {
     servo3.write(50); //3 Key
     delay(twait*2);
     servo3.write(130); 
     delay(twait*2);
   }
   if (results.value==16724175) {
     servo4.write(50); //4 Key
     delay(twait*2);
     servo4.write(130); 
     delay(twait*2);
   }
   if (results.value==16718055) {
     servo5.write(50); //5 Key
     delay(twait*2);
     servo5.write(130); 
     delay(twait*2);
   }
   if (results.value==16743045) {
     servo6.write(50); //6 Key
     delay(twait*2);
     servo6.write(130); 
     delay(twait*2);
   }
   if (results.value==16716015) {
     servo7.write(50); //7 Key    
     delay(twait*2);
     servo7.write(130); 
     delay(twait*2);
   }
   if (results.value==16726215) {
     servo8.write(50); //8 Key    
     delay(twait*2);
     servo8.write(130); 
     delay(twait*2);
   }
   if (results.value==16734885) {
     servo9.write(50); //9 Key    
     delay(twait*2);
     servo9.write(130); 
     delay(twait*2);
   }     
   if (results.value==16728765) {
     servo10.write(50); //* Key
     delay(twait*2);
     servo10.write(130); 
     delay(twait*2);
   }
   if (results.value==16730805) {
     servo11.write(50); //0 Key
     delay(twait*2);
     servo11.write(130); 
     delay(twait*2);
   }
   if (results.value==16732845) {
     servo12.write(50); //# Key
     delay(twait*2);
     servo12.write(130); 
     delay(twait*2);
   }
   // Sequential operations 
   if (results.value==16712445) {
     servo7.write(145); // OK key=Clap hands
     servo8.write(150); 
     servo9.write(90); 
     servo10.write(40); 
     servo11.write(35); 
     servo12.write(90); 
     // Servo 13 on A1 as pin D15
     digitalWrite(15, HIGH);
     // .5 Millisecond=0, 2.5 Ms=180 degrees
     delayMicroseconds(2500); 
     digitalWrite(15, LOW);
     delay(100); // minimum 20 Ms pause
     digitalWrite(15, HIGH);
     delayMicroseconds(500); 
     digitalWrite(15, LOW);
     delay(100); 

     delay(twait*2);
     
   }
   if (results.value==16761405) { // right key;
     for (int i=0; i<10; i++){
       servo1.write(turnr[0][i]);  
       servo2.write(turnr[1][i]);  
       servo3.write(turnr[2][i]);  
       servo4.write(turnr[3][i]);  
       servo5.write(turnr[4][i]);  
       servo6.write(turnr[5][i]); 
       delay(twait);
     }
   }

   if (results.value==16754775) {  // back key
     for (int i=0; i<10; i++){
       servo1.write(walkb[0][i]);  
       servo2.write(walkb[1][i]);  
       servo3.write(walkb[2][i]);  
       servo4.write(walkb[3][i]);  
       servo5.write(walkb[4][i]);  
       servo6.write(walkb[5][i]); 
       delay(twait);
     }
   }

   if (results.value==16720605){ // left key;
     for (int i=0; i<10; i++){
       servo1.write(turnl[0][i]);  
       servo2.write(turnl[1][i]);  
       servo3.write(turnl[2][i]);  
       servo4.write(turnl[3][i]);  
       servo5.write(turnl[4][i]);  
       servo6.write(turnl[5][i]); 
       delay(twait);
     }
   }

   if (results.value==16736925) {  // forward key
     for (int i=0; i<10; i++){
       servo1.write(walkf[0][i]);  
       servo2.write(walkf[1][i]);  
       servo3.write(walkf[2][i]);  
       servo4.write(walkf[3][i]);  
       servo5.write(walkf[4][i]);  
       servo6.write(walkf[5][i]); 
       delay(twait);
     }
   }
  
//   delay(100);         // Wait .1 second

   irrecv.resume(); // Receive the next value
  }
}  // End of program
