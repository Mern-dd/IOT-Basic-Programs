// #
// # Editor     : Lauren from DFRobot
// # Date       : 17.01.2012

// # Product name: Joystick Module
// # Product SKU : DFR0061
// # Version     : 1.0

// # Description:
// # Modify the Sample code for the Joystick Module

// # Connection:
// #        X-Axis  -> Analog pin 0
// #        Y-Axis  -> Analog pin 1
// #        Z-Axis  -> Digital pin 3
// #

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int JoyStick_X = 0; //x
int JoyStick_Y = 1; //y
int JoyStick_Z = 9; //key

void setup()
{
  myservo.attach(10); 

  pinMode(JoyStick_Z, INPUT);
  Serial.begin(9600); // 9600 bps
}
void loop()
{
  int x,y;
  x=analogRead(JoyStick_X);x-=360;
  y=analogRead(JoyStick_Y);y-=360;
  Serial.print(x);
  Serial.print(" , ");
  Serial.println(y);
  if(x> 100)
  {
    for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  }
  else if (x< -100)
  {
    for (pos = 120; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  }
  delay(100);
}
