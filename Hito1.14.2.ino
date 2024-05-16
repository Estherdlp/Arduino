int digito1=0;
int digito2=0;
int suma=0;
int multiplicacion=0;
int resta=0;
String lectura1="";
String lectura2="";
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Introduce dos digitos");
  while(!Serial.available()>0){
    ;
  }
  lectura1 = Serial.readStringUntil('\n');
  digito1=lectura1.toInt();
  Serial.print("Primer digito: ");
  Serial.println(digito1);
  while(!Serial.available()>0){
    ;
  }
  lectura2 = Serial.readStringUntil('\n');
  digito2=lectura2.toInt();
  Serial.print("Segundo digito: ");
  Serial.println(digito2);
  Serial.print("Valor en decimal de sumar ambos: ");
  suma=digito1+digito2;
  Serial.println(suma);
  Serial.print("Valor en decimal de multiplicar ambos: ");
  multiplicacion=digito1*digito2;
  Serial.println(multiplicacion);
  Serial.print("Valor en decimal de restar el segundo al primero: ");
  resta=digito1-digito2;
  Serial.println(resta);
  Serial.println("Gracias por utilizar nuestro servicio");
}
