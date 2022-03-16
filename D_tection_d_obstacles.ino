// defines pins numbers
const int trigPin = 5;
const int echoPin = 4;
// defines variables
long duration;
int distances[10];
float variations[9];
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distances[0] = duration * 0.034 / 2;
  Serial.print("Distances: ");
  

  
  
  for(int x = 0; x<9;x++){
    variations[x] = distances[x] - distances[x+1];
  }

  if(distances[1] - distances[2] <= -100 && distances[0] < 100 distances[0] >= 70){
    if(distances[0] - distances[2] <= -100){
      //Danger Faible
    }
  }
  if(distances[1] - distances[2] <= -20 && distances[0] < 70 distances[0] >= 40){
    if(distances[0] - distances[2] <= -20){
      //Danger Moyen
    }
  }
  if(distances[1] - distances[2] <= - && distances[0] < 40 distances[0] >= 10){
    if(distances[0] - distances[2] <= -20){
      //Danger Moyen
    }
  }
  
  for(int x = 0; x<9;x++){
  Serial.println(variations[x]);
  delay(50);
  }
  distances[9] = 0;
  for(int x = 0; x<10;x++){
    distances[10-x] = distances[9-x];
  }

  delay(1000);
}
