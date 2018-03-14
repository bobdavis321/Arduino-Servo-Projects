// Piped Dinosaur 17 DOF Ver 3 w Serial using arrays
// November 2015 by Bob Davis
// Mapped as D2 is servo1 
// Mapped as D3 is servo2 
// Etc.
// Available Commands:
// 0=zero servos, 1 = ankles, 2=knees, 3=hips
// f=forward, b=back, r=right, l=left
// s=sit, d=down, u=up
// if no command wiggles tail and mouth

#include <Servo.h>
// Define our Servo's
Servo servo1; // Left Ankle tilt 
Servo servo2; // Left Ankle
Servo servo3; // Left Knee
Servo servo4; // Left Hip
Servo servo5; // Right Ankle tilt
Servo servo6; // Right Ankle
Servo servo7; // Right Knee
Servo servo8; // Right hip
Servo servo9; // Left Hand
Servo servo10; // Left elbow
Servo servo11; // Left shoulder
Servo servo12; // Right Hand
Servo servo13; // Right elbow
Servo servo14; // Right shoulder
Servo servo15; // Head
Servo servo16; // Mouth
Servo servo17; // Tail
Servo servo18; // Tail
int twait=100; // Sets time delay between steps

int walkf[10][12] = {
// 0   1   2   3   4   5   6   7   8   9  10  11
{ 90, 90,100,100,110,100,100, 90, 90, 90, 90, 90}, // L Ankle
{ 90, 90, 80, 70, 60, 70, 80, 90, 90, 90, 90, 90}, // L ankle
{ 90, 90, 80, 70, 60, 70, 80, 80, 80, 80, 90, 90}, // L Knee
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 80, 70, 90}, // L Hip
{ 90, 90, 90, 90, 90, 90, 90, 90, 90,100,110, 90}, // R ankle
{ 90, 90, 80, 80, 80, 80, 80, 80, 80,100,110, 90}, // R ankle
{ 90, 90, 90, 90, 90, 90,100,110,120,120,110, 90}, // R knee
{ 90, 90, 90, 90, 90, 90, 80, 70, 60, 70, 80, 90}, // R hip
{100,100,100,100, 90, 90, 80, 80, 80, 80, 90, 90}, // Tail 1
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // Tail 2
};

int walkb[10][12] = {
// 0   1   2   3   4   5   6   7   8   9  10  11
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 80, 70, 90}, // L R ankle
{ 90, 90, 90, 90, 90, 90, 90, 90, 90,100,100, 90}, // Knee
{ 90, 80, 80, 80, 80, 80, 80, 80, 80,100,100, 90}, // hip
{ 90, 90,100,110,120,110,100, 90, 90, 90, 90, 90}, // R R Ankle
{ 90, 90, 80, 70, 60, 70, 80, 90, 90, 90, 90, 90}, // Knee
{ 90, 90, 80, 70, 60, 70, 80, 80, 90, 90, 90, 90}, // Hip
{ 80, 70, 60, 60, 70, 80, 90, 90, 90, 90, 90, 90}, // L F ankle
{100,110,120,110,100, 90, 90, 90, 90, 90, 90, 90}, // Knee
{100,110,120,110,100, 90, 90, 90, 90, 90, 90, 90}, // Hip
{ 90, 90, 90, 90, 90, 90,100,110,120,120,110, 90}, // R F ankle
};

// Turning is a bit tricky as he digs in his feet
int turnr[12][12] = {
// 0   1   2   3   4   5   6   7   8   9  10  11
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // L R Ankle
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // Knee
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // Hip
{ 90, 90, 90, 95, 95, 95, 95, 95, 90, 90, 90, 90}, // R R ankle
{ 90, 90, 90, 95, 95, 95, 95, 95, 90, 90, 90, 90}, // Knee
{ 90, 90, 90, 95, 95, 95, 95, 95, 90, 90, 90, 90}, // hip
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // L F ankle
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // Knee
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // hip
{ 90, 90, 90, 90,100,110,110,125,110,100, 90, 90}, // R F ankle
{ 90, 90, 90, 90,100,110,110,110, 90, 90, 90, 90}, // Knee
{ 90, 90, 90, 90,100,100,110,100, 90, 90, 90, 90}, // Hip
};

int turnl[12][12] = {
// 0   1   2   3   4   5   6   7   8   9  10  11
{ 90, 90, 90, 80, 80, 80, 80, 80, 90, 90, 90, 90}, // L R Ankle
{ 90, 90, 90, 80, 80, 80, 80, 80, 90, 90, 90, 90}, // Knee
{ 90, 90, 90, 80, 80, 80, 80, 80, 80, 90, 90, 90}, // Hip
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // R R ankle
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // Knee
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // hip
{ 90, 90, 90, 90, 80, 70, 70, 65, 70, 80, 90, 90}, // L F ankle
{ 90, 90, 90, 90, 80, 70, 70, 70, 90, 90, 90, 90}, // Knee
{ 90, 90, 90, 90, 90, 80, 70, 80, 90, 90, 90, 90}, // hip
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // R F ankle
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // Knee
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // Hip
};

int sit[14][12] = {  //now sit
// 0   1   2   3   4   5   6   7   8   9  10  11
{ 95,100,105,110,115,120,125,120,115,110,105,100}, // L R ankle
{ 80, 70, 60, 50, 40, 30, 20, 30, 40, 50, 60, 80}, // Knee
{ 85, 80, 75, 70, 65, 60, 55, 60, 65, 70, 75, 80}, // Hip
{ 85, 80, 75, 70, 65, 60, 55, 60, 65, 70, 75, 80}, // R R Ankle
{100,110,120,130,140,150,160,150,140,130,120,100}, // Knee
{ 95,100,105,110,115,120,125,120,115,110,105,100}, // hip
{ 90, 80, 70, 60, 50, 30, 10, 30, 50, 60, 70, 80}, // L F ankle
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // Knee
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // hip
{ 90,100,110,120,130,150,170,150,130,120,110,100}, // R F ankle
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // Knee
{ 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90}, // Hip
{ 90, 90, 90, 90, 90, 60, 60, 60, 90, 90, 90, 90}, // head
{ 90,110,130,150,170,170,170,150,120,110,100, 90}, // Tail
};

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
  servo13.attach(14); // servo on digital pin 10
  servo14.attach(15); // servo on digital pin 11
  servo15.attach(16); // servo on digital pin 11
  servo16.attach(17); // servo on digital pin 11
  servo17.attach(18); // servo on digital pin 11
  Serial.begin(9600);
  Serial.print("Ready");
}

void loop(){
  servo1.write(90); // Return to zero position
  servo2.write(90);  
  servo3.write(170); // knee straight is 180
  servo4.write(90); 
  servo5.write(90); 
  servo6.write(90); 
  servo7.write(10); // knee straight is 0
  servo8.write(90); 
  servo9.write(90);  
  servo10.write(90); 
  servo11.write(90);  
  servo12.write(90); 
  servo13.write(90); 
  servo14.write(90); 
  servo15.write(90); 
  servo16.write(90); 
  servo17.write(90); 
  if ( Serial.available()) {
    char sinch = Serial.read();
    switch(sinch) {
      case '0': // 0 key
      case 'u': // u key
        servo1.write(90); // Return to up position
        servo2.write(90);  
        servo3.write(170); 
        servo4.write(90); 
        servo5.write(90); 
        servo6.write(90); 
        servo7.write(10); 
        servo8.write(90); 
        servo9.write(90);  
        servo10.write(90); 
        servo11.write(90);  
        servo12.write(90); 
        servo13.write(90); 
        servo14.write(90); 
        servo15.write(90); 
        servo16.write(90); 
        servo17.write(90); 
        delay(twait*2);
        break;
      // Test out the servos 4 at a time
      case '1': //1 Key - Ankles
        servo1.write(50); 
        servo4.write(50); 
        servo7.write(50); 
        servo10.write(50); 
        delay(twait*2);
        servo1.write(130); 
        servo4.write(130); 
        servo7.write(130); 
        servo10.write(130); 
        delay(twait*2);
        break;
      case '2': //2 Key - Knees
        servo2.write(50); 
        servo5.write(50); 
        servo8.write(50); 
        servo11.write(50); 
        delay(twait*2);
        servo2.write(130); 
        servo5.write(130); 
        servo8.write(130); 
        servo11.write(130); 
        delay(twait*2);
        break;
      case '3': //3 Key - Hips
        servo3.write(50); 
        servo6.write(50); 
        servo9.write(50); 
        servo12.write(50); 
        delay(twait*2);
        servo3.write(130); 
        servo6.write(130); 
        servo9.write(130); 
        servo12.write(130); 
        delay(twait*2);
        break;
      case '4': //4 Key - Head
        servo13.write(50); 
        delay(twait*2);
        servo13.write(130); 
        delay(twait*2);
        break;
      case '5': //5 Key - Tail
      case 't': //t Key - Tail
        servo14.write(60); 
        servo15.write(120); 
        servo16.write(60); 
        servo17.write(120); 
        delay(twait*4); // leave time for tail to move.
        servo14.write(120); 
        servo15.write(60); 
        servo16.write(120); 
        servo17.write(60); 
        delay(twait*4);
        break;
      // Sequential operations 
      case 'd': //d = squat down
        for (int s=0; s<120; s++){
          servo1.write(90);  
          servo2.write(90-.5*s);  
          servo3.write(170-s); // 170 is up
          servo4.write(90+.5*s);  
          servo5.write(90);  
          servo6.write(90+.5*s); 
          servo7.write(10+s);// 10 is up  
          servo8.write(90-.5*s);
          delay(twait/2);
          }
          delay(twait*10);
        for (int s=0; s<120; s++){
          servo1.write(90);  
          servo2.write(30+.5*s);  
          servo3.write(50+s); // 170 is up
          servo4.write(150-.5*s);  
          servo5.write(90);  
          servo6.write(150-.5*s); 
          servo7.write(130-s);// 10 is up  
          servo8.write(30+.5*s);
          delay(twait/2);
          }
          delay(twait*10);
        break;
      case 's': // Sit - Sit and shake head 
        for (int i=0; i<12; i++){
          servo1.write(sit[0][i]);  
          servo2.write(sit[1][i]);  
          servo3.write(sit[2][i]);  
          servo4.write(sit[3][i]);  
          servo5.write(sit[4][i]);  
          servo6.write(sit[5][i]); 
          servo7.write(sit[6][i]);  
          servo8.write(sit[7][i]);  
          servo9.write(sit[8][i]); 
          servo10.write(sit[9][i]);  
          servo11.write(sit[10][i]);  
          servo12.write(sit[11][i]); 
          servo13.write(sit[12][i]);
// Wagging tail might tip him over, move tail instead!
          servo16.write(sit[13][i]); 
          delay(twait*2);
        }
        break;        
      case 'f': // forward key
        for (int i=0; i<12; i++){
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
          servo14.write(walkf[12][i]); 
          servo15.write(walkf[13][i]); 
          servo16.write(walkf[14][i]); 
          servo17.write(walkf[15][i]); 
          delay(twait);
        }
        break; 
      case 'b':  // back key
        for (int i=0; i<12; i++){
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
          servo14.write(walkb[12][i]); 
          servo15.write(walkb[13][i]); 
          servo16.write(walkb[14][i]); 
          servo17.write(walkb[15][i]); 
          delay(twait);
        }
        break;        
      case 'r': // right key;
        for (int i=0; i<12; i++){
          servo1.write(turnr[0][i]);  
          servo2.write(turnr[1][i]);  
          servo3.write(turnr[2][i]);  
          servo4.write(turnr[3][i]);  
          servo5.write(turnr[4][i]);  
          servo6.write(turnr[5][i]); 
          servo7.write(turnr[5][i]);  
          servo8.write(turnr[6][i]); 
          servo9.write(turnr[8][i]);  
          servo10.write(turnr[9][i]); 
          servo11.write(turnr[10][i]);  
          servo12.write(turnr[11][i]); 
          delay(twait);
        }
        break;        
      case 'l': // left key;
        for (int i=0; i<12; i++){
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
          delay(twait);
        }
        break;        
    }}
  else{ // nothing to do so gently wiggle tail and mouth.
        servo13.write(85); 
        servo16.write(95); 
        servo17.write(95); 
        delay(twait*10);
        servo13.write(95); 
 //       servo14.write(85); 
 //       servo15.write(95); 
        servo16.write(85); 
        servo17.write(85); 
        delay(twait*10);
  }
}  // End of program
