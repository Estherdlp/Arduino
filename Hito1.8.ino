int a=8;
int b=24;
int ledazul=8;
int ledverde=10;

void setup()
{
  pinMode(ledazul, OUTPUT);
  pinMode(ledverde, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(a>=b){
    digitalWrite(ledazul,HIGH);
  }
  else{
    digitalWrite(ledverde,HIGH);
  }
}
