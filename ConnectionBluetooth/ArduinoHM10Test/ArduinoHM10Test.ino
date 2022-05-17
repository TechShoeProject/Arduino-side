int inByte = 0;         // incoming serial byte
String DonneString = "";
boolean ledStatus = false;
bool connectedBT = false;
int vibLowObs = 100, vibMediumObs = 175, vibHighObs = 255, vibPopObs =
200;
// defines pins numbers
const int trigPin = 5;
const int echoPin = 4;
// defines variables
long duration;
int distances[10];
float dangerosite, verif1, verif2, timeM, timeA;
String Danger;

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

void setup() {
   // start serial port at 9600 bps and wait for port to open:
   Serial.begin(9600);
   mySerial.begin(9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
}

void loop() {
   while (mySerial.available() > 0) {
     // get incoming byte:
     inByte = mySerial.read();
     switch(inByte){
       case 3:
         switch(mySerial.read()){
           case 1:
             switch(mySerial.read()){
               case 1:
                 vibLowObs = map(mySerial.read(),0,255,0,1023);
                 Serial.println(vibLowObs);
                 break;
               case 2:
                 vibMediumObs = map(mySerial.read(),0,255,0,1023);
                 Serial.println(vibMediumObs);
                 break;
               case 3:
                 vibHighObs = map(mySerial.read(),0,255,0,1023);
                 break;
               case 4:
                 vibPopObs = map(mySerial.read(),0,255,0,1023);
                 break;
           break;
             }
         }
         break;
     case 4:
        mySerial.write((byte)4);
        mySerial.write((byte)0);
     }
   }
   //Obstacles
   delay(1000);
   Serial.println(mySerial.read());
   mySerial.print(100);
   delay(15);
   mySerial.print(49);
}
