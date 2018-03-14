// Humanoid 9 DOF demo
// Oct 2015 by Bob Davis

#include <Servo.h> 
Servo servo1;  // Left Ankle
Servo servo2;  // Left Hip
Servo servo3;  // Right Ankle
Servo servo4;  // Right Hip
Servo servo5;  // Left arm
Servo servo6;  // Left Shoulder
Servo servo7;  // Right arm
Servo servo8;  // Right Shoulder
Servo servo9;  // Head
int pos = 0;   // variable to store the servo position 
 
void setup() 
{ 
  servo1.attach(2);  // Left Ankle - attaches the servo 
  servo2.attach(3);  // Left hip
  servo3.attach(4);  // Right Ankle
  servo4.attach(5);  // Right hip
  servo5.attach(8);  // Left arm
  servo6.attach(9);  // Left Shoulder
  servo7.attach(10);  // Right arm
  servo8.attach(11);  // Right Shoulder
  servo9.attach(12);  // Head
  
  servo1.write(90);  // Set zero positions
  servo2.write(90);  // 
  servo3.write(90);  // 
  servo4.write(90);  // 
  servo5.write(90);  // Set zero positions
  servo6.write(170);  // 
  servo7.write(90);  // 
  servo8.write(10);  // 
  servo9.write(90);  // Set zero positions
  delay(200);
} 

void StepForward(){  
  servo1.write(80);  //shift weight to left ankle
  servo3.write(80);  
  delay(200);
  servo2.write(110); //left hip
  servo4.write(110); //right hip
  delay(200);
  servo1.write(90);  //level ankle 
  servo3.write(90);  //right ankle
  delay(200);
  servo1.write(100); //Shift weight to right ankle
  servo3.write(100);  
  delay(200);
  servo2.write(70);  //left hip
  servo4.write(70);  //right hip
  delay(200);
  servo1.write(90);  //level ankle 
  servo3.write(90);  //right ankle
  delay(200);
}
void StepBackward(){  
  servo1.write(80);  //shift weight to left ankle
  servo3.write(80);  
  delay(200);
  servo2.write(70);  //left hip
  servo4.write(70);  //right hip
  delay(200);
  servo1.write(90);  //level left ankle
  servo3.write(90);  //level right ankle
  delay(200);
  servo1.write(100);  //Shift weight to right ankle
  servo3.write(100);  
  delay(200);
  servo2.write(110);  //left hip
  servo4.write(110);  //right hip
  delay(200);
  servo1.write(90);  //level ankle 
  servo3.write(90);  //right ankle
  delay(200);
}
void WaveArms(){
  servo6.write(10);
  delay (500);  
  servo8.write(170);
  delay (500);  
  servo5.write(50);
  delay (200);  
  servo5.write(130);
  delay (200);  
  servo7.write(130);
  delay (200);  
  servo7.write(50);
  delay (200);  
  servo5.write(50);
  delay (200);  
  servo5.write(130);
  delay (200);  
  servo7.write(130);
  delay (200);  
  servo7.write(50);
  delay (200);  
  servo9.write(40);  // head
  delay (500);  
  servo9.write(140);
  delay (500);  
  servo5.write(90);
  servo6.write(170);
  servo7.write(90);
  servo8.write(10);
  servo9.write(90);
}
//Main Function
void loop() { 
  StepForward();
  StepForward();
  StepForward();
  StepForward();
  servo2.write(90);  //left hip
  servo4.write(90);  //right hip
  delay(500);  
  StepBackward();
  StepBackward();
  StepBackward();
  StepBackward();
  servo2.write(90);  //left hip
  servo4.write(90);  //right hip
  delay(500);  
  WaveArms();
  delay(500);
}
// end of program
