int button=3;
int led=6;
int lectura=0;

void setup()
{
  pinMode(button, INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  lectura=digitalRead(button);
  if(lectura==1){
    digitalWrite(led,1);
    delay(2000);
  }
  else{
    digitalWrite(led,0);
  }

}
