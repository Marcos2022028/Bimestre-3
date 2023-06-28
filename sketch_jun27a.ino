#include <LedControl.h> //libreria para las led matricial
#include <Adafruit_NeoPixel.h>//libreria para la rueda led
#include <Servo.h>//se instala esta libreria para el servo motor
#include <SoftwareSerial.h>//para el bluetoo



SoftwareSerial miBT(8, 9);
Adafruit_NeoPixel tira = Adafruit_NeoPixel(12,12);//SE INDICA EL NUMERO DE PIXELES A USAR Y EL PIN CON EL QUE SE VA A CONTROLAR
LedControl MATLED = LedControl(11,13,10,1);	// crea objeto

byte caracter[8] = {		//Arreglo para mostrar figura 1		
0x5a, 0x24, 0x18, 0x3c, 0x42, 0x99, 0x66, 0x0
};

byte caracter_2[8] = { //Arreglo para mostrar figura 2
0x3c, 0x5a, 0xa5, 0xa1, 0x99, 0x66, 0x3c, 0x18
};
byte caracter_3[8] = { //Arreglo para mostrar figura 3
0x18, 0x18, 0x66, 0x5a, 0xa5, 0x42, 0x24, 0x18
};

 //Se coloca el pin del led
char Dato;
int LED=2;
int LED_2=3;
int LED_3=4;
int LED_4=5;
//Se determina si estara prendida o apagada
bool estado = 0;
bool estado1=0;
bool estado2=0;
bool estado3=0;
//valores determinados con una funcion en especifico 
int valor;
int luces;
//Nombre del servo motor
Servo peep;

void setup() {
  miBT.begin(9600);
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(LED_2,OUTPUT);
  pinMode(LED_3,OUTPUT);
  pinMode(LED_4,OUTPUT);
  tira.begin();
  tira.show();//
  MATLED.shutdown(0,false);			// enciende la matriz
  MATLED.setIntensity(0,4);			// establece brillo
  MATLED.clearDisplay(0);	
  peep.attach(6);

}
void loop() {
  if (miBT.available() > 0){
    Dato = miBT.read();
   Serial.println(Dato);

   if(Dato == 'A')
   estado=!estado;
   digitalWrite(LED, estado);

    if(Dato == 'B')
   estado1=!estado1;
   digitalWrite(LED_2, estado1);

    if(Dato == 'C')
   estado2=!estado2;
   digitalWrite(LED_3, estado2);

    if(Dato == 'D')
   estado3=!estado3;
   digitalWrite(LED_4, estado3);


   if(Dato == 'E') //Boton de la aplicación
   figura();

   if(Dato == 'F') //Boton de la aplicación
   figura_2();

   if(Dato == 'G') //Boton de la aplicación
   figura_3();


   if(Dato == 'H')
    for(int i = 0; i<12; i = i+2 ){//Se crea la animación de la neopixel
       tira.setBrightness(100);
       tira.setPixelColor(i, 230,250,5);
       tira.show();
        delay(100);
    }

  } 
  servo();
  otros();

 }
 void figura(){
     for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
      {
     MATLED.setRow(0,i,caracter[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
 }

void figura_2(){
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_2[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }

}
void figura_3(){
     for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_3[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

void servo(){//que crea la función 
  if (miBT.available() > 0){//que si el bluetoo es mayor que cero
    valor = miBT.read();//valor sea a lee el bluetoo
    Serial.println(valor);//imprima el valor
    peep.write(valor); //y que el servo haga lo que este en el valor del servo
  }
}

void otros(){//se crea la variable para los cambios en las leds
  if (miBT.available() > 0){//que si el bluetoo es mayor que cero
    luces = miBT.read();//luces sea a lee el bluetoo
    Serial.println(luces);//imprima el valor_luces
    if(luces >= 195){//si luces es mayor e igual a 190
      digitalWrite(LED,HIGH);//este encienda la led1
    }
    if(luces >= 207){//si luces es mayor e igual a 200
      digitalWrite(LED_2,HIGH);//este encienda la led2
    }
    if(luces >= 214)//si luces es mayor e igual a 215
    {
      digitalWrite(LED_3,HIGH);//este encienda la led3
    }
    
    if(luces >= 220)//si luces es mayor e igual a 235
    {
      digitalWrite(LED_4,HIGH);//este encienda la led4
    }
  }
}