bool switched = false;
bool released = false;
int landNum = 0;

void setup() {
 
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


    // 28しかない

//   if (digitalRead(2) == HIGH) {
//    SetLand(2);

    if (digitalRead(3) == HIGH) {
    SetLand(3);
    } else if (digitalRead(4) == HIGH) {
    SetLand(4);
    } else if (digitalRead(14) == HIGH) {
    SetLand(14);
    } else if (digitalRead(15) == HIGH) {
    SetLand(15);
  } else if (digitalRead(16) == HIGH) {
    SetLand(16);
  } else if (digitalRead(17) == HIGH) {
    SetLand(17);
  } else if (digitalRead(18) == HIGH) {
    SetLand(18);
    
    } else if (digitalRead(22) == HIGH) {
    SetLand(22);
    } else if (digitalRead(23) == HIGH) {
    SetLand(23);
    } else if (digitalRead(24) == HIGH) {
    SetLand(24);
    } else if (digitalRead(25) == HIGH) {
    SetLand(25);
    } else if (digitalRead(26) == HIGH) {
    SetLand(26);
    } else if (digitalRead(27) == HIGH) {
    SetLand(27);
    
    } else if (digitalRead(35) == HIGH) {
    SetLand(35);
    } else if (digitalRead(40) == HIGH) {
    SetLand(40);
    } else if (digitalRead(41) == HIGH) {
    SetLand(41);
    } else if (digitalRead(42) == HIGH) {
    SetLand(42);
    } else if (digitalRead(43) == HIGH) {
    SetLand(43);
    } else if (digitalRead(44) == HIGH) {
    SetLand(44);
    } else if (digitalRead(45) == HIGH) {
    SetLand(45);
    } else if (digitalRead(46) == HIGH) {
    SetLand(46);
    } else if (digitalRead(47) == HIGH) {
    SetLand(47);
    } else if (digitalRead(48) == HIGH) {
    SetLand(48);
    } else if (digitalRead(49) == HIGH) {
    SetLand(49);
    } else if (digitalRead(50) == HIGH) {
    SetLand(50);
    } else if (digitalRead(51) == HIGH) {
    SetLand(51);
    } else if (digitalRead(52) == HIGH) {
    SetLand(52);
    } else if (digitalRead(53) == HIGH) {
    SetLand(53);
    
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


  delay(100);
}
