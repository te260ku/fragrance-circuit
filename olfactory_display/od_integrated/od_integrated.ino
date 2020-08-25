#include <Servo.h>

bool isSwitched = false;
bool isReleased = false;
// ランドの合計数
const int maxLandNum = 30;
// 匂いの情報を格納する配列
int smellStates[maxLandNum] = {
  0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 
  0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2};
Servo servo1;
Servo servo2;

void ServoDown(Servo s) {
  s.write(0);
}
void ServoUp(Servo s) {
  s.write(90);
}

void setup() {
  Serial.begin(9600);
  
  // デジタルピン
  pinMode(2, INPUT);  
  pinMode(3, INPUT);  
  pinMode(4, INPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);  
  pinMode(16, INPUT);  
  pinMode(17, INPUT);  
  pinMode(18, INPUT); 
  pinMode(22, INPUT);  
  pinMode(23, INPUT);  
  pinMode(24, INPUT);  
  pinMode(25, INPUT);  
  pinMode(26, INPUT);  
  pinMode(27, INPUT);  
  pinMode(35, INPUT);
  pinMode(40, INPUT);  
  pinMode(41, INPUT);  
  pinMode(42, INPUT);  
  pinMode(43, INPUT); 
  pinMode(44, INPUT);
  pinMode(45, INPUT);
  pinMode(46, INPUT);  
  pinMode(47, INPUT);  
  pinMode(48, INPUT);  
  pinMode(49, INPUT);  
  pinMode(50, INPUT);
  pinMode(51, INPUT);
  pinMode(52, INPUT);  
  pinMode(53, INPUT); 


  // サーボ
  servo1.attach(13);
  servo2.attach(12);

  // サーボの初期化
  ServoDown(servo1);
  ServoDown(servo2);
}

void SetLand(int landNum) {

  if (!isReleased) {
    isReleased = true;
    isSwitched = true;
  }

  if (isSwitched) {
    int smellState = smellStates[landNum];

    if (smellState == 1) {
      // 匂い1がついているランドの場合
      ServoUp(servo1);
    } else if (smellState == 2) {
      // 匂い2がついているランドの場合
      ServoUp(servo2);
    } else {
      // 匂いがついていないランドの場合
      ServoDown(servo1);
      ServoDown(servo2);
      
    }

    Serial.print(landNum);
    Serial.print("\t");
    Serial.println("");
    isSwitched = false;
  }
}

void loop() {
  if (digitalRead(3) == HIGH) {
    SetLand(0);
  } else if (digitalRead(4) == HIGH) {
    SetLand(1);
  } else if (digitalRead(14) == HIGH) {
    SetLand(2);
  } else if (digitalRead(15) == HIGH) {
    SetLand(3);
  } else if (digitalRead(16) == HIGH) {
    SetLand(4);
  } else if (digitalRead(17) == HIGH) {
    SetLand(5);
  } else if (digitalRead(18) == HIGH) {
    SetLand(6);
  } else if (digitalRead(22) == HIGH) {
    SetLand(7);
  } else if (digitalRead(23) == HIGH) {
    SetLand(8);
  } else if (digitalRead(24) == HIGH) {
    SetLand(9);
  } else if (digitalRead(25) == HIGH) {
    SetLand(10);
  } else if (digitalRead(26) == HIGH) {
    SetLand(11);
  } else if (digitalRead(27) == HIGH) {
    SetLand(12);
  } else if (digitalRead(35) == HIGH) {
    SetLand(13);
  } else if (digitalRead(40) == HIGH) {
    SetLand(14);
  } else if (digitalRead(41) == HIGH) {
    SetLand(15);
  } else if (digitalRead(42) == HIGH) {
    SetLand(16);
  } else if (digitalRead(43) == HIGH) {
    SetLand(17);
  } else if (digitalRead(44) == HIGH) {
    SetLand(18);
  } else if (digitalRead(45) == HIGH) {
    SetLand(19);
  } else if (digitalRead(46) == HIGH) {
    SetLand(20);
  } else if (digitalRead(47) == HIGH) {
    SetLand(21);
  } else if (digitalRead(48) == HIGH) {
    SetLand(22);
  } else if (digitalRead(49) == HIGH) {
    SetLand(23);
  } else if (digitalRead(50) == HIGH) {
    SetLand(24);
  } else if (digitalRead(51) == HIGH) {
    SetLand(25);
  } else if (digitalRead(52) == HIGH) {
    SetLand(26);
  } else if (digitalRead(53) == HIGH) {
    SetLand(27);
  } else {
    ServoDown(servo1);
    ServoDown(servo2);
    isReleased = false;
    isSwitched = false;
  }
  
  delay(100);
}
