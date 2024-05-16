int PWMpin=10;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  for (int i=0;i<=255;i++){
    analogWrite(PWMpin,i);
    delay(10);
    Serial.println(i);
  }
}
