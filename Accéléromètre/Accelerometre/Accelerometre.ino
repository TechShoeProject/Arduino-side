#include "Wire.h"
#include <MPU6050_light.h>
MPU6050 mpu(Wire);
 
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.begin();
  mpu.calcGyroOffsets();

}
 
void loop() {
  mpu.update();
  float tmp = mpu.getTemp();
  float gyro[3] = {mpu.getGyroX(), mpu.getGyroY(), mpu.getGyroZ()};
  bool Etatcourant;
  static bool Etatprec;


  if((abs(gyro[0])>=10) || (abs(gyro[1])>=10) || (abs(gyro[2])>=10)) {

    Etatcourant = true;

  }

  else {

    Etatcourant = false;

  }

  if (!Etatprec == Etatcourant) {

    if (Etatcourant == true) {

    Serial.write(1);
    delay(15);
    Serial.write(0);
    delay(15);
    Serial.write(1);
    delay(15);
    Serial.write(1);
    }
    else {

    Serial.write(1);
    delay(15);
    Serial.write(0);
    delay(15);
    Serial.write(1);
    delay(15);
    Serial.write(0);
    }

  }

 Etatprec = Etatcourant;
 delay(100);
   
}
