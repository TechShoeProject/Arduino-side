const int DO = 2, AO = A0;
float son;

void setup() {
  Serial.begin(9600);
  pinMode(AO, INPUT);
  pinMode(DO, INPUT);
}

void loop() {
  son = analogRead(AO);
  Serial.println(son);
  delay(20);
}
