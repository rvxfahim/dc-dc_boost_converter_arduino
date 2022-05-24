/*
 *  Timer1 library example
 *  June 2008 | jesse dot tane at gmail dot com
 */
 
#include "TimerOne.h"
#include <digitalWriteFast.h>
 int vOut;
 int dutycycle=1000;
 bool dir=false;
void setup()
{
  //Serial.begin(500000);
  Timer1.initialize(20);         // initialize timer1
  Timer1.pwm(9, dutycycle);                // setup pwm on pin 9, duty cycle
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(13, HIGH);
  //pinModeFast(7, INPUT);
  pinMode(7,INPUT);
  //attachInterrupt(digitalPinToInterrupt(7), decrease, CHANGE);
}

 
void loop()
{
//  vOut = analogRead(A0);
//  float vOut1 = vOut * (5.0 / 1023.0);
//  float current=vOut1/2631;
//  float v1=current*10000;
//  float total=v1+vOut1;
//  if (total>12)
//  {
//    dutycycle--;
//    Timer1.setPwmDuty(9, dutycycle);
//    }
//    else
//    {
//      dutycycle++;
//    Timer1.setPwmDuty(9, dutycycle);
//      }
//  if (total<12.3 && total>11.8)
//  {
//    digitalWrite(2, HIGH);
//    }
//  else
//  digitalWrite(2,LOW);
//  //Serial.println(total);
//  //float iOut=analogRead(A1);
//  //Serial.println("Current: " + String(iOut));

//  if(digitalReadFast(7)==HIGH)
//    {
//      dutycycle--;
//      Timer1.setPwmDuty(9, dutycycle);
//      //Serial.println("decreasing duty");
//      }
// else
//    {
//      dutycycle++;
//      Timer1.setPwmDuty(9, dutycycle);
//      //Serial.println("inreasing duty");
//      }

if(digitalRead(7)){
    
     dutycycle--;
     if(dutycycle<5)
     dutycycle=5;
    Timer1.setPwmDuty(9, dutycycle);
    }
    else{
     
      dutycycle++;
      if(dutycycle>1015)
      dutycycle=1015;
    Timer1.setPwmDuty(9, dutycycle);
    
   }

}
