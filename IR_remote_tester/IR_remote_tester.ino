// IR Remote code capture
// Based on code from:
// Version 0.1 July, 2009
// Copyright 2009 Ken Shirriff
// http://arcfn.com

#include <IRremote.h>
int RECV_PIN = 19;  //Same as A5
IRrecv irrecv(RECV_PIN);
decode_results results; // Decode the results
void setup()
{
Serial.begin(9600);
irrecv.enableIRIn(); // receiver enable
}
void loop()
{
if(irrecv.decode(&results))
{
Serial.println(results.value,HEX); // Send the results
irrecv.resume(); // Resume receiving data
}
}
