#include <Wire.h> //Libreria I2C
#include <Adafruit_Sensor.h> // Libreria para Acelerometro
#include <Adafruit_ADXL345_U.h> //Libreria para Acelerometro
#include <Servo.h>//se instala esta libreria para el servo motor

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(); //Coloco Nombre al Acelerometro
int Eje_X = 0; //Variable para la aceleracion en eje X
int Eje_Y = 0; //Variable para la aceleracion en eje Y

int lu_x;//creacion de valor de dato 1
int lu_y;//creacion de valor de dato 2

Servo dota;//SE CREA LA VARIABLE PARA EL SERVO MOTOR
Servo jota;//SE CREA OTRA  VARIABLE PARA EL SERVO MOTOR


void setup(void) {
Serial.begin(9600); //Inicializo el monitor serial a 9600bps
 accel.begin();// Inicializo libreria del acelerometro
 dota.attach(3);
 jota.attach(4);
}

void loop(void) {

sensors_event_t event; //Le coloco un nombre a las lecturas del acelerometro
accel.getEvent(&event); //los datos de las lecturas del acelerometro se pasan a la funcion que envia los datos
Eje_X = event.acceleration.x; //Asigna la lectura del acelerometro en el eje X
Eje_Y = event.acceleration.y; //Asigna la lectura del acelerometro en el eje Y


lu_x = map(Eje_X, -10, 9, -80, 80);//Mapeo y restablecimiento de valores 1
lu_y = map(Eje_Y, -20, 10, -10, 80);//Mapeo y restablecimiento de valores 2
  
Serial.print("X: "); Serial.print(Eje_X); Serial.print(" ");
Serial.print("Y: "); Serial.print(Eje_Y); Serial.print(" ");
delay(100);

Serial.print("X: "); Serial.println(Eje_X); Serial.print(" ");//Imprecion de valores y signos
dota.write(lu_x);//establecimiento de valores 
Serial.print("Y: "); Serial.println(Eje_Y); Serial.print(" ");//Imprecion de valores y signos
jota.write(lu_y);//establecimiento de valores 
delay(100);//tiempo
}
