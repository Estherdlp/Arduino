int a=0;
int b=90;
int ledazul=8;


void setup()
{
  pinMode(ledazul, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while(a<b){
    a++;
    Serial.println(a);
  }
  if(a==b){
    digitalWrite(ledazul,HIGH);
  }
}
