// Spider 18 DOF version 2
// November 2015 by Bob Davis
// Mapped as D2 is servo1 
// Mapped as D3 is servo2 
// Etc.

#include <Servo.h>
// Define our Servo's
Servo servo1; // LF Lower Leg
Servo servo2; // LF Middle Leg
Servo servo3; // LF hip
Servo servo4; // LM Lower leg
Servo servo5; // LM Middle Leg
Servo servo6; // LM Hip
Servo servo7; // LR Lower Leg
Servo servo8; // LR Middle Leg
Servo servo9; // LR hip
Servo servo10; // RR Lower leg
Servo servo11; // RR Middle leg
Servo servo12; // RR hip
Servo servo13; // RM Lower Leg
Servo servo14; // RM Middle leg
Servo servo15; // RM hip
Servo servo16; // RF Lower leg
Servo servo17; // RF Middle Leg
Servo servo18; // RF hip
int twait=100; // Sets time delay between steps

int walkf[18][8] = {
// 0  Leg1 Leg6 Leg2 Leg5 Leg3 Leg4  0
{130, 110, 130, 130, 130, 130, 130, 130}, 
{130, 150, 130, 130, 130, 130, 130, 130}, 
{ 90, 120, 120, 120, 120, 120, 120,  90}, 
{130, 130, 130, 110, 130, 130, 130, 130}, 
{130, 130, 130, 150, 130, 130, 130, 130}, 
{ 90,  60,  60, 120, 120, 120, 120,  90}, 
{130, 130, 130, 130, 130, 110, 130, 130}, 
{130, 130, 130, 130, 130, 150, 130, 130}, 
{ 90,  60,  60,  60,  60, 120, 120,  90}, 
{ 50,  50,  50,  50,  50,  50,  70,  50}, 
{ 50,  50,  50,  50,  50,  50,  30,  50}, 
{ 90, 120, 120, 120, 120, 120,  60,  90}, 
{ 50,  50,  50,  50,  70,  50,  50,  50}, 
{ 50,  50,  50,  50,  30,  50,  50,  50}, 
{ 90, 120, 120, 120,  60,  60,  60,  90}, 
{ 50,  50,  70,  50,  50,  50,  50,  50}, 
{ 50,  50,  30,  50,  50,  50,  50,  50}, 
{ 90, 120,  60,  60,  60,  60,  60,  90}, 
};

int walkb[18][8] = {
// 0  Leg1 Leg6 Leg2 Leg5 Leg3 Leg4  0
{130, 110, 130, 130, 130, 130, 130, 130}, 
{130, 150, 130, 130, 130, 130, 130, 130}, 
{ 90,  60,  60,  60,  60,  60,  60,  90}, 
{130, 130, 130, 110, 130, 130, 130, 130}, 
{130, 130, 130, 150, 130, 130, 130, 130}, 
{ 90, 120, 120,  60,  60,  60,  60,  90}, 
{130, 130, 130, 130, 130, 110, 130, 130}, 
{130, 130, 130, 130, 130, 150, 130, 130}, 
{ 90, 120, 120, 120, 120,  60,  60,  90}, 
{ 50,  50,  50,  50,  50,  50,  70,  50}, 
{ 50,  50,  50,  50,  50,  50,  30,  50}, 
{ 90,  60,  60,  60,  60,  60, 120,  90}, 
{ 50,  50,  50,  50,  70,  50,  50,  50}, 
{ 50,  50,  50,  50,  30,  50,  50,  50}, 
{ 90,  60,  60,  60, 120, 120, 120,  90}, 
{ 50,  50,  70,  50,  50,  50,  50,  50}, 
{ 50,  50,  30,  50,  50,  50,  50,  50}, 
{ 90,  60, 120, 120, 120, 120, 120,  90}, 
};

int turnr[18][8] = {
// 0  Leg1 Leg6 Leg2 Leg5 Leg3 Leg4  0
{130, 110, 130, 130, 130, 130, 130, 130}, 
{130, 150, 130, 130, 130, 130, 130, 130}, 
{ 90, 120, 120, 120, 120, 120, 120,  90}, 
{130, 130, 130, 110, 130, 130, 130, 130}, 
{130, 130, 130, 150, 130, 130, 130, 130}, 
{ 90,  60,  60, 120, 120, 120, 120,  90}, 
{130, 130, 130, 130, 130, 110, 130, 130}, 
{130, 130, 130, 130, 130, 150, 130, 130}, 
{ 90,  60,  60,  60,  60, 120, 120,  90}, 
{ 50,  50,  50,  50,  50,  50,  70,  50}, 
{ 50,  50,  50,  50,  50,  50,  30,  50}, 
{ 90,  60,  60,  60,  60,  60, 120,  90}, 
{ 50,  50,  50,  50,  70,  50,  50,  50}, 
{ 50,  50,  50,  50,  30,  50,  50,  50}, 
{ 90,  60,  60,  60, 120, 120, 120,  90}, 
{ 50,  50,  70,  50,  50,  50,  50,  50}, 
{ 50,  50,  30,  50,  50,  50,  50,  50}, 
{ 90,  60, 120, 120, 120, 120, 120,  90}, 
};

int turnl[18][8] = {
// 0  Leg1 Leg6 Leg2 Leg5 Leg3 Leg4  0
{130, 110, 130, 130, 130, 130, 130, 130}, 
{130, 150, 130, 130, 130, 130, 130, 130}, 
{ 90,  60,  60,  60,  60,  60,  60,  90}, 
{130, 130, 130, 110, 130, 130, 130, 130}, 
{130, 130, 130, 150, 130, 130, 130, 130}, 
{ 90, 120, 120,  60,  60,  60,  60,  90}, 
{130, 130, 130, 130, 130, 110, 130, 130}, 
{130, 130, 130, 130, 130, 150, 130, 130}, 
{ 90, 120, 120, 120, 120,  60,  60,  90}, 
{ 50,  50,  50,  50,  50,  50,  70,  50}, 
{ 50,  50,  50,  50,  50,  50,  30,  50}, 
{ 90, 120, 120, 120, 120, 120,  60,  90}, 
{ 50,  50,  50,  50,  70,  50,  50,  50}, 
{ 50,  50,  50,  50,  30,  50,  50,  50}, 
{ 90, 120, 120, 120,  60,  60,  60,  90}, 
{ 50,  50,  70,  50,  50,  50,  50,  50}, 
{ 50,  50,  30,  50,  50,  50,  50,  50}, 
{ 90, 120,  60,  60,  60,  60,  60,  90}, 
};

void setup() { 
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
  servo13.attach(14); // servo on digital pin 14-A0
  servo14.attach(15); // servo on digital pin 15-A1
  servo15.attach(16); // servo on digital pin 16-A2
  servo16.attach(17); // servo on digital pin 17-A3
  servo17.attach(18); // servo on digital pin 18-A4
  servo18.attach(19); // servo on digital pin 19-A5 
  Serial.begin(9600);
  Serial.print("Ready");
}

void loop(){
  if ( Serial.available()) {
    char sinch = Serial.read();
    // Test out the servos 6 at a time
    switch(sinch) {
      case 'u': // rise up to 90 degrees
        servo1.write(90); servo2.write(90); servo3.write(90);
        servo4.write(90); servo5.write(90); servo6.write(90); 
        servo7.write(90); servo8.write(90); servo9.write(90);
        servo10.write(90); servo11.write(90); servo12.write(90); 
        servo13.write(90); servo14.write(90); servo15.write(90);
        servo16.write(90); servo17.write(90); servo18.write(90);
        break;
      case 'd': // Return to down position
        servo1.write(130); servo2.write(130); servo3.write(90); 
        servo4.write(130); servo5.write(130); servo6.write(90); 
        servo7.write(130); servo8.write(130); servo9.write(90);  
        servo10.write(50); servo11.write(50); servo12.write(90); 
        servo13.write(50); servo14.write(50); servo15.write(90); 
        servo16.write(50); servo17.write(50); servo18.write(90);
        break;
      case '1': //1 Key - Ankles
        servo1.write(60); servo4.write(60); servo7.write(60); 
        servo10.write(120); servo13.write(120); servo16.write(120); 
        delay(twait*4);
        servo1.write(120); servo4.write(120); servo7.write(120); 
        servo10.write(60); servo13.write(60); servo16.write(60); 
        delay(twait*4);
        break;
      case '2': //2 Key - Knees
        servo2.write(70); servo5.write(70); servo8.write(70); 
        servo11.write(110); servo14.write(110); servo17.write(110); 
        delay(twait*4);
        servo2.write(110); servo5.write(110); servo8.write(110); 
        servo11.write(70); servo14.write(70); servo17.write(70); 
         delay(twait*4);
        break;
      case '3': //3 Key - Hips
        servo3.write(60); servo6.write(60); servo9.write(60); 
        servo12.write(120); servo15.write(120); servo18.write(120); 
        delay(twait*4);
        servo3.write(120); servo6.write(120); servo9.write(120); 
        servo12.write(60); servo15.write(60); servo18.write(60); 
        delay(twait*4);
        break;
      // Sequential operations 
      case 'f': // forward key
        for (int i=0; i<8; i++){
          servo1.write(walkf[0][i]);  
          servo2.write(walkf[1][i]);  
          servo3.write(walkf[2][i]);  
          servo4.write(walkf[3][i]);  
          servo5.write(walkf[4][i]);  
          servo6.write(walkf[5][i]); 
          servo7.write(walkf[6][i]);  
          servo8.write(walkf[7][i]); 
          servo9.write(walkf[8][i]);  
          servo10.write(walkf[9][i]); 
          servo11.write(walkf[10][i]);  
          servo12.write(walkf[11][i]); 
          servo13.write(walkf[12][i]);  
          servo14.write(walkf[13][i]); 
          servo15.write(walkf[14][i]);  
          servo16.write(walkf[15][i]); 
          servo17.write(walkf[16][i]);  
          servo18.write(walkf[17][i]); 
          delay(twait*2);
        }
        break;      
      case 'b':  // back key 
        for (int i=0; i<8; i++){
          servo1.write(walkb[0][i]);  
          servo2.write(walkb[1][i]);  
          servo3.write(walkb[2][i]);  
          servo4.write(walkb[3][i]);  
          servo5.write(walkb[4][i]);  
          servo6.write(walkb[5][i]); 
          servo7.write(walkb[6][i]);  
          servo8.write(walkb[7][i]); 
          servo9.write(walkb[8][i]);  
          servo10.write(walkb[9][i]); 
          servo11.write(walkb[10][i]);  
          servo12.write(walkb[11][i]); 
          servo13.write(walkb[12][i]); 
          servo14.write(walkb[13][i]);  
          servo15.write(walkb[14][i]); 
          servo16.write(walkb[15][i]); 
          servo17.write(walkb[16][i]);  
          servo18.write(walkb[17][i]); 
          delay(twait*2);
        }
        break;        
      case 'l': // left key;
        for (int i=0; i<8; i++){
          servo1.write(turnl[0][i]);  
          servo2.write(turnl[1][i]);  
          servo3.write(turnl[2][i]);  
          servo4.write(turnl[3][i]);  
          servo5.write(turnl[4][i]);  
          servo6.write(turnl[5][i]); 
          servo7.write(turnl[6][i]);  
          servo8.write(turnl[7][i]); 
          servo9.write(turnl[8][i]);  
          servo10.write(turnl[9][i]); 
          servo11.write(turnl[10][i]);  
          servo12.write(turnl[11][i]); 
          servo13.write(turnl[12][i]); 
          servo14.write(turnl[13][i]);  
          servo15.write(turnl[14][i]); 
          servo16.write(turnl[15][i]); 
          servo17.write(turnl[16][i]);  
          servo18.write(turnl[17][i]); 
          delay(twait*2);
        }
        break;        
      case 'r': // right key;
        for (int i=0; i<8; i++){
          servo1.write(turnr[0][i]);  
          servo2.write(turnr[1][i]);  
          servo3.write(turnr[2][i]);  
          servo4.write(turnr[3][i]);  
          servo5.write(turnr[4][i]);  
          servo6.write(turnr[5][i]); 
          servo7.write(turnr[6][i]);  
          servo8.write(turnr[7][i]); 
          servo9.write(turnr[8][i]);  
          servo10.write(turnr[9][i]); 
          servo11.write(turnr[10][i]);  
          servo12.write(turnr[11][i]); 
          servo13.write(turnr[12][i]); 
          servo14.write(turnr[13][i]);  
          servo15.write(turnr[14][i]); 
          servo16.write(turnr[15][i]); 
          servo17.write(turnr[16][i]);  
          servo18.write(turnr[17][i]); 
          delay(twait*2);
        }
        break;        
    }
  }
}  // End of program
