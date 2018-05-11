 //Tabla de notas
#define DO 262 // frecuencia para generar un DO
#define RE 294 // frecuencia de Re
#define MI 330 // frecuencia Mi
#define FA 350 // frecuencia para generar un FA
#define SOL 392 // frecuencia SOL
#define LA 440 // frecuencia para generar un LA
#define SI 494 // frecuencia del SI
#define DOL 530 // frecuencia Do sostenido
#define REL 570 //frecuencia Re sostenido
#define SILENCIO 0

//Canción que vamos a reproducir

const int melody[]{ 
DO, DO, RE, DO, FA, MI,

DO, DO, RE, DO, SOL, FA,

DO, DO, DOL, LA, FA, MI, RE,

SI, SI, LA, FA, SOL, FA}; // queremos reproducir



//Tabla donde guardamos la duracion necesaria de cada nota para que suene la cancion

const int duration[]{ //duración de cada nota

400,400,500,500,500,600,

400,400,500,500,500,600,

400,400,500,500,500,500,600,

400,400,500,500,500,600};


//*******************************

int Buzzer=8;  //Salida del Buzzer
int i;         //Contador para el bucle
int tam=sizeof(melody)/sizeof(melody[0]); //Numero de notas de la melodia
int Button=2;
int ButtonState;
int Sensor1=7
int Sensor2=6;
int SensorState1=3;
int SensorState2=4;
//*******************************
 
void setup() {
 pinMode(Buzzer,OUTPUT);
 pinMode(Button,INPUT);
 pinMode(Sensor1,INPUT);
 pinMode(Sensor2,INPUT);
 pinMode(SensorState1,OUTPUT);
 pinMode(Sensor
 Serial.begin(9600);
}
void loop() {  
Serial.println(ButtonState);
ButtonState=digitalRead(Button);
SensorState1=digitalRead(Sensor1);
SensorState2=digitalRead(Sensor2);
if(ButtonState==HIGH)
{  
  for (i = 0; i <tam; i++) {
    // pin8 output the voice, every scale is 0.5 sencond
    tone(Buzzer, melody[i], duration[i]);
    //Paramos de reproducir esta nota durante un breve periodo de tiempo
    delay(450);
  }
  }
   
  // restart after two seconds 
  analogWrite(Buzzer, SILENCIO);
  delay(5000);
}
