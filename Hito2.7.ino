float a;
float temperaturaCelsius;
float temperaturaFahrenheit;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  a=analogRead(A1);
  temperaturaCelsius=5.0/1024*a*100-50;
  temperaturaFahrenheit=9.0/5*temperaturaCelsius+32;
  Serial.print("La temperatura en Celsius es: ");
  Serial.println(temperaturaCelsius);
  Serial.print("La temperatura en Fahrenheit es: ");
  Serial.println(temperaturaFahrenheit);
  delay(1000);
}
