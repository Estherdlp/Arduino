unsigned long time;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Tiempo");
  time=millis();
  Serial.println(time);
  delay(1000);
}
