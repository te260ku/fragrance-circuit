bool switched = false;
bool released = false;
int landNum = 0;

void setup() {
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(37, INPUT);
  pinMode(38, INPUT);
  pinMode(39, INPUT);
  pinMode(40, INPUT);
  pinMode(41, INPUT);
  pinMode(34, INPUT);
  pinMode(36, INPUT);
  pinMode(38, INPUT);
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
//  int i,s;
//
//  for (i = 2, s = 1; i >= 100, s >= 30, digitalRead(i) == HIGH; i++, s++ ) {
//    SetLand(s);
//  }

   if (digitalRead(22) == HIGH) {
    SetLand(1);
  } else if (digitalRead(23) == HIGH) {
    SetLand(2);
  } else if (digitalRead(24) == HIGH) {
    SetLand(3);
  } else if (digitalRead(25) == HIGH) {
    SetLand(4);
  } else if (digitalRead(26) == HIGH) {
    SetLand(5);
  } else if (digitalRead(27) == HIGH) {
    SetLand(6);
  } else if (digitalRead(28) == HIGH) {
    SetLand(7);
  } else if (digitalRead(29) == HIGH) {
    SetLand(8);
  } else if (digitalRead(30) == HIGH) {
    SetLand(9);
  } else if (digitalRead(31) == HIGH) {
    SetLand(10);
  } else if (digitalRead(32) == HIGH) {
    SetLand(11);
  } else if (digitalRead(33) == HIGH) {
    SetLand(12);
  } else if (digitalRead(34) == HIGH) {
    SetLand(13);
  } else if (digitalRead(35) == HIGH) {
    SetLand(14);
  } else if (digitalRead(36) == HIGH) {
    SetLand(15);
  } else if (digitalRead(37) == HIGH) {
    SetLand(16);
  } else if (digitalRead(38) == HIGH) {
    SetLand(17);
  } else if (digitalRead(39) == HIGH) {
    SetLand(18);
  } else if (digitalRead(40) == HIGH) {
    SetLand(19);
  } else if (digitalRead(41) == HIGH) {
    SetLand(20);
  } else if (digitalRead(42) == HIGH) {
    SetLand(21);
  } else if (digitalRead(43) == HIGH) {
    SetLand(22);
  } else if (digitalRead(44) == HIGH) {
    SetLand(23);
  } else if (digitalRead(45) == HIGH) {
    SetLand(24);
  } else if (digitalRead(46) == HIGH) {
    SetLand(25);
  } else if (digitalRead(47) == HIGH) {
    SetLand(26);
  } else if (digitalRead(48) == HIGH) {
    SetLand(27);
  } else if (digitalRead(49) == HIGH) {
    SetLand(28);
  } else if (digitalRead(50) == HIGH) {
    SetLand(29);
  } else if (digitalRead(51) == HIGH) {
    SetLand(30);
  } else if (digitalRead(52) == HIGH) {
    SetLand(31);
  } else {
    released = false;
    switched = false;
  }
  
 

  if (switched) {
    Serial.print(landNum);
    Serial.print("\t");
    Serial.println("");
    switched = false;
  }

  delay(1000);
}
