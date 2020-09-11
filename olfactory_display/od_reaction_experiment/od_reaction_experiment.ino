#include<Servo.h>
 
Servo servo1;
Servo servo2;
int c = 0;

void setup(void){  
  servo1.attach(13); 
  servo2.attach(12); 
  servo1.write(80); 
  servo2.write(0);
  
  
  Serial.begin(9600);
  Serial.println("Start");
}
 
void loop(void){

  int startDelayRand = random(1, 3);
  Serial.println("start delay: " + startDelayRand*1000);
  delay(startDelayRand*1000);  

  
  int servoRand = random(10);
  if (servoRand < 5) {
    servo1.write(0); 
    servo2.write(0);
    Serial.println("1");
  } else {
    servo1.write(80);
    servo2.write(70);
    Serial.println("0");
  }

  int endDelayRand = random(1, 3);
  Serial.println("end delay: " + endDelayRand*1000);
  delay(endDelayRand*1000);



  servo1.write(80);
  servo2.write(0);
  
  
  c++;
  if (c > 5) {
  delay(6000);
  c = 0; 
}


  

  
}
