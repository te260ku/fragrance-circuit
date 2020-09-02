#include<Servo.h>
 
Servo servo1;
Servo servo2;

void setup(void){  
  servo1.attach(13); 
  servo2.attach(12); 
  servo1.write(0); 
  servo2.write(90);
  
  
  Serial.begin(9600);
  Serial.println("init");
}
 
void loop(void){

  int startDelayRand = random(1, 5);
  Serial.println(randDelay*1000);
  delay(randDelay*1000);  
  
  int servoRand = random(10);
  if (randServo < 5) {
    servo1.write(0); 
    servo2.write(90);
    Serial.println("1");
  } else {
    servo1.write(90);
    servo2.write(0);
    Serial.println("2");
  }

  int endDelayRand = random(1, 5);
  Serial.println(randDelay*1000);
  delay(randDelay*1000);

  servo1.write(0);
  servo1.write(90);

  
}
