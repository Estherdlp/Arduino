int pinLedDigital=13;

void setup()
{
  Serial.begin(9600);
  pinMode(pinLedDigital, OUTPUT);
}

void loop()
{
  Serial.println("Hola mundo");
  digitalWrite(pinLedDigital,HIGH);
}
