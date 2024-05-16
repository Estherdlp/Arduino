int a=0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0){
    a=Serial.read();
    Serial.print("Recibido: ");
    Serial.println(a,HEX);
  }
}
