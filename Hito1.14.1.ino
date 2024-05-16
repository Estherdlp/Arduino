int undigito=0;
int suma=0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Introduce un digito");
  while(!Serial.available()>0){
    ;
  }
  undigito=Serial.read();
  Serial.print("Valor en acii es: ");
  Serial.println(undigito);
  Serial.println("Valor en decimal (teclado) es: ");
  undigito=undigito-48;
  Serial.println(undigito);
  Serial.print("Valor en decimal de sumar al digito 5: ");
  suma=undigito+5;
  Serial.println(suma);
  delay(2000);
}
