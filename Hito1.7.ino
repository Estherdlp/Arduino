int a=2;
int b=6;
int c=0;


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  c=min(a,b);
  Serial.println("Imprime el valor minimo entre las variables a y b");
  Serial.println(c);
  delay(3000);
  
  c=max(a,b);
  Serial.println("Imprime el valor maximo entre las variables a y b");
  Serial.println(c);
  delay(3000);
  
  c=abs(a);
  Serial.println("Imprime el valor absoluto de la variable a");
  Serial.println(c);
  delay(3000);
  
  c=sq(b);
  Serial.println("Imprime el valor de la varaible b elevado al cuadrado");
  Serial.println(c);
  delay(3000);
}
