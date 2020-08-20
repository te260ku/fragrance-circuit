bool isSwitched = false;
bool isReleased = false;
const int maxLandNum = 2;
// 匂いの有無を格納する配列
bool isSmellArray[maxLandNum] = {true, false};

void setup() {
  Serial.begin(9600);
  // 基板デバイスで使うピンの設定
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void SetLand(int landNum) {
  // landNum: 配列のインデックスに対応する整数

  if (!isReleased) {
    isReleased = true;
    isSwitched = true;
  }

  if (isSwitched) {
    bool isSmell = isSmellArray[landNum];
    if (isSmell) {
      // 匂いがついているランドだったら
      // サーボを回転させる
    } else {
      // 匂いがついていないランドだったら
      // unityに値を送信する
      Serial.print(landNum);
      Serial.print("\t");
      Serial.println(""); 
    }
    
    isSwitched = false;
  }
}

void loop() {

  // 検出する項目
  // 1. どのランドに接触したのか
  // 2. そのランドに匂いは付いているか
  
  // テスト用に2番ピンと3番ピンを使用
  if (digitalRead(2) == HIGH) {
    SetLand(0);
  } else if (digitalRead(3) == HIGH) {
    SetLand(1);
  } else {
    isReleased = false;
    isSwitched = false;
  }
  
  delay(100);
}
