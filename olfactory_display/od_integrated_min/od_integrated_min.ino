bool isSwitched = false;
bool isReleased = false;
int landNum = 0;
const int maxLandNum = 2;
bool isSmellArray[maxLandNum] = {true, false};

void setup() {
  Serial.begin(9600);
  // 基板デバイスで使うピンの設定
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
}

void SetLand(int num, int land) {
  if (!isReleased) {
    landNum = num;
    isReleased = true;
    isSwitched = true;
  }
  


  if (isSwitched) {
    bool isSmell = isSmellArray[num];
    if (isSmell) {
      // サーボを回転させる
    }
    
    // unityに値を送信する
    Serial.print(landNum);
    Serial.print("\t");
    Serial.println("");
    
    isSwitched = false;
  }
}

void loop() {

  // 検出する項目
  // 1. どのランドに接触したのか
  // 2. そのランドに匂いは付いているか
  
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
