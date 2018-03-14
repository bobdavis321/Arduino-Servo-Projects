// Humanoid 17 DOF Serial Version 2
// Jan 2016 by Bob Davis
// Mapped as D2 is servo1 
// Mapped as D3 is servo2 
// Etc.
// f=forward, b=back
// r=right l=left
// w=wave s=sit
// c=clap p=pick up

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
int twait=100; // Sets time delay between steps

int walkf[8][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 95, 105, 105, 105, 105,  95,  90,  90,  85,  85}, // Left Ankle
{ 90,  90,  90,  85,  80,  75,  70,  70,  75,  80}, // Knee
{ 90,  90,  90,  85,  80,  75,  70,  70,  75,  80}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  85,  90}, // Hip
{ 95, 105, 105, 105, 105,  95,  90,  90,  85,  90}, // Right Ankle
{ 90,  90,  90,  85,  80,  75,  70,  70,  75,  80}, // Knee
{ 90,  90,  90,  85,  80,  75,  70,  70,  75,  80}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  85,  90}, // Hip
};

int walkb[8][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 95, 105, 105, 105, 105,  95,  90,  90,  85,  85}, // Left Ankle
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Knee
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  85,  90}, // Hip
{ 95, 105, 105, 105, 105,  95,  90,  90,  85,  90}, // Right Ankle
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Knee
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  85,  90}, // Hip
};

// Turning is a bit tricky because he has to drag his feet
int turnr[8][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 95, 100, 100, 100, 100,  95,  90,  90,  90,  90}, // Left Ankle
{ 90,  90,  90,  85,  80,  75,  70,  70,  75,  80}, // Knee
{ 90,  90,  90,  85,  80,  75,  70,  70,  75,  80}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  90,  90}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  90,  90}, // Right Ankle
{ 90,  90,  90,  85,  80,  75,  70,  75,  80,  85}, // Knee
{ 90,  90,  90,  85,  80,  75,  70,  75,  80,  85}, // Hip
{ 95, 100, 100, 100, 100,  95,  90,  90,  90,  90}, // Hip
};

int turnl[8][10] = {
// 0    1    2    3    4    5    6    7    8    9
{ 85,  80,  80,  80,  80,  85,  90,  90,  90,  90}, // Left Ankle
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Knee
{ 90,  90,  90,  95, 100, 105, 110, 110, 105, 100}, // Hip
{ 85,  80,  80,  80,  80,  85,  90,  90,  90,  90}, // Hip
{ 85,  80,  80,  80,  80,  85,  90,  90,  90,  90}, // Right Ankle
{ 90,  90,  90,  95, 100, 105, 110, 105, 100,  95}, // Knee
{ 90,  90,  90,  95, 100, 105, 110, 105, 100,  95}, // Hip
{ 85,  80,  80,  80,  80,  85,  90,  90,  90,  90}, // Hip
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
  servo13.attach(14); // servo on digital pin 14
  servo14.attach(15); // servo on digital pin 15
  servo15.attach(16); // servo on digital pin 16
  servo16.attach(17); // servo on digital pin 17
  servo17.attach(18); // servo on digital pin 18
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
        servo1.write(60); //1=Feet
        servo5.write(60); 
        delay(twait*2);
        servo1.write(120); 
        servo5.write(120); 
        delay(twait*2);
        break;

      case '2':
        servo2.write(60); //2=Knees
        servo6.write(60); 
        delay(twait*2);
        servo2.write(120); 
        servo6.write(120); 
        delay(twait*2);
        break;

      case '3':
        servo3.write(60); //3=Hips
        servo7.write(60); 
        delay(twait*2);
        servo3.write(120); 
        servo7.write(120); 
        delay(twait*2);
        break;

      case '4':
        servo4.write(60); //4=Hips
        servo8.write(60); 
        delay(twait*2);
        servo4.write(120); 
        servo8.write(120); 
        delay(twait*2);
        break;

      case '5':
        servo9.write(60); //5=hand
        servo13.write(60); 
        delay(twait*2);
        servo9.write(120); 
        servo13.write(120); 
        delay(twait*2);
        break;

      case '6':
        servo10.write(60); //6=wrist
        servo14.write(60); 
        delay(twait*2);
        servo10.write(120); 
        servo14.write(120); 
        delay(twait*2);
        break;

      case '7':
        servo11.write(60); //7=elbow    
        servo15.write(60);     
        delay(twait*2);
        servo11.write(120); 
        servo15.write(120); 
        delay(twait*2);
        break;

      case '8':
        servo12.write(90); //8=Shoulders   
        servo16.write(90);     
        delay(twait*2);
        break;

      case '9':
        servo17.write(60); //9=Head   
        delay(twait*2);
        servo17.write(120); 
        delay(twait*2);
        break;

      case 's': // sit down
        servo2.write(35);
        servo3.write(160);
        servo6.write(145);
        servo7.write(20);
        delay(twait*10);
        servo2.write(30); // lean forward to stand back up
        servo3.write(180);
        servo6.write(150);
        servo7.write(00);
        delay(twait*10);
        break;

      case 'w': // wave hand
        servo12.write(30);
        servo10.write(100);
        delay(twait*5);
        servo10.write(160);
        delay(twait*5);
        servo10.write(100);
        delay(twait*5);
        servo10.write(160);
        delay(twait*5);
        servo10.write(100);
        delay(twait*5);
        break;
        
      case 'p': // pick up
        servo10.write(110);  // hands down
        servo14.write(70);
        servo12.write(140); // arms forward
        servo16.write(40);
        servo2.write(70); // bend down
        servo3.write(145);
        servo6.write(110);
        servo7.write(35);
        delay(twait*5);
        servo9.write(60); // close hands
        servo13.write(60);
        delay(twait*5);
        servo2.write(70); // rise up slowly
        servo3.write(120);
        servo6.write(110);
        servo7.write(60);
        delay(twait*2);
        servo2.write(85); // rise up
        servo3.write(90);
        servo6.write(95);
        servo7.write(90);
        delay(twait*5);
        servo12.write(90); // raise arms
        servo16.write(90);
        delay(twait*10);
        break;
        
      case 'c': // Clap hands
        servo2.write(85); // Lean back to counterbalance arms
        servo6.write(95); 
        servo9.write(90); // move arms forward
        servo10.write(120);
        servo11.write(120);
        servo12.write(90);
        servo13.write(90);
        servo14.write(60);
        servo15.write(60);
        servo16.write(90);
        servo17.write(40);
        delay(twait*5);  
        servo9.write(60); //pinch hands
        servo13.write(60);
        servo17.write(140);
        delay(twait*5);
        servo9.write(90); //open hands
        servo13.write(90);
        servo17.write(40);
        delay(twait*5);
        break;        

      // Sequential operations 
      case 'r': // right key;
        for (int i=0; i<10; i++){
          servo1.write(turnr[0][i]);  
          servo2.write(turnr[1][i]);  
          servo3.write(turnr[2][i]);  
          servo4.write(turnr[3][i]);  
          servo5.write(turnr[4][i]);  
          servo6.write(turnr[5][i]); 
          servo7.write(turnr[6][i]);  
          servo8.write(turnr[7][i]); 
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
