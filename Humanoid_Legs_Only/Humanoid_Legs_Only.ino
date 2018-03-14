// Humanoid Legs Only
// Oct 2015 by Bob davis

#include <Servo.h> 
Servo servo1;  // create servo object to control a servo 
Servo servo2;
Servo servo3;
Servo servo4;  
 
void setup() 
{ 
  servo1.attach(2);  // Left Ankle - attaches the servo 
  servo2.attach(3);  // left hip
  servo3.attach(4);  // right Ankle
  servo4.attach(5);  // Right hip
  servo5.attach(7);  // Left arm
  servo6.attach(8);  // Right arm
  
  servo1.write(90);  // Set zero positions
  servo2.write(90);  // 
  servo3.write(90);  // 
  servo4.write(90);  // 
  delay(2000);
} 

void StepForward(){  //Moving Left Leg Forward
  servo1.write(75);  //shift weight to left ankle
  servo3.write(60);  //right ankle kicks weight over
  delay(200);
  servo3.write(70);  //level ankle lifts
  servo2.write(110); //left hip
  servo4.write(120); //right hip
  delay(200);
  servo1.write(90);  //level right ankle
  servo3.write(90);  //level right ankle
  delay(200);
  servo1.write(115);  //Shift weight to right ankle
  servo3.write(110);  //right ankle kicks weight to other
  delay(200);
  servo1.write(110);  //level ankle lifts
  servo2.write(70);  //left hip
  servo4.write(60);  //right hip
  delay(200);
  servo1.write(90);  //level ankle 
  servo2.write(90);  //left hip
  servo3.write(90);  //right ankle
  servo4.write(90);  //right hip
  delay(200);  
}
void StepBackward(){  //Moving Left Leg Forward
  servo1.write(75);  //shift weight to left ankle
  servo3.write(60);  //right ankle kicks weight over
  delay(200);
  servo3.write(70);  //level ankle lifts
  servo2.write(70); //left hip
  servo4.write(60); //right hip
  delay(200);
  servo1.write(90);  //level right ankle
  servo3.write(90);  //level right ankle
  delay(200);
  servo1.write(115);  //Shift weight to right ankle
  servo3.write(110);  //right ankle kicks weight to other
  delay(200);
  servo1.write(110);  //level ankle lifts
  servo2.write(110);  //left hip
  servo4.write(120);  //right hip
  delay(200);
  servo1.write(90);  //level ankle 
  servo2.write(90);  //left hip
  servo3.write(90);  //right ankle
  servo4.write(90);  //right hip
  delay(200);  
}
void WaveArms(){
  servo5.write(50);
  delay (200);  
  servo6.write(50);
  delay (200);  
  servo5.write(130);
  delay (200);  
  servo6.write(130);
  delay (200);  
  servo5.write(90);
  servo6.write(90);
 
}
//Main Function
void loop() { 
  StepForward();
  delay(500);
  StepForward();
  delay(500);
  StepBackward();
  delay(500);
  StepBackward();
  delay(500);
}
// end of program
