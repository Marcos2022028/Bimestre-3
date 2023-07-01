#include <Ticker.h>
#include "LedControl.h" //Libreria de la matriz led

void impresion(void);
Ticker Interrupcion(impresion, 3000); //Cada 3 segundos, realiza una interrupcion

int toma;//nos ayudara a tomar el valor del sensor 
int buzz=6;//indica el pin del buzzer
int sensor=A1;//indica el pin del sensor 

LedControl MATLED = LedControl(11,13,10,1);	// crea objeto

byte caracter[8] = {		//Arreglo para mostrar ALERTA	
0x3c, 0x5a, 0x99, 0x99, 0xbd, 0xa5, 0x5a, 0x3c
};

byte caracter_1[8] = {		//Arreglo para mostrar la llama	
0x8, 0x1c, 0x3a, 0x79, 0x79, 0x72, 0x3c, 0x0
};

byte caracter_2[8] = { //Arreglo para mostrar la letra M
0x0, 0x36, 0x36, 0x6b, 0x63, 0xc3, 0xc3, 0x0
};

byte caracter_3[8] = { //Arreglo para mostrar la letra A
 0x18, 0x24, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x0
};

byte caracter_4[8] = { //Arreglo para mostrar la letra R
 0x3c, 0x66, 0x66, 0x66, 0x78, 0x66, 0x66, 0x66
};

byte caracter_5[8] = { //Arreglo para mostrar la letra C
 0x0, 0x3c, 0x46, 0x46, 0x40, 0x46, 0x46, 0x3c
};

byte caracter_6[8] = { //Arreglo para mostrar la letra O
 0x3c, 0x66, 0x42, 0x42, 0x42, 0x66, 0x3c, 0x0
};

byte caracter_7[8] = { //Arreglo para mostrar la letra S
 0x0, 0x38, 0x44, 0x40, 0x38, 0x4, 0x4, 0x78
};

byte caracter_8[8] = { //Arreglo para mostrar el numero 2
 0x0, 0x38, 0x7c, 0xc, 0x18, 0x30, 0x3e, 0x0
};

byte caracter_9[8] = { //Arreglo para mostrar el numero 0
 0x0, 0x3c, 0x72, 0x62, 0x46, 0x4e, 0x3c, 0x0
};

byte caracter_10[8] = { //Arreglo para mostrar el numero 2
 0x0, 0x38, 0x7c, 0xc, 0x18, 0x30, 0x3e, 0x0
};

byte caracter_11[8] = { //Arreglo para mostrar el numero 2
 0x0, 0x38, 0x7c, 0xc, 0x18, 0x30, 0x3e, 0x0
};

byte caracter_12[8] = { //Arreglo para mostrar el numero 0
 0x0, 0x3c, 0x72, 0x62, 0x46, 0x4e, 0x3c, 0x0
};

byte caracter_13[8] = { //Arreglo para mostrar el numero 2
 0x0, 0x38, 0x7c, 0xc, 0x18, 0x30, 0x3e, 0x0
};

byte caracter_14[8] = { //Arreglo para mostrar el numero 8
0x3c, 0x42, 0x42, 0x3c, 0x42, 0x42, 0x42, 0x3c
};

void setup() {
  Serial.begin(9600);  //Inicio la comunicacion serial	

  MATLED.shutdown(0,false);			// enciende la matriz
  MATLED.setIntensity(0,4);			// establece brillo
  MATLED.clearDisplay(0);	//se indica para limpiar la matriz led
  //Interrupcion.start();   //Inicializa la libreria y las interrupciones por software
  pinMode(buzz, OUTPUT); //que el pin buzz se encuentra como salida
 
  //IMPRIME TODO LOS CARACTERES INDICADOS 
  delay(1500);
  Dibujo();
  delay(1500);
  Dibujo_2();
  delay(500);
  letra_2();
  delay(500);
  letra_3();
  delay(500);
  letra_4();
  delay(500);
  letra_5();
  delay(500);
  letra_6();
  delay(500);
  letra_7();
  delay(500);
  numero();
  delay(500);
  numero_1();
  delay(500);
  numero_2();
  delay(500);
  numero_3();
  delay(500);
  numero_4();
  delay(500);
  numero_5();
  delay(500);
  numero_6();
  delay(500);
}

void loop() {
  //Interrupcion.update(); //Actualiza la libreria para poder mantener la interrupcion al pendiente

  toma = analogRead(sensor);
  Serial.println(toma);
  if(toma >400){
    digitalWrite(buzz, HIGH);//que encienda el buzzer
    Dibujo();//Que haga lo que esta en la funcion
    delay(1000);//tome un descanso
    MATLED.clearDisplay(0);	//se indica para limpiar la matriz led
    Dibujo_2();
    delay(1000);
    MATLED.clearDisplay(0);	//se indica para limpiar la matriz led
  }else{
    digitalWrite(buzz, LOW);//APAGAR EL BUZZ
    delay(1000);
    MATLED.clearDisplay(0);	//se indica para limpiar la matriz led
  }

}



//funcion para mostrar figura 1
void Dibujo(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

void Dibujo_2(){//se crea la funcion para mostrar la llama
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_1[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la llama
void letra(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la   M
void letra_2(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_2[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la A
void letra_3(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_3[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la R
void letra_4(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_4[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la C
void letra_5(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_5[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la O
void letra_6(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_6[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para la S
void letra_7(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_7[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para el 2
void numero(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_8[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para el 0
void numero_1(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_9[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para el 2
void numero_2(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_10[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para el 2
void numero_3(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_11[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para el 0
void numero_4(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_12[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para el 2
void numero_5(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_13[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}

//funcion para el 8
void numero_6(){//se crea la funcion para figura
     MATLED.clearDisplay(0);
      for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
     {
     MATLED.setRow(0,i,caracter_14[i]);		// establece fila con valor de array cero en misma posicion
     delay(100);
     }
}


//par la interrupcion 
void impresion(void){
 Serial.println(toma);//se imprima el valor del sensor
}