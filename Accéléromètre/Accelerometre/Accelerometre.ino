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

  if((gyro[0]>=10) || (gyro[1]>=10) || (gyro[2]>=10) || (gyro[0]<=-10) || (gyro[1]<=-10) || (gyro[2]<=-10)) {
    Serial.write(1);
    delay(15);
    Serial.write(0);
    delay(15);
    Serial.write(1);
    delay(15);
    Serial.write(1);
    delay(15);
    Serial.println(1);

    while ((gyro[0]>=10) || (gyro[1]>=10) || (gyro[2]>=10) || (gyro[0]<=-10) || (gyro[1]<=-10) || (gyro[2]<=-10)) {
    }
  }

  else {
    Serial.write(1);
    delay(15);
    Serial.write(0);
    delay(15);
    Serial.write(1);
    delay(15);
    Serial.write(0);
    delay(15);
    Serial.println(0);

    while ((-10>gyro[0]<10) && (-10>gyro[1]<10) && (-10>gyro[2]<10)) {
    }
  }

  delay(100);
   
}
