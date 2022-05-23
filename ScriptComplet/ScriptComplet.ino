const int trigPin = 5;
const int echoPin = 4;
int inByte = 0;
String DonneString = "";
boolean ledStatus = false;
bool connectedBT = false;
int vibLowObs = 100, vibMediumObs = 175, vibHighObs = 255, vibPopObs = 200;
int moteurVibreurDevant = 9, moteurVibreurDerriere = 10, moteurVibreurMilieu = 11;
long duration;
int distances[10];
float dangerosite, verif1, verif2, timeM, timeA, timeElapsed, lastMove;
String Danger;

#include <SoftwareSerial.h>
#include <I2Cdev.h>
#include <HMC5883L.h>
#include "Wire.h"
#include <MPU6050_light.h>
MPU6050 mpu(Wire);

SoftwareSerial mySerial(2, 3);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(moteurVibreurDevant, OUTPUT);
  pinMode(moteurVibreurDerriere, OUTPUT);
  pinMode(moteurVibreurMilieu, OUTPUT);
  Wire.begin();
  mpu.begin();
  mpu.calcGyroOffsets();
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distances[0] = duration * 0.034 / 2;

  //Lecture des bytes
  while (mySerial.available() > 0) {
     inByte = mySerial.read();
     Serial.println(inByte);
     switch(inByte){
       case 2:
         delay(205);
         switch(mySerial.read()){
           case 0:
             analogWrite(moteurVibreurDevant, 255);
             analogWrite(moteurVibreurDerriere, 255);
             analogWrite(moteurVibreurMilieu, 255);
             delay(500);
             digitalWrite(moteurVibreurDevant, LOW);
             digitalWrite(moteurVibreurDerriere, LOW);
             digitalWrite(moteurVibreurMilieu, LOW);
             break;
         }
       case 3:
         delay(205);
         switch(mySerial.read()){
           case 1:
             delay(205);
             switch(mySerial.read()){
               case 1:
                 delay(205);
                 vibLowObs = map(mySerial.read(),0,255,0,1023);
                 break;
               case 2:
                 delay(205);
                 vibMediumObs = map(mySerial.read(),0,255,0,1023);
                 break;
               case 3:
                 delay(205);
                 vibHighObs = map(mySerial.read(),0,255,0,1023);
                 break;
               case 4:
                 delay(205);
                 vibPopObs = map(mySerial.read(),0,255,0,1023);
                 break;
             }
           break;
         }
        break;
     case 4:
        delay(205);
        switch(mySerial.read()){
          case 0:
            mySerial.write(4);
            delay(15);
            mySerial.write(0);
            break;
          case 1:
            mySerial.write(4);
            delay(15);
            mySerial.write(1);
        }
        break;
     }
   }
  
  //Obstacles
  verif1 = distances[1] - distances[2];
  verif2 = distances[0] - distances[2];
  timeA = millis();
  if(verif1 - verif2 <= 5){
    dangerosite = -verif1 * 10 / distances[1] * (timeA-timeM);
    if(dangerosite > 0 && distances[0] < 100){
      if(dangerosite > 3000){
        analogWrite(moteurVibreurDevant, vibPopObs);
      }
      else if(35 < dangerosite && dangerosite <= 55){
        analogWrite(moteurVibreurDevant, vibLowObs);
      }
      else if(55 < dangerosite && dangerosite <= 125){
        analogWrite(moteurVibreurDevant, vibMediumObs);
      }
      else if(125 < dangerosite && dangerosite <= 3000){
        analogWrite(moteurVibreurDevant, vibHighObs);
      }
    }
  }
  timeM = timeA;
  
  distances[9] = 0;
  for(int x = 0; x<10;x++){
    distances[10-x] = distances[9-x];
  }

  //Accéléromètre
  mpu.update();
  float tmp = mpu.getTemp();
  float gyro[3] = {mpu.getGyroX(), mpu.getGyroY(), mpu.getGyroZ()};
  bool Etatcourant;
  static bool Etatprec;


  if((abs(gyro[0])>=10) || (abs(gyro[1])>=10) || (abs(gyro[2])>=10)) {
    Etatcourant = true;
    lastMove = millis();
  } else {
    Etatcourant = false;
  }
  
  timeElapsed = millis() - lastMove;
  if (!Etatprec == Etatcourant) {
    if (Etatcourant == true) {
      mySerial.write(1);
      delay(15);
      mySerial.write(0);
      delay(15);
      mySerial.write(1);
      delay(15);
      mySerial.write(1);
    }
    else if (timeElapsed >= 120000) {
      mySerial.write(1);
      delay(15);
      mySerial.write(0);
      delay(15);
      mySerial.write(1);
      delay(15);
      mySerial.write(0);
      Etatprec = Etatcourant;
    }
  }
  delay(200);
}
