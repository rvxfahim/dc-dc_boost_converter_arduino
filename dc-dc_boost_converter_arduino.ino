/*
 *  Timer1 library example
 *  June 2008 | jesse dot tane at gmail dot com
 */
 
#include "TimerOne.h"
 int vOut;
 int dutycycle=1023;
void setup()
{
  Serial.begin(115200);
  Timer1.initialize(10);         // initialize timer1, and set a 1/2 second period
  Timer1.pwm(9, dutycycle);                // setup pwm on pin 9, 50% duty cycle
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

 
void loop()
{
  vOut = analogRead(A0);
  float vOut1 = vOut * (5.0 / 1023.0);
  float current=vOut1/1000.0;
  float v1=current*10000;
  float total=v1+vOut1;
  if (total>12)
  {
    dutycycle++;
    Timer1.setPwmDuty(9, dutycycle);
    }
    else
    {
      dutycycle--;
    Timer1.setPwmDuty(9, dutycycle);
      }
  //Serial.println(total);
}
