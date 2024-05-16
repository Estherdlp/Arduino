String inputString = "";    //Cadena para almacenar lo que ha introducido el usuario
bool stringComplete = false;  //Booleano para cuando se pulse enter

void setup() {          //Inicializacion placa
  Serial.begin(9600);
  inputString.reserve(200);
}

void loop() {
  if (stringComplete==true){
    Serial.println(inputString);
    inputString = "";     //Limpia el string
    stringComplete = false;   //Pone la variable de control a falso
  }
}

void serialEvent(){       //Evento producido por introducir algo por teclado
  Serial.println("El valor introducido por el usuario es: ");
  inputString = Serial.readStringUntil('\n');
  if(inputString.length() > 0) {//Si la longitud de lo introducido es >0, variable de control true
     stringComplete = true;
  }
}
