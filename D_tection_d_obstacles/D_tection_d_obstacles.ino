// defines pins numbers
const int trigPin = 5;
const int echoPin = 4;
// defines variables
long duration;
int distances[10];
float dangerosite, verif1, verif2, timeM, timeA;
String Danger;
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
  

  
  
  verif1 = distances[1] - distances[2];
  verif2 = distances[0] - distances[2];
  timeA = millis();
  if(verif1 - verif2 <= 5){
    dangerosite = -verif1 * 10 / distances[1] * (timeA-timeM);
    if(dangerosite > 0 && distances[0] < 100){
      if(dangerosite > 3000){
        Serial.println("Pop");
      }
      else if(35 < dangerosite && dangerosite <= 55){
        Serial.println("Faible");
      }
      else if(55 < dangerosite && dangerosite <= 125){
        Serial.println("Moyen");
      }
      else if(125 < dangerosite && dangerosite <= 3000){
        Serial.println("Eleve");
      }
      Serial.println(dangerosite);
    }
  }
  timeM = timeA;
  
  distances[9] = 0;
  for(int x = 0; x<10;x++){
    distances[10-x] = distances[9-x];
  }

  delay(200);
}
