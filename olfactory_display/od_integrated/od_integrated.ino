#include <Servo.h>

bool isSwitched = false;
bool isReleased = false;
// ランドの合計数
const int maxLandNum = 30;
// 匂いの情報を格納する配列
int smellStates[maxLandNum] = {1, 2};
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
  // 基板デバイスで使うピンの設定
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  servo1.attach(5);
  servo2.attach(6);

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
  
  // テスト用に2番ピンと3番ピンを使用
  if (digitalRead(2) == HIGH) {
    SetLand(0);
  } else if (digitalRead(3) == HIGH) {
    SetLand(1);
  } else {
    ServoDown(servo1);
    ServoDown(servo2);
    isReleased = false;
    isSwitched = false;
  }
  
  delay(100);
}
