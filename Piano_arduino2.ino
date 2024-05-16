//Arduino 2
void setup()
{
  pinMode(8, INPUT);        //Interruptor
  Serial.begin(9600);
}

void loop()
{
  unsigned long tiempo=0;
  int espera=0;
  tiempo=millis();          //Se vuelca el tiempo de ejecucion en la variable tiempo
  while(espera==0){
    if (millis() - tiempo > 1100){    //Si han pasado 1.1s, se pone a 1 espera
      espera=1;
    }
  }
  if(digitalRead(8)==HIGH && espera==1){  //Si han pasado 1.1s y el interruptor esta en alto, envia 1
    Serial.write("1");
    espera=0;
  }
  if(digitalRead(8)==LOW && espera==1){   //Si han pasado 1.1s y el interruptor esta en bajo, envia 0
    Serial.write("0");
    espera=0;
  }
}
