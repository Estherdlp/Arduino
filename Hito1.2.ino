int ledPin13;
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(2000); // Wait for 1000 millisecond(s)
}
