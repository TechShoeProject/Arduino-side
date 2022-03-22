int inByte = 0;         // incoming serial byte
boolean ledStatus = false;

void setup() {
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

    // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    if (inByte == 0x01) {
      if (ledStatus) {
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.print("Setting LED On");
        ledStatus = false;
      }
      else {
        digitalWrite(LED_BUILTIN, LOW);
        Serial.print("Setting LED Off");
        ledStatus = true;
      }
    }
    else {
      Serial.write(inByte);
    }
  }
}
