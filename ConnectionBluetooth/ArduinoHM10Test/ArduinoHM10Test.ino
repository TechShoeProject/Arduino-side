int inByte = 0;         // incoming serial byte
boolean ledStatus = false;

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

void setup() {
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  while (mySerial.available() > 0) {
    // get incoming byte:
    inByte = mySerial.read();
    Serial.println(inByte);
    
  }
  delay(200);
}
