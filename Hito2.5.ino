int ledazul=4;
int microfono=600;

void setup()
{
  pinMode(ledazul, OUTPUT);
}

void loop()
{
  int valorsensor=analogRead(A3);
  if(valorsensor>microfono){
    digitalWrite(ledazul,HIGH);
    delay(3000);
    digitalWrite(ledazul,LOW);
  }
  else{
    digitalWrite(ledazul,LOW);
  }
}
