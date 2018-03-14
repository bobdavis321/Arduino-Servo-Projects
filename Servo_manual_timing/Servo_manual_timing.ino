
// Servo with manual timing
// By Bob Davis
// November 2, 2015
// Servos Connected D2-D19
// Does not use servo.h as the timing is included

void setup() { 
// The servos on pins 2-17
  for (int i=0; i<20; i++){
  pinMode (i, OUTPUT);
  }
} 
 
void loop() { 
  for (int i=0; i<20; i++){
  digitalWrite (i, HIGH);
  delayMicroseconds(1500);                           
  digitalWrite (i, LOW);
  }
  delay(20);  // in milliseconds                         
}  // End of program

