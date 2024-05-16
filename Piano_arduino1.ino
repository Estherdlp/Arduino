//Arduino 1
void setup()
{
  pinMode(2,OUTPUT);          //Zumbador
  pinMode(3,OUTPUT);          //Led blanco
  pinMode(4,OUTPUT);          //Led amarillo
  pinMode(5,OUTPUT);          //Led rojo
  pinMode(6,OUTPUT);          //Led verde
  pinMode(7,OUTPUT);          //Led azul
  pinMode (8, INPUT);         //Pulsador 1
  pinMode (9, INPUT);         //Pulsador 2
  pinMode (10, INPUT);        //Pulsador 3
  pinMode (11, INPUT);        //Pulsador 4
  pinMode (12, INPUT);        //Pulsador 5
  Serial.begin(9600);
}

void generar_melodia(int melodia[10]){       //Se genera una melodia aleatoria cada inicio de ciclo
  for (int i=0;i<10;i++){
    melodia[i]=random(1,6);   //Valor aleatorio entre 1 y 5, almacenado en vector melodia, posicion i
  }
}

int pulsador1(int &contador){ //Funcion si se pulsa el primer pulsador, recibiendo 1
  tone(2, 146.83);            //Re tercera octava
  delay(500);
  if (digitalRead(12)==HIGH){ //Se deja de pulsar el pulsador
    ;
  }
  noTone(2);                  //Se apaga el zumbador
  contador++;
  return (1);                 //Devuelve el numero de pulsador tocado
}

int pulsador2(int &contador){ //Funcion si se pulsa el segundo pulsador, recibiendo 1
  tone(2, 164.81);            //Mi tercera octava
  delay(500);
  if(digitalRead(11)==HIGH){  //Se deja de pulsar el pulsador
    ;
  }
  noTone(2);                  //Se apaga el zumbador
  contador++;
  return (2);                 //Devuelve el numero de pulsador tocado
}

int pulsador3(int &contador){ //Funcion si se pulsa el tercer pulsador, recibiendo 1
  tone(2, 174.61);            //Fa tercera octava
  delay(500);
  if (digitalRead(10)==HIGH){ //Se deja de pulsar el pulsador
    ;
  }
  noTone(2);                  //Se apaga el zumbador
  contador++;
  return (3);                 //Devuelve el numero de pulsador tocado
}

int pulsador4(int &contador){ //Funcion si se pulsa el cuarto pulsador, recibiendo 1
  tone(2, 196.00);            //Sol tercera octava
  delay(500);
  if (digitalRead(9)==HIGH){  //Se deja de pulsar el pulsador
    ;
  }
  noTone(2);                  //Se apaga el zumbador
  contador++;
  return (4);                 //Devuelve el numero de pulsador tocado
}

int pulsador5(int &contador){ //Funcion si se pulsa el quinto pulsador, recibiendo 1
  tone(2, 222.00);            //La tercera octava
  delay(500);
  if (digitalRead(8)==HIGH){  //Se deja de pulsar el pulsador
    ;
  }
  noTone(2);                  //Se apaga el zumbador
  contador++;
  return (5);                 //Devuelve el numero de pulsador tocado
}

int pulsador6(int &contador){ //Funcion si se pulsa el primer pulsador, recibiendo 0
  tone(2, 2349.32);           //Re septima octava
  delay(500);
  if (digitalRead(12)==HIGH){ //Se deja de pulsar el pulsador
    ;
  }
  noTone(2);                  //Se apaga el zumbador
  contador++;
  return (1);                 //Devuelve el numero de pulsador tocado
}

int pulsador7(int &contador){ //Funcion si se pulsa el primer pulsador, recibiendo 0
  tone(2,   2637.02);         //Mi septima octava
  delay(500);
  if (digitalRead(12)==HIGH){ //Se deja de pulsar el pulsador
    ;
  }
  noTone(2);                  //Se apaga el zumbador
  contador++;
  return (2);                 //Devuelve el numero de pulsador tocado
}

int pulsador8(int &contador){ //Funcion si se pulsa el primer pulsador, recibiendo 0
  tone(2, 2793.83);           //Fa septima octava
  delay(500);
  if (digitalRead(12)==HIGH){ //Se deja de pulsar el pulsador
    ;
  }
  noTone(2);                  //Se apaga el zumbador
  contador++;
  return (3);                 //Devuelve el numero de pulsador tocado
}

int pulsador9(int &contador){ //Funcion si se pulsa el primer pulsador, recibiendo 0
  tone(2, 3135.96);           //Sol septima octava
  delay(500);
  if (digitalRead(12)==HIGH){ //Se deja de pulsar el pulsador
    ;
  }
  noTone(2);                  //Se apaga el zumbador
  contador++;
  return (4);                 //Devuelve el numero de pulsador tocado
}

int pulsador10(int &contador){//Funcion si se pulsa el primer pulsador, recibiendo 0
  tone(2, 3520.00);           //La septima octava
  delay(500);
  if (digitalRead(12)==HIGH){ //Se deja de pulsar el pulsador
    ;
  }
  noTone(2);                  //Se apaga el zumbador
  contador++;
  return (5);                 //Devuelve el numero de pulsador tocado
}

void cancion(int contador,int melodia[10]){   //Funcion que recorre la melodia propuesta y enciende el led correspondiente
  if (melodia[contador]==1){  //Indicacion para primer pulsador
    digitalWrite(7,HIGH);
    delay(1000);
    digitalWrite(7,LOW);
  }
  if (melodia[contador]==2){  //Indicacion para segundo pulsador
    digitalWrite(6,HIGH);
    delay(1000);
    digitalWrite(6,LOW);
  }
  if (melodia[contador]==3){  //Indicacion para tercer pulsador
    digitalWrite(5,HIGH);
    delay(1000);
    digitalWrite(5,LOW);
  }
  if (melodia[contador]==4){  //Indicacion para cuarto pulsador
    digitalWrite(4,HIGH);
    delay(1000);
    digitalWrite(4,LOW);
  }
  if (melodia[contador]==5){  //Indicacion para quinto pulsador
    digitalWrite(3,HIGH);
    delay(1000);
    digitalWrite(3,LOW);
  }
}
void contadorAciertos(int melodia[10], int pulsador_usuario[10]){ //Funcion que contabiliza el numero de aciertos del usuario
  int aciertos=0;
  for (int contador2=0;contador2<10;contador2++){
    if (melodia[contador2]==pulsador_usuario[contador2]){
      aciertos++;
    }
  }
  if (aciertos==10){          //Si se han acertado todas las notas, parpadean todos los LED y suena musica de victoria
    for (int i=0;i<3;i++){ 
      digitalWrite(3, HIGH);  //Se encienden todos los led
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      tone(2, 600);           //Tono victoria parte 1
      delay (1000);
      digitalWrite(3, LOW);   //Se apagan todos los led
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      tone(2, 800);           //Tono victoria parte 1
      delay (1000);
    }
    noTone(2);                //Se apaga el zumbador
  }
  if (aciertos<10){           //Si no se han acertado todas las notas, se ilumina el LED rojo y suena musica de derrota
    digitalWrite(5, HIGH); 
    tone(2, 600);             //Musica de derrota
    delay(1000);
    noTone(2);
    tone(2, 400);
    delay (1000);
    noTone(2);
    tone(2, 200);
    delay (1000);
    noTone(2);
    digitalWrite(5, LOW);     //Se apaga led rojo
  }
  aciertos=0;                 //Variable aciertos a 0 para el siguiente ciclo
}

void loop()
{
  char lectura[1];
  int contador=0,lecturaInt=0, melodia[10]={0,0,0,0,0,0,0,0,0,0}, pulsador_usuario[10]={0,0,0,0,0,0,0,0,0,0}; //Declaracion variables
  if (Serial.available()){
    if (contador==0){
      generar_melodia(melodia);          //Llamada a la funcion que genera una melodia aleatoria cada iteracion
    }
    Serial.readBytesUntil('\0',lectura,1);
    lecturaInt=atoi(lectura);
    while(lecturaInt==0 && contador<10){
      Serial.readBytesUntil('\0',lectura,1);
      lecturaInt=atoi(lectura);
      cancion(contador, melodia);      //Llamada funcion cancion, pasando como entrada la posicion de la melodia
      if (digitalRead(12)==HIGH){      //Llamada a la funcion de re septima octava
        pulsador_usuario[contador]=pulsador6(contador);
      }
      if (digitalRead(11)==HIGH){      //Llamada a la funcion de mi septima octava
        pulsador_usuario[contador]=pulsador7(contador);
      }
      if (digitalRead(10)==HIGH){      //Llamada a la funcion de fa septima octava
        pulsador_usuario[contador]=pulsador8(contador);
      }
      if (digitalRead(9)==HIGH){       //Llamada a la funcion de sol septima octava
        pulsador_usuario[contador]=pulsador9(contador);
      }
      if (digitalRead(8)==HIGH){       //Llamada a la funcion de la septima octava             
        pulsador_usuario[contador]=pulsador10(contador);
      }
    }
    while(lecturaInt==1 && contador<10){
      Serial.readBytesUntil('\0',lectura,1);
      lecturaInt=atoi(lectura);
      cancion(contador, melodia);      //Llamada funcion cancion, pasando como entrada la posicion de la melodia
      if (digitalRead(12)==HIGH){      //Llamada a la funcion de re tercera octava
        pulsador_usuario[contador]=pulsador1(contador);
      }
      if (digitalRead(11)==HIGH){      //Llamada a la funcion de mi tercera octava
        pulsador_usuario[contador]=pulsador2(contador);
      }
      if (digitalRead(10)==HIGH){      //Llamada a la funcion de fa tercera octava
        pulsador_usuario[contador]=pulsador3(contador);
      }
      if (digitalRead(9)==HIGH){       //Llamada a la funcion de sol tercera octava
        pulsador_usuario[contador]=pulsador4(contador);
      }
      if (digitalRead(8)==HIGH){       //Llamada a la funcion de la tercera octava              
        pulsador_usuario[contador]=pulsador5(contador);
      }
    }
    if (contador==10){      //Cuando se han tocado 10 veces los pulsadores, llama a la funcion que comprueba los aciertos
      contadorAciertos(melodia, pulsador_usuario);
      contador=0;             //Variable contador a 0 para el siguiente ciclo
    }
  }
}
