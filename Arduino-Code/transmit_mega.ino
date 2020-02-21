/*
   Vincenzo Lombardo
   Gr 12 Final Summitive
   Self driving car transmit code
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();
  Serial.begin(9600);
}
struct cardata {
  bool m1;
  bool m2;
  bool m3;
  bool m4;
  int speed1;
  int speed2;
  byte rec;
} data;

byte rec;
void loop() {
  if (Serial.available() > 0) {
    rec = Serial.read();
  }
  else {
    // ree();
  }
  rec=2;
  data.rec = rec;
  send_command(rec);
  
}

void ree() {
  data.m1 = false;
  data.m2 = false;
  data.m3 = false;
  data.m4 = false;
  data.speed1 = 0;
  data.speed2 = 0;
  data.rec = 0;
  rec=0;
}

void send_command(byte command) {
  switch (command) {
    //reset command
     case 0: ree(); break;
    // single command
    case 1: forward(); break;
    case 2: reverse(); break;
    case 3: right(); break;
    case 4: left(); break;

    //combination command
    case 6: forward_right(); break;
    case 7: forward_left(); break;
    case 8: reverse_right(); break;
    case 9: reverse_left(); break;

  }
  radio.write(&data, sizeof(data));
}

void right() {
  data.m1 = true;
  data.m2 = false;
  data.m3 = false;
  data.m4 = true;
  data.speed1 = 125;
  data.speed2 = 125;
  //Serial.println("Right");

}

void left() {
  data.m1 = false;
  data.m2 = true;
  data.m3 = true;
  data.m4 = false;
  data.speed1 = 125;
  data.speed2 = 125;
   //Serial.println("Left");

}

void forward() {
  data.m1 = true;
  data.m2 = false;
  data.m3 = true;
  data.m4 = false;
  data.speed1 = 125;
  data.speed2 = 125;
 //Serial.println("Forward");
}

void reverse() {
  data.m1 = false;
  data.m2 = true;
  data.m3 = false;
  data.m4 = true;
  data.speed1 = 125;
  data.speed2 = 125;
 // Serial.println("Backwards");
}

void forward_right() {
  data.m1 = true;
  data.m2 = false;
  data.m3 = true;
  data.m4 = false;
  data.speed1 = 200;
  data.speed2 = 100;
  //Serial.println("FR");
}

void reverse_right() {
  data.m1 = false;
  data.m2 = true;
  data.m3 = false;
  data.m4 = true;
  data.speed1 = 200;
  data.speed2 = 100;
  // Serial.println("RR");
}

void forward_left() {
  data.m1 = true;
  data.m2 = false;
  data.m3 = true;
  data.m4 = false;
  data.speed1 = 100;
  data.speed2 = 200;
   //Serial.println("FL");
}

void reverse_left() {
  data.m1 = false;
  data.m2 = true;
  data.m3 = false;
  data.m4 = true;
  data.speed1 = 100;
  data.speed2 = 200;
 // Serial.println("RL");
}
