#include <Wire.h>//se llama la libreria Wire que nos ayudara a comunicarnos con el dispositivos de I2C
#include <LiquidCrystal_I2C.h>//se instala la libreria LiquidCrystal_I2C para trabajar con el i2c del lcd junto con el MÃ³dulo serial I2C
#define lcdAddress 0x27  //se indica la direcciÃ³n que toma el modulo i2c
#define filas 2//se indica que numero de filas que tiene el lcd que son dos para despues utilizarlo
#define columnas 16//se indica el numero de columnas que tiene el lcd que son 16 
LiquidCrystal_I2C pantallalcd(lcdAddress, columnas, filas);//se llama la libreria LiquidCrystal_I2C se le indica el nombre de pantallalcd se le indica la direcciÃ³n del lcd,la variable columnas y filas

const int pul = 2; //Define los pines a usar
const int pul_1 = 3;
const int buzz = 4;
const int trig = 5;
const int echo = 6;
float tempo;
float dis;
const float val = 58.2; 
int lee;

#define bomba 7  //Define el pin de la bomba
#define salida() pinMode(bomba,OUTPUT)
#define apagar() digitalWrite(bomba,HIGH)
#define encender() digitalWrite(bomba,LOW)
#define salidaa() pinMode(trig,OUTPUT)
#define entrada() pinMode(echo,INPUT) 

void setup() {
 pantallalcd.init();//se indica que la pantallalcd que en eso se iniciara
 pantallalcd.backlight();//se indica que la pantallalcd para su iluminaciÃ³n
 salidaa();//Variable de salida
 entrada();//Variable de entrada
 salida();//Variable de salida
 Serial.begin(9600);//Funcion del monitor serial
 attachInterrupt(digitalPinToInterrupt(pul_1),SIR,RISING);//Interrupcion del boton
 attachInterrupt(digitalPinToInterrupt(pul),MEN,RISING);//Interrupcion del boton
}

void SIR(){ //Funcion de no retorno
  pantallalcd.clear();
  pantallalcd.setCursor(0,0);
  pantallalcd.print("Extrayendo");
  delay(2000);
  pantallalcd.clear();
}

void MEN(){//Funcion de no retorno
  pantallalcd.clear();
  pantallalcd.setCursor(0,0);
  pantallalcd.print("Se detecto");
  pantallalcd.setCursor(2,1);
  pantallalcd.print("Interrupcion");
  delay(2000);
  pantallalcd.clear();
}


void BLACK(){
  if(dis<9){
    pantallalcd.setCursor(0,1);
    pantallalcd.print("*");
    delay(100);
    pantallalcd.print("*");
    delay(100);
    pantallalcd.print("*");
    delay(100);
  }
  if(dis<8){
    pantallalcd.print("*");
    delay(100);
    pantallalcd.print("*");
    delay(100);
    pantallalcd.print("*");
    delay(100);
  }
  if(dis<7){
    pantallalcd.print("*");
    delay(100);
    pantallalcd.print("*");
    delay(100);
    pantallalcd.print("*");
    delay(100);
  }
  if(dis<6){
    pantallalcd.print("*");
    delay(100);
    pantallalcd.print("*");
    delay(100);
  }
  if(dis<5){
    pantallalcd.print("*");
    delay(100);
  }
  if(dis<4){
    pantallalcd.print("*");
    delay(100);
    pantallalcd.print("*");
    delay(100);
  }
  if(dis<3){
    pantallalcd.print("*");
    delay(100);
    pantallalcd.print("*");
    delay(100);
  }
}


void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds (2);
  digitalWrite(trig, HIGH);
  delayMicroseconds (10);
  tempo = pulseIn(echo,HIGH);
  dis = (tempo) /val;
  Serial.print(dis);
  Serial.println("cm");
  pantallalcd.setCursor(1,0);
  pantallalcd.print("ESTADO TANQUE");
  BLACK();
}