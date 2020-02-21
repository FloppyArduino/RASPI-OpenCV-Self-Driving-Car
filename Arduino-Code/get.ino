/*
 * Vincenzo Lombardo
 * Gr 12 Final Summitive
 * Self driving car transmit code
 */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

//---------motor pins-----//
int pin1 = A0;
int pin2 = A1;
int pin3 = A3;
int pin4 = A2;
int motorA=5;
int motorB=6;

void setup() {
  Serial.begin(9600);

  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(motorA,OUTPUT);
  pinMode(motorB,OUTPUT);
  
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}
struct cardata {
  bool m1;
  bool m2;
  bool m3;
  bool m4;
  int speed1;
  int speed2;
  byte rec;
}data;

void loop() {
  if (radio.available()>0) {
    while(radio.available()){
     radio.read(&data, sizeof(data));
      }
  }else{
        Serial.println("none");
    }
   // Serial.println(data.rec);
    movecar();
    
}

void movecar(){
  analogWrite(motorA,data.speed1);   
  analogWrite(motorB,data.speed2);
  digitalWrite(pin1,data.m1);
  digitalWrite(pin2,data.m2);
  digitalWrite(pin3,data.m3);
  digitalWrite(pin4,data.m4);
}
