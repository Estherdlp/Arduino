int ledazul=4;
int valorluz=50;

void setup()
{
  pinMode(ledazul, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int valorsensor=analogRead(5);
  if(valorsensor<valorluz){
    digitalWrite(ledazul,HIGH);
    delay(3000);
    digitalWrite(ledazul,LOW);
  }
  else{
    digitalWrite(ledazul,LOW);
  }
  if(valorsensor<103){
    Serial.println("Hay poca luz");
    delay(3000);
  }
  if(valorsensor>103 && valorsensor<206){
    Serial.println("Hay luz media");
    delay(3000);
  }
  if(valorsensor>206){
    Serial.println("Hay mucha luz");
    delay(3000);
  }
  Serial.println(valorsensor);
}
