// Humanoid 17 DOF + Serial using arrays
// November 2015 by Bob Davis
// Mapped as D2 is servo1 
// Mapped as D3 is servo2 
// Etc.

#include <Servo.h>
// Define our Servo's
Servo servo1; // Left Ankle
Servo servo2; // Left Knee
Servo servo3; // Left Hip F-B
Servo servo4; // Left Hip R-L
Servo servo5; // Right Ankle
Servo servo6; // Right Knee
Servo servo7; // Right Hip F-B
Servo servo8; // Right Hip R-L
Servo servo9; // Left Hand
Servo servo10; // Left Wrist
Servo servo11; // Left Elbow
Servo servo12; // Left Shoulder
Servo servo13; // Right Hand
Servo servo14; // Right Wrist
Servo servo15; // Right Elbow
Servo servo16; // Right Shoulder
Servo servo17; // Head
int twait=50; // Sets time delay between steps

int walkf[8][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 95, 100, 100, 100, 100,  95,  90,  90,  90,  90}, // Left Ankle
{ 90,  90,  85,  80,  75,  70,  75,  75,  75,  80}, // Knee
{ 90,  90,  85,  80,  75,  70,  75,  75,  75,  80}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  90,  90}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  90,  90}, // Right Ankle
{ 90,  90,  90,  85,  80,  75,  75,  75,  80,  85}, // Knee
{ 90,  90,  90,  85,  80,  75,  75,  75,  80,  85}, // Hip
{ 90,  95,  95,  96,  95,  95,  90,  90,  90,  90}, // Hip
};

int walkb[8][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 95, 100, 100, 100, 100,  95,  90,  90,  85,  85}, // Left Ankle
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Knee
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  90,  90}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  90,  90}, // Right Ankle
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Knee
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Hip
{ 95,  95,  95,  95,  95,  95,  90,  90,  90,  90}, // Hip
};

// Turning is a bit tricky because he has to drag his feet
int turnr[8][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 90,  90,  90,  90,  94,  98,  98,  98,  94,  90}, // Left Ankle
{ 90,  90,  85,  80,  75,  70,  70,  75,  80,  85}, // Knee
{ 90,  90,  85,  80,  75,  70,  70,  75,  80,  85}, // Hip
{ 90,  90,  85,  80,  75,  70,  70,  75,  80,  85}, // Hip
{ 90,  90,  90,  90,  90,  94,  94,  94,  94,  90}, // Rigt Ankle
{ 90,  90,  90,  90,  85,  80,  75,  75,  80,  85}, // Knee
{ 90,  90,  90,  90,  85,  80,  75,  75,  80,  85}, // Hip
{ 90,  90,  90,  90,  85,  80,  75,  75,  80,  85}, // Hip
};

int turnl[8][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 90,  90,  90,  90,  90,  90,  90,  90,  90,  90}, // Left Ankle
{ 90,  90,  95, 100, 105, 105, 105, 105, 100,  95}, // Knee
{ 90,  90,  95, 100, 105, 105, 105, 105, 100,  95}, // Hip
{ 90,  90,  95, 100, 105, 105, 105, 105, 100,  95}, // Hip
{ 90,  90,  90,  90,  90,  90,  90,  90,  90,  90}, // right Ankle
{ 90,  90,  95, 100, 105, 105, 105, 105, 100,  95}, // Knee
{ 90,  90,  95, 100, 105, 105, 105, 105, 100,  95}, // Hip
{ 90,  90,  95, 100, 105, 105, 105, 105, 100,  95}, // Hip
};

int clap[9][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 90,  90,  90,  80,  70,  60,  60,  70,  80,  90}, // Left hand
{ 90, 100, 110, 120, 120, 120, 120, 110, 100,  90}, // Left wrist
{ 90, 100, 110, 120, 120, 120, 120, 110, 100,  90}, // Left elbow
{140, 120,  90,  90,  90,  90,  90,  90, 120, 140}, // Left Shoulder
{ 90,  90,  90,  80,  70,  60,  60,  70,  80,  90}, // Right hand
{ 90,  80,  70,  60,  60,  60,  60,  70,  80,  90}, // Right Wrist
{ 90,  80,  70,  60,  60,  60,  60,  70,  80,  90}, // Right Elbow
{ 40,  60,  90,  90,  90,  90,  90,  90,  60,  40}, // Right Shoulder
{ 80,  60,  40,  40,  60,  80, 100, 120, 140, 120}, // Head
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
  servo15.attach(16); // servo on digital pin 12
  servo16.attach(17); // servo on digital pin 13
  servo17.attach(18); // servo on digital pin 13
  Serial.begin(9600);
  Serial.print("Ready");
}

void loop(){
  servo1.write(90); // Return to zero position
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
  servo12.write(160);// 160=Left Shoulder down 
  servo13.write(90); 
  servo14.write(90); 
  servo15.write(90); 
  servo16.write(20); // 20=Right Shoulder down
  servo17.write(90); // Head 

  if ( Serial.available()) {
    char sinch = Serial.read();
    // Test out the servos 2 at a time
    switch(sinch) {
      case '1':
        servo1.write(50); //1 Key
        servo5.write(50); 
        delay(twait*2);
        servo1.write(130); 
        servo5.write(130); 
        delay(twait*2);
        break;
      case '2':
        servo2.write(50); //2 Key
        servo6.write(50); 
        delay(twait*2);
        servo2.write(130); 
        servo6.write(130); 
        delay(twait*2);
        break;
      case '3':
        servo3.write(50); //3 Key
        servo7.write(50); 
        delay(twait*2);
        servo3.write(130); 
        servo7.write(130); 
        delay(twait*2);
        break;
      case '4':
        servo4.write(50); //4 Key
        servo8.write(50); 
        delay(twait*2);
        servo4.write(130); 
        servo8.write(130); 
        delay(twait*2);
        break;
      case '5':
        servo9.write(50); //5 Key
        servo13.write(50); 
        delay(twait*2);
        servo9.write(130); 
        servo13.write(130); 
        delay(twait*2);
        break;
      case '6':
        servo10.write(50); //6 Key
        servo14.write(50); 
        delay(twait*2);
        servo10.write(130); 
        servo14.write(130); 
        delay(twait*2);
        break;
      case '7':
        servo11.write(50); //7 Key    
        servo15.write(50);     
        delay(twait*2);
        servo11.write(130); 
        servo15.write(130); 
        delay(twait*2);
        break;
      case '8':
        servo12.write(50); //8 Key    
        servo16.write(50);     
        delay(twait*2);
        servo12.write(130); 
        servo16.write(130); 
        delay(twait*2);
        break;
      case '9':
        servo17.write(50); //9 Key    
        delay(twait*2);
        servo17.write(130); 
        delay(twait*2);
        break;
      // Sequential operations 
      case 'c': // Clap hands
        servo2.write(80); // Lean back to counterbalance arms
        servo6.write(100); 
        for (int i=0; i<10; i++){
          servo9.write(clap[0][i]);  
          servo10.write(clap[1][i]);  
          servo11.write(clap[2][i]);  
          servo12.write(clap[3][i]);  
          servo13.write(clap[4][i]);  
          servo14.write(clap[5][i]); 
          servo15.write(clap[5][i]);  
          servo16.write(clap[6][i]); 
          servo17.write(clap[6][i]); 
          delay(twait*2);
        }
        break;        
      case 'r': // right key;
        for (int i=0; i<10; i++){
          servo1.write(turnr[0][i]);  
          servo2.write(turnr[1][i]);  
          servo3.write(turnr[2][i]);  
          servo4.write(turnr[3][i]);  
          servo5.write(turnr[4][i]);  
          servo6.write(turnr[5][i]); 
          servo7.write(turnr[5][i]);  
          servo8.write(turnr[6][i]); 
          delay(twait);
        }
        break;        
      case 'b':  // back key
        for (int i=0; i<10; i++){
          servo1.write(walkb[0][i]);  
          servo2.write(walkb[1][i]);  
          servo3.write(walkb[2][i]);  
          servo4.write(walkb[3][i]);  
          servo5.write(walkb[4][i]);  
          servo6.write(walkb[5][i]); 
          servo7.write(walkb[6][i]);  
          servo8.write(walkb[7][i]); 
          delay(twait);
        }
        break;        
      case 'l': // left key;
        for (int i=0; i<10; i++){
          servo1.write(turnl[0][i]);  
          servo2.write(turnl[1][i]);  
          servo3.write(turnl[2][i]);  
          servo4.write(turnl[3][i]);  
          servo5.write(turnl[4][i]);  
          servo6.write(turnl[5][i]); 
          servo7.write(turnl[6][i]);  
          servo8.write(turnl[7][i]); 
          delay(twait);
        }
        break;        
      case 'f': // forward key
        for (int i=0; i<10; i++){
          servo1.write(walkf[0][i]);  
          servo2.write(walkf[1][i]);  
          servo3.write(walkf[2][i]);  
          servo4.write(walkf[3][i]);  
          servo5.write(walkf[4][i]);  
          servo6.write(walkf[5][i]); 
          servo7.write(walkf[6][i]);  
          servo8.write(walkf[7][i]); 
          delay(twait);
        }
        break;        
    }
  }
}  // End of program
