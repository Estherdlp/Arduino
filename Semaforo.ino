#include <LiquidCrystal.h>                  //Libreria LCD
int esperaFinalizada=0;                     //Definicion de variables
unsigned long tiempo=0;
LiquidCrystal lcd(5, 4, 0, 1, 2, 3);        //Pines cableados LCD (RS, E, D4, D5, D6, D7)

void setup() {
  pinMode(6,INPUT);                         //Pulsador
  pinMode(7,OUTPUT);                        //Zumbador
  pinMode (8, OUTPUT);                      //Led rojo peatones
  pinMode (9, OUTPUT);                      //Led verde peatones
  pinMode (10, OUTPUT);                     //Led rojo coches
  pinMode (11, OUTPUT);                     //Led amarillo coches
  pinMode (12, OUTPUT);                     //Led verde coches
  lcd.begin(16, 2);                         //LCD
  lcd.setCursor(0, 0);                      //Apuntar primera fila LCD
  lcd.print("**PEATON**");                  //Texto inicial primera fila
  lcd.setCursor(0, 1);                      //Apuntar primera fila LCD
  lcd.print("**PULSE**");                   //Texto inicial segunda fila
} 

int inicio_ciclo(){                          //Ambos semaforos en rojo para los peatones que no han terminado de cruzar
  digitalWrite(10,HIGH);
  digitalWrite(8,HIGH);   
  delay(2000);
  tiempo=millis();                           //Vuelca en la variable tiempo el tiempo que lleva arduino encendido
  return (0);
}

int semaforo_verde(int esperaFinalizada, unsigned long tiempo){                     //Coches verde y peatones rojo
  do{                                        //Ejecucion si el pulsador no se ha activado o no han transcurrido 30s
    digitalWrite(10,LOW);
    digitalWrite(12,HIGH);
    if (millis() - tiempo > 15000){          //Si han transcurrido 30 segundos, modifica el valor de la variable
      return (1);
    }
  }while(digitalRead(6)==LOW && esperaFinalizada==0);
  return (0);
}

int semaforo_amarillo(){                    //Coches amarillo y peatones rojo
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  delay(5000);
}

void semaforo_rojo(){                       //Coches rojo y peatones verde
  int contador=0;
  digitalWrite(11,LOW);                     //Se apagan las luces del estado anterior
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);                     //Se encienden las luces del estado actual
  digitalWrite(10,HIGH);
  for(contador=0;contador<10;contador++){   //Sonido para avisar del semaforo verde para peatones
    tone(7, 300);                          
    delay(500);                             
    noTone(7);                              //Apagar zumbador en cada iteracion
    delay(500);                             
  }
}

void semaforo_intermitente(){               //Parpadeo semaforo amarillo coches y verde peatones
  int contador=0;
  digitalWrite(9,LOW);                      //Se apagan las luces del estado anterior
  digitalWrite(10,LOW);
  for(contador=0;contador<12;contador++){    
    tone(7, 300);                           //Tono del zumbador pasivo al ponerse el semáforo en verde intermitente
    digitalWrite(9,HIGH);                   
    digitalWrite(11,HIGH);                  
    delay(400);                             
    noTone(7);                              //Apagar zumbador
    digitalWrite(9,LOW);                    
    digitalWrite(11,LOW);                   
    delay(350);
  }
}
void pantalla(){                            //Funcion para cambiar el texto de la pantalla
  lcd.setCursor(0, 0);                      //Primera fila de la pantalla
  lcd.print("**PEATON**");
  lcd.setCursor(0, 1);                      //Segunda fila de la pantalla
  lcd.print("**PULSE**");
  if (digitalRead(6)==HIGH){                //Mensaje en la pantalla si un peaton pide cambio de color
    lcd.setCursor(0, 0);                    //Primera fila de la pantalla
    lcd.print("**ESPERE**");
    lcd.setCursor(0, 1);                    //Segunda fila de la pantalla
    lcd.print("**VERDE**");
  }
}

void loop() {                               //Programa que itera
  pantalla();                               //Llamada a la funcion que modifica el texto de la pantalla
  esperaFinalizada=inicio_ciclo();          //Llamada a la funcion que pone ambos semaforos en rojo
  esperaFinalizada=semaforo_verde(esperaFinalizada,tiempo);//Llamada a la funcion que pone el semaforo de vehiculos en verde
  if (digitalRead(6)==HIGH){                //Llamada a la funcion que modifica el texto de la pantalla, solo si un peaton pide cruzar
    pantalla();
  }
  semaforo_amarillo();                      //Llamada a la funcion que pone el semaforo de vehiculos en amarillo
  pantalla();                               //Llamada a la funcion que modifica el texto de la pantalla
  semaforo_rojo();                          //Llamada a la funcion que pone el semaforo de vehiculos en rojo
  semaforo_intermitente();                  //Llamada a la funcion que pone el semaforo de vehiculos en amarillo intermitente
}
