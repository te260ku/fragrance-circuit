bool switched = false;
bool released = false;
bool touched = false;
int landNum = 0;

// static
const int maxLandNum = 2;

void setup() {
//  for (int i=0; i<maxLandNum; i++) {
//    pinMode(i, INPUT);
//  }  

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void SetLand(int num) {
  if (!released) {
    landNum = num;
    
    released = true;
    switched = true;
  }
}

void loop() {
  
for (int i=3; i>1; i--) {
  if (digitalRead(i) == HIGH) {
    
    SetLand(i);
    
    touched = true;

    break;
  } else {
    released = false;
    switched = false;
  }
}

//if (!touched) {
//    released = false;
//    switched = false;
//    touched = false;
//  }

  if (switched) {
    Serial.print(landNum);
    Serial.print("\t");
    Serial.println("");
    switched = false;
  }

  


  delay(100);
}
