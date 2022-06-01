const int trigPin = 2, trigCote = 9, trigDevant = 7;
const int echoPin = 3, echoCote = 10, echoDevant = 8;
const int AO = A2, DO = 6;
int inByte = 0;
String DonneString = "";
boolean ledStatus = false;
bool connectedBT = false;
int vibLowObs = 400, vibMediumObs = 700, vibHighObs = 1023, vibPopObs = 850, vibS = 500;
int moteurVibreurDevant = 13, moteurVibreurDerriere = 11, moteurVibreurMilieu = 12;
long duration, durationCote, durationDevant;
int distances[10], distancesCote[10], distancesDevant[10];
float dangerosite, dangerositeCote, dangerositeDevant, verif1, verif2, verif3, verif4, verif5, verif6, timeM, timeA, timeElapsed, lastMove;
String Danger;

int GPSManeuver = -1;

int vibSType = 0;
int straight = 0, turnRight = 0, turnLeft = 0, keepRight = 0, keepLeft = 0, stayRight = 0, stayLeft = 0, bearRight = 0, bearLeft = 0, rightThenLeft = 0, leftThenRight = 0, enterThenExitRoundabout = 0;

bool ObstacleActive = true, SonoreActive = true;

#include <SoftwareSerial.h>
#include <I2Cdev.h>
#include <HMC5883L.h>
#include "Wire.h"
#include <MPU6050_light.h>
MPU6050 mpu(Wire);
#include <AceRoutine.h>
using namespace ace_routine;

SoftwareSerial mySerial(4, 5);

void goStraight() {
  switch(straight){
    case 0:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
    case 1:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
    case 2:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
    case 3:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
    case 4:
      analogWrite(moteurVibreurDevant, 255);
      delay(800);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
    case 5:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      break;
    case 6:
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
  }
}

void goTurnRight() {
  switch(turnRight){
    //chaussure gauche
  }
}

void goTurnLeft() {
  switch(turnLeft){
    case 0:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 1:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 2:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 3:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 4:
      analogWrite(moteurVibreurMilieu, 255);
      delay(800);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 5:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      break;
    case 6:
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
  }
}

void goKeepRight() {
  switch(keepRight){
    //chaussure gauche
  }
}

void goKeepLeft() {
  switch(keepLeft){
    case 0:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 1:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 2:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 3:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 4:
      analogWrite(moteurVibreurMilieu, 255);
      delay(800);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 5:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      break;
    case 6:
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
  }
}

void goStayRight() {
  switch(stayRight){
    //chaussure gauche
  }
}

void goStayLeft() {
  switch(stayLeft){
    case 0:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 1:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 2:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 3:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 4:
      analogWrite(moteurVibreurMilieu, 255);
      delay(800);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 5:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      break;
    case 6:
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
  }
}

void goBearRight() {
  switch(bearRight){
    //chaussure gauche
  }
}

void goBearLeft() {
  switch(bearLeft){
    case 0:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 1:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 2:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 3:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 4:
      analogWrite(moteurVibreurMilieu, 255);
      delay(800);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 5:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      break;
    case 6:
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
  }
}

void goRightThenLeft() {
  switch(rightThenLeft){
    //chaussure gauche
  }
}

void goLeftThenRight() {
  switch(leftThenRight){
    case 0:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 1:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 2:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 3:
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      delay(100);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 4:
      analogWrite(moteurVibreurMilieu, 255);
      delay(800);
      digitalWrite(moteurVibreurMilieu, LOW);
      break;
    case 5:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      break;
    case 6:
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
  }
}

void goEnterThenExitRoundabout(){
  switch(enterThenExitRoundabout){
    case 0:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
    case 1:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
    case 2:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
    case 3:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      delay(100);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
    case 4:
      analogWrite(moteurVibreurDevant, 255);
      delay(800);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
    case 5:
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      break;
    case 6:
      analogWrite(moteurVibreurDerriere, 255);
      delay(300);
      digitalWrite(moteurVibreurDerriere, LOW);
      analogWrite(moteurVibreurMilieu, 255);
      delay(300);
      digitalWrite(moteurVibreurMilieu, LOW);
      analogWrite(moteurVibreurDevant, 255);
      delay(300);
      digitalWrite(moteurVibreurDevant, LOW);
      break;
  }
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigCote, OUTPUT);
  pinMode(echoCote, INPUT);
  pinMode(trigDevant, OUTPUT);
  pinMode(echoDevant, INPUT);
  pinMode(moteurVibreurDevant, OUTPUT);
  pinMode(moteurVibreurDerriere, OUTPUT);
  pinMode(moteurVibreurMilieu, OUTPUT);
  pinMode(AO, INPUT);
  pinMode(DO, INPUT);
  Wire.begin();
  mpu.begin();
  mpu.calcGyroOffsets();
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  bool Etatcourant;
  static bool Etatprec = false;
  if(Etatprec == true){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distances[0] = duration * 0.034 / 2;
    digitalWrite(trigCote, LOW);
    delayMicroseconds(2);
    digitalWrite(trigCote, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigCote, LOW);
    durationCote = pulseIn(echoCote, HIGH);
    distancesCote[0] = durationCote * 0.034 / 2;
    digitalWrite(trigDevant, LOW);
    delayMicroseconds(2);
    digitalWrite(trigDevant, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigDevant, LOW);
    durationDevant = pulseIn(echoDevant, HIGH);
    distancesDevant[0] = durationDevant * 0.034 / 2;
  }

  //Lecture des bytes
  while (mySerial.available() > 0) {
     inByte = mySerial.read();
     Serial.println(inByte);
     switch(inByte){
       case 0:
        switch(mySerial.read()){
          case 0:
            switch(mySerial.read()){
              case 0:
                GPSManeuver = mySerial.read();
                break;
            }
            break;
          }
        break;
       case 2:
         switch(mySerial.read()){
           case 0:
             switch(mySerial.read()){
               case 0:
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
                break;
              case 1:
                switch(mySerial.read()){
                  case 0:
                    for(int x = 0; x < 50; x++) {
                      mySerial.print(1);
                      delay(15);
                      mySerial.print(0);
                      delay(15);
                      mySerial.print(6);
                      delay(15);
                      mySerial.print(map(analogRead(AO), 0, 1023, 0, 255));
                      delay(100);
                    }
                    break;
                }
                break;
              case 2:
                switch(mySerial.read()){
                  case 0:
                    for(int x = 0; x < 50; x++) {
                      digitalWrite(trigDevant, LOW);
                      delayMicroseconds(2);
                      digitalWrite(trigDevant, HIGH);
                      delayMicroseconds(10);
                      digitalWrite(trigDevant, LOW);
                      durationDevant = pulseIn(echoDevant, HIGH);
                      distancesDevant[0] = durationDevant * 0.034 / 2;
                      verif5 = distancesDevant[1] - distancesDevant[2];
                      verif6 = distancesDevant[0] - distancesDevant[2];
                      if(verif5 - verif6 <= 5)
                        dangerositeDevant = -verif5 * 10 / distancesDevant[1] * 265;
                      mySerial.print(1);
                      delay(15);
                      mySerial.print(0);
                      delay(15);
                      mySerial.print(2);
                      delay(15);
                      mySerial.print(map(constrain(dangerositeDevant, 0, 4500), 0, 4500, 0, 255));
                      delay(15);
                      mySerial.print(1);
                      delay(15);
                      mySerial.print(0);
                      delay(15);
                      mySerial.print(3);
                      delay(15);
                      mySerial.print(constrain(distancesDevant[0], 0, 255));
                      delay(15);
                      mySerial.print(1);
                      delay(15);
                      mySerial.print(0);
                      delay(15);
                      mySerial.print(4);
                      delay(15);
                      mySerial.print(constrain(verif6, 0, 255));
                      Serial.println(dangerositeDevant);
                      delay(100);
                      distancesDevant[9] = 0;
                      for(int x = 0; x<10;x++){
                        distancesDevant[10-x] = distancesDevant[9-x];
                      }
                    }
                    break;
                }
                break;
              case 3:
                switch(mySerial.read()){
                  case 0:
                    mySerial.print(1);
                    delay(15);
                     mySerial.print(0);
                    delay(15);
                    mySerial.print(1);
                    delay(15);
                    mySerial.print(Etatprec ? 1 : 0);
                    delay(15);
                    mySerial.print(2);
                    delay(15);
                     mySerial.print(0);
                    delay(15);
                    mySerial.print(3);
                    delay(15);
                    mySerial.print(0);
                }
                break;
             }
             break;
         }
         break;
       case 3:
         switch(mySerial.read()){
           case 0:
             switch(mySerial.read()){
               case 1:
                 vibLowObs = map(mySerial.read(),0,255,0,1023);
                 break;
               case 2:
                 vibMediumObs = map(mySerial.read(),0,255,0,1023);
                 break;
               case 3:
                 vibHighObs = map(mySerial.read(),0,255,0,1023);
                 break;
               case 4:
                 vibPopObs = map(mySerial.read(),0,255,0,1023);
                 break;
             }
             break;
          case 1:
            switch(mySerial.read()){
              case 0:
                vibS = map(mySerial.read(),0,255,0,1023);
                break;
              case 1:
                vibSType = mySerial.read();
                break;
            }
            break;
          case 2:
            switch(mySerial.read()){
              case 0:
                straight = mySerial.read();
                break;
              case 1:
                turnRight = mySerial.read();
                break;
              case 2:
                turnLeft = mySerial.read();
                break;
              case 3:
                keepRight = mySerial.read();
                break;
              case 4:
                keepLeft = mySerial.read();
                break;
              case 5:
                stayRight = mySerial.read();
                break;
              case 6:
                stayLeft = mySerial.read();
                break;
              case 7:
                bearRight = mySerial.read();
                break;
              case 8:
                bearLeft = mySerial.read();
                break;
              case 9:
                rightThenLeft = mySerial.read();
                break;
              case 10:
                leftThenRight = mySerial.read();
                break;
              case 11:
                enterThenExitRoundabout = mySerial.read();
                break;
            }
            break;
         }
        break;
     case 4:
        switch(mySerial.read()){
          case 0:
            switch(mySerial.read()){
              case 0:
                switch(mySerial.read()){
                  case 0:
                    mySerial.print(4);
                    delay(15);
                    mySerial.print(0);
                    delay(15);
                    mySerial.print(0);
                    delay(15);
                    mySerial.print(0);
                    ObstacleActive = false;
                    break;
                  case 1:
                    mySerial.print(4);
                    delay(15);
                    mySerial.print(0);
                    delay(15);
                    mySerial.print(0);
                    delay(15);
                    mySerial.print(1);
                    ObstacleActive = true;
                    break;
                }
                break;
              case 1:
                switch(mySerial.read()){
                  case 0:
                    mySerial.print(4);
                    delay(15);
                    mySerial.print(1);
                    delay(15);
                    mySerial.print(0);
                    delay(15);
                    mySerial.print(0);
                    SonoreActive = false;
                    break;
                  case 1:
                    mySerial.print(4);
                    delay(15);
                    mySerial.print(1);
                    delay(15);
                    mySerial.print(0);
                    delay(15);
                    mySerial.print(1);
                    SonoreActive = true;
                    break;
                }
                break;
            }
            break;
        }
        break;
     }
   }

  //GPS
  if(GPSManeuver != -1 && Etatprec == true){
    switch(GPSManeuver){
      case 0:
        goStraight();
        break;
      case 1:
        goTurnRight();
        break;
      case 2:
        goTurnLeft();
        break;
      case 3:
        goKeepRight();
        break;
      case 4:
        goKeepLeft();
        break;
      case 5:
        goStayRight();
        break;
      case 6:
        goStayLeft();
        break;
      case 7:
        goBearRight();
        break;
      case 8:
        goBearLeft();
        break;
      case 9:
        goRightThenLeft();
        break;
      case 10:
        goLeftThenRight();
        break;
      case 11:
        goEnterThenExitRoundabout();
        break;
    }
  }
  
  //Obstacles
  digitalWrite(moteurVibreurDevant, LOW);
  digitalWrite(moteurVibreurDerriere, LOW);
  digitalWrite(moteurVibreurMilieu, LOW);
  if(ObstacleActive && Etatprec == true){
    verif1 = distances[1] - distances[2];
    verif2 = distances[0] - distances[2];
    verif3 = distancesCote[1] - distancesCote[2];
    verif4 = distancesCote[0] - distancesCote[2];
    verif5 = distancesDevant[1] - distancesDevant[2];
    verif6 = distancesDevant[0] - distancesDevant[2];
    timeA = millis();
    if(verif1 - verif2 <= 5){
      dangerosite = -verif1 * 10 / distances[1] * (timeA-timeM);
      if(dangerosite > 0 && distances[0] < 100){
        if(dangerosite > 3000){
          analogWrite(moteurVibreurDerriere, vibPopObs);
        }
        else if(35 < dangerosite && dangerosite <= 55){
          analogWrite(moteurVibreurDerriere, vibLowObs);
        }
        else if(55 < dangerosite && dangerosite <= 125){
          analogWrite(moteurVibreurDerriere, vibMediumObs);
        }
        else if(125 < dangerosite && dangerosite <= 3000){
          analogWrite(moteurVibreurDerriere, vibHighObs);
        }
      }
    }
    if(verif3 - verif4 <= 5){
      dangerositeCote = -verif3 * 10 / distancesCote[1] * (timeA-timeM);
      if(dangerositeCote > 0 && distancesCote[0] < 100){
        if(dangerositeCote > 3000){
          analogWrite(moteurVibreurMilieu, vibPopObs);
        }
        else if(35 < dangerositeCote && dangerositeCote <= 55){
          analogWrite(moteurVibreurMilieu, vibLowObs);
        }
        else if(55 < dangerositeCote && dangerositeCote <= 125){
          analogWrite(moteurVibreurMilieu, vibMediumObs);
        }
        else if(125 < dangerositeCote && dangerositeCote <= 3000){
          analogWrite(moteurVibreurMilieu, vibHighObs);
        }
      }
    }
    if(verif5 - verif6 <= 5 && mpu.getGyroX() < 10){
      dangerositeDevant = -verif5 * 10 / distancesDevant[1] * (timeA-timeM);
      if(dangerositeDevant > 0 && distancesDevant[0] < 100){
        if(dangerositeDevant > 3000){
          analogWrite(moteurVibreurDevant, vibPopObs);
        }
        else if(35 < dangerositeDevant && dangerositeDevant <= 55){
          analogWrite(moteurVibreurDevant, vibLowObs);
        }
        else if(55 < dangerositeDevant && dangerositeDevant <= 125){
          analogWrite(moteurVibreurDevant, vibMediumObs);
        }
        else if(125 < dangerositeDevant && dangerositeDevant <= 3000){
          analogWrite(moteurVibreurDevant, vibHighObs);
        }
      }
    }
    timeM = timeA;
    
    distances[9] = 0;
    for(int x = 0; x<10;x++){
      distances[10-x] = distances[9-x];
    }

    distancesCote[9] = 0;
    for(int x = 0; x<10;x++){
      distancesCote[10-x] = distancesCote[9-x];
    }

    distancesDevant[9] = 0;
    for(int x = 0; x<10;x++){
      distancesDevant[10-x] = distancesDevant[9-x];
    }
  }

  //Accéléromètre
  mpu.update();
  float tmp = mpu.getTemp();
  float gyro[3] = {mpu.getGyroX(), mpu.getGyroY(), mpu.getGyroZ()};


  if((abs(gyro[0])>=10) || (abs(gyro[1])>=10) || (abs(gyro[2])>=10)) {
    Etatcourant = true;
    lastMove = millis();
  } else {
    Etatcourant = false;
  }
  
  timeElapsed = millis() - lastMove;
  if (!Etatprec == Etatcourant) {
    if (Etatcourant == true) {
      mySerial.print(1);
      delay(15);
      mySerial.print(0);
      delay(15);
      mySerial.print(1);
      delay(15);
      mySerial.print(1);
      Etatprec = Etatcourant;
    }
    else if (timeElapsed >= 120000) {
      mySerial.print(1);
      delay(15);
      mySerial.print(0);
      delay(15);
      mySerial.print(1);
      delay(15);
      mySerial.print(0);
      Etatprec = Etatcourant;
    }
  }

  //Détection sonore
  if(SonoreActive && Etatprec == true){
    float Analog;
    int Digital;
    Analog = analogRead(AO);
    Digital = digitalRead(DO);
    
    //Serial.print ("Tension analogique:"); Serial.print (Analog, 4);  Serial.print ("V, ");
    //Serial.print ("Limite:");
    
    if(Digital==1)
    {
        switch(vibSType){
          case 0:
            analogWrite(moteurVibreurDevant, vibS);
            analogWrite(moteurVibreurDerriere, vibS);
            analogWrite(moteurVibreurMilieu, vibS);
            delay(300);
            digitalWrite(moteurVibreurDevant, LOW);
            digitalWrite(moteurVibreurDerriere, LOW);
            digitalWrite(moteurVibreurMilieu, LOW);
            break;
          case 1:
            analogWrite(moteurVibreurDevant, vibS);
            analogWrite(moteurVibreurDerriere, vibS);
            analogWrite(moteurVibreurMilieu, vibS);
            delay(300);
            digitalWrite(moteurVibreurDevant, LOW);
            digitalWrite(moteurVibreurDerriere, LOW);
            digitalWrite(moteurVibreurMilieu, LOW);
            delay(100);
            analogWrite(moteurVibreurDevant, vibS);
            analogWrite(moteurVibreurDerriere, vibS);
            analogWrite(moteurVibreurMilieu, vibS);
            delay(300);
            digitalWrite(moteurVibreurDevant, LOW);
            digitalWrite(moteurVibreurDerriere, LOW);
            digitalWrite(moteurVibreurMilieu, LOW);
            break;
          case 2:
            analogWrite(moteurVibreurDevant, vibS);
            analogWrite(moteurVibreurDerriere, vibS);
            analogWrite(moteurVibreurMilieu, vibS);
            delay(300);
            digitalWrite(moteurVibreurDevant, LOW);
            digitalWrite(moteurVibreurDerriere, LOW);
            digitalWrite(moteurVibreurMilieu, LOW);
            delay(100);
            analogWrite(moteurVibreurDevant, vibS);
            analogWrite(moteurVibreurDerriere, vibS);
            analogWrite(moteurVibreurMilieu, vibS);
            delay(300);
            digitalWrite(moteurVibreurDevant, LOW);
            digitalWrite(moteurVibreurDerriere, LOW);
            digitalWrite(moteurVibreurMilieu, LOW);
            delay(100);
            analogWrite(moteurVibreurDevant, vibS);
            analogWrite(moteurVibreurDerriere, vibS);
            analogWrite(moteurVibreurMilieu, vibS);
            delay(300);
            digitalWrite(moteurVibreurDevant, LOW);
            digitalWrite(moteurVibreurDerriere, LOW);
            digitalWrite(moteurVibreurMilieu, LOW);
            break;
          case 3:
            analogWrite(moteurVibreurDevant, vibS);
            analogWrite(moteurVibreurDerriere, vibS);
            analogWrite(moteurVibreurMilieu, vibS);
            delay(800);
            digitalWrite(moteurVibreurDevant, LOW);
            digitalWrite(moteurVibreurDerriere, LOW);
            digitalWrite(moteurVibreurMilieu, LOW);
            break;          
        }
    }
  }
  delay(200);
}
