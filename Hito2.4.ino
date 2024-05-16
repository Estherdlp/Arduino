int potenciometro=A3;

void setup()
{
  Serial.begin(9600);
  pinMode(potenciometro, INPUT);
}

void loop()
{
  int valor=analogRead(potenciometro);
  Serial.println(valor);
  delay(2000);
}
