#include <Stepper.h>
#include "LedControl.h" 


LedControl MATLED = LedControl(11,13,10,1);	// crea objeto


byte caracter[8] = {		//Arreglo para mostrar el numero 1		
0x0, 0x18, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3c
};

byte caracter_2[8] = { //Arreglo para mostrar el numero 2
 0x0, 0x3c, 0x42, 0x4, 0x8, 0x10, 0x20, 0x7e
};
byte caracter_3[8] = { //Arreglo para mostrar el numero 2
 0x3c, 0x66, 0x6, 0x1c, 0x6, 0x66, 0x3c, 0x0
};



float Tiempo= 2;          // Tiempo de retardo en milisegundos (Velocidad del Motor)
float numero_pasos = 0;   // Valor en grados donde se encuentra el motor
float grados;       // Almacena la cadena de datos recibida
float cuenta;
int Pulsador = 3;//pines en donde estan lo botones
int Pulsador2 = 4;//pines en donde estan lo botones
int Pulsador3 = 5;//pines en donde estan lo botones
int ESTADO1=LOW;
int ESTADO2=LOW;
int ESTADO3=LOW;
bool estado =0;
void setup() {                
pinMode(9, OUTPUT);   //Salida que va conectado al motor
pinMode(8, OUTPUT);   //Salida que va conectado al motor
pinMode(7, OUTPUT);    //Salida que va conectado al motor
pinMode(6, OUTPUT);    //Salida que va conectado al motor
pinMode(Pulsador,INPUT);//se configura el pin 12 como entrada para el boton1
pinMode(Pulsador2,INPUT);//se configura el pin 13 como entrada para el boton2
pinMode(Pulsador3,INPUT);//se configura el pin 3  como entrada para el boton3
  MATLED.shutdown(0,false);			// enciende la matriz
  MATLED.setIntensity(0,4);			// establece brillo
  MATLED.clearDisplay(0);	
 attachInterrupt(digitalPinToInterrupt(3), interruptor, FALLING);//SE UTILIZA PARA INTERUPCIÓN
grados=0;
}
void loop() {
  ESTADO1=digitalRead(Pulsador);//monitorea el estado de los botones
  ESTADO2=digitalRead(Pulsador2);//monitorea el estado de los botones
  ESTADO3=digitalRead(Pulsador3);//monitorea el estado de los botones

   if(estado ==1)//PISO1	
  {     
     MATLED.clearDisplay(0);			// blanquea matriz
     if(grados==1465){grados=-1465;cuenta=960;}//si del PISO3 queremos ir al PISO1
       if(grados==750){grados=-750;}//si del PISO2 queremos ir al PISO1
       else
  {    grados=0;//si iniciamos en el PISO1
       grados = (grados* 1.4222222222); // Ajuste de 512 vueltas a los 360 grados
       while (grados>numero_pasos){   // Girohacia la izquierda en grados
       paso_izq();numero_pasos = numero_pasos + 1;
       }
       while (grados<numero_pasos){   // Giro hacia la derecha en grados
       paso_der();numero_pasos = numero_pasos - 1;
       cuenta=cuenta - 1;
       }
       grados=(grados/1.4222222222);//para poder comparar despues
        mostrar();
       apagado();         // Apagado del Motor para que no se caliente
  }
  estado =0;
  }



  if(ESTADO2==HIGH)//PISO2
  {    
     MATLED.clearDisplay(0);
     if(grados==0){grados=1200;}//si del PISO1 queremos ir al PISO2
       if(grados==2000){grados=grados-720;}//si del PISO3 queremos ir al PISO2
       else
  {    grados=1200;//si iniciamos en el PISO2
       grados = (grados* 1.4222222222); // Ajuste de 512 vueltas a los 360 grados
       while (grados>numero_pasos){   // Girohacia la izquierda en grados
       paso_izq();numero_pasos = numero_pasos + 1;
       }
       while (grados<numero_pasos){   // Giro hacia la derecha en grados
       paso_der();numero_pasos = numero_pasos - 1;
       }
       grados=(grados/1.4222222222);//para poder comparar despues	
        mostrar_2();	
       apagado();         // Apagado del Motor para que no se caliente
  }
  }
 if(ESTADO3==HIGH)//PISO3
  {    
     MATLED.clearDisplay(0);
     if(grados==0){grados=1100;cuenta=2000;}//si del PISO1 queremos ir al PISO3
       if(grados==750){grados=grados + 715;}//si del PISO2 queremos ir al PISO3
       else
  {    grados=2070;//si iniciamos en el PISO2
       grados = (grados* 1.4222222222); // Ajuste de 512 vueltas a los 360 grados
       while (grados>numero_pasos){   // Girohacia la izquierda en grados
       paso_izq();numero_pasos = numero_pasos + 1;
       cuenta=cuenta - 1;
       }
       while (grados<numero_pasos){   // Giro hacia la derecha en grados
       paso_der();numero_pasos = numero_pasos - 1;
       }
       grados=(grados/1.4222222222);//para poder comparar despues	
        mostrar_3();	
       apagado();         // Apagado del Motor para que no se caliente
  }
  }
}  ///////////////////// Fin del Loop ///////////////////////////
void paso_der(){         // Pasos a la derecha
 digitalWrite(9, LOW); 
 digitalWrite(8, LOW);  
 digitalWrite(7, HIGH);  
 digitalWrite(6, HIGH);  
 delay(Tiempo);  
 digitalWrite(9, LOW); 
 digitalWrite(8, HIGH);  
 digitalWrite(7, HIGH);  
 digitalWrite(6, LOW);  
 delay(Tiempo);  
 digitalWrite(9, HIGH); 
 digitalWrite(8, HIGH);  
 digitalWrite(7, LOW);  
 digitalWrite(6, LOW);  
 delay(Tiempo);
 digitalWrite(9, HIGH); 
 digitalWrite(8, LOW);  
 digitalWrite(7, LOW);  
 digitalWrite(6, HIGH);  
 delay(Tiempo);
}

void paso_izq() {        // Pasos a la izquierda
 digitalWrite(9, HIGH); 
 digitalWrite(8, LOW);  
 digitalWrite(7, LOW);  
 digitalWrite(6, HIGH);  
 delay(Tiempo); 
 digitalWrite(9, HIGH); 
 digitalWrite(8, HIGH);  
 digitalWrite(7, LOW);  
 digitalWrite(6, LOW);  
 delay(Tiempo);
 digitalWrite(9, LOW); 
 digitalWrite(8, HIGH);  
 digitalWrite(7, HIGH);  
 digitalWrite(6, LOW);  
 delay(Tiempo); 
 digitalWrite(9, LOW); 
 digitalWrite(8, LOW);  
 digitalWrite(7, HIGH); 
 digitalWrite(6, HIGH);  
 delay(Tiempo);   
    
}
        
void apagado() {         // Apagado del Motor
 digitalWrite(9, LOW); 
 digitalWrite(8, LOW);  
 digitalWrite(7, LOW);  
 digitalWrite(6, LOW);  
 }

 void mostrar(){			// funcion mostrar_1
  for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
  {
    MATLED.setRow(0,i,caracter[i]);		// establece fila con valor de array cero en misma posicion
  }
}

void mostrar_2(){
    for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
  {
    MATLED.setRow(0,i,caracter_2[i]);		// establece fila con valor de array cero en misma posicion
  }
}

void mostrar_3(){
    for (int i = 0; i < 8; i++)  		// bucle itera 8 veces por el array
  {
    MATLED.setRow(0,i,caracter_3[i]);		// establece fila con valor de array cero en misma posicion
  }
}

void interruptor(){
  estado = 1;
}