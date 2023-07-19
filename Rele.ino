#include <SoftwareSerial.h>//para el bluetoo
SoftwareSerial miBT(8, 9);//se indica el tx rxt de los pines que van y tambien el nombre del blueto

char Dato;//nos ayudaran a leer el dato que viene como caracter
bool esta = 0;
bool esta_1=0;  

#define Rele 5 // se crea una variable
#define Rele2 6 // se crea una variable
#define outpin(pin) pinMode(pin,OUTPUT) // se define y se acorta una función

void setup(){ //inica el void setup
miBT.begin(9600);//se inicializa el bluetoo
Serial.begin(9600); //para el monitor serial.
outpin(Rele);  //se declara que pin va a hacer
outpin(Rele2);  //se declara que pin va a hacer
} // se cierra el void setup


void loop(){ //inica el bucle
  if (miBT.available() > 0){//se indica lo que lleva la configuración del bluetoo
    Dato = miBT.read();//se indica que dato sea igual que lee el bluetoo
   Serial.println(Dato);// y que imprima el valor del dato

   if(Dato == 'F')//se dato es igual a el caracter A hace lo siguiente 
     Luz();

    if(Dato == 'G')//se dato es igual a el caracter A hace lo siguiente 
     Luz_2();

  }
}//finaliza  el programa. 
void Luz(){
   esta=!esta;// para apagar y encender con el mismo boton
   digitalWrite(Rele, esta);

}
void Luz_2(){
    esta_1=!esta_1;// para apagar y encender con el mismo boton
    digitalWrite(Rele, esta_1);
}