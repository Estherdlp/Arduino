#include <Servo.h>
Servo groveServo;
int potenciometro=0;
int shaft;

void setup()
{
  groveServo.attach(3);
  pinMode(potenciometro,INPUT);
}

void loop()
{
  shaft=analogRead(potenciometro);
  shaft=map(shaft,0,500,0,179);
  groveServo.write(shaft);
  delay(10);
}
