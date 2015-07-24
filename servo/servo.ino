/*
Arduino Servo Test sketch
 */
#include <Servo.h>

Servo servo1; // Define our Servo

const int servo1Low = 0;
const int servo1High = 180;

void setup()
{
  Serial.begin(9600);
  servo1.attach(10);
}

void loop()
{
  servo1.write(servo1High);
  delay(500);       
  servo1.write(servo1Low);
  delay(500); 
}






