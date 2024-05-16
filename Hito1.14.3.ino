int suma=0;
String inString="";
void setup()
{
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  Serial.println("\n\nString toInt():");
  Serial.println();
}

int leerPSerie(){
  int valor=1;
  while(valor==1){
    while(!Serial.available()>0){
      ;
    }
    while(Serial.available()>0){
      inString = Serial.readStringUntil('\n');
      valor=inString.toInt();
      Serial.println(valor);
      inString="";
      return valor;
    }
  }
}

void loop()
{
  Serial.println("Introduzca un numero entero y pulse enter: ");
  int valorteclado=leerPSerie();
  Serial.print("Has introducido el valor: ");
  Serial.println(valorteclado);
  delay(1000);
  Serial.println("Introduzca otro numero entero y pulse enter: ");
  int valorteclado2=leerPSerie();
  Serial.print("Has introducido el valor: ");
  Serial.println(valorteclado2);
  delay(1000);
  suma=valorteclado+valorteclado2;
  Serial.print("El resultado de la suma es: ");
  Serial.println(suma);
}
