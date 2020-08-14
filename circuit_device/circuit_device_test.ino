bool switched = false;
bool released = false;
int landNum = 0;

void setup() {
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

   if (digitalRead(2) == HIGH) {
    SetLand(1);
  } else if (digitalRead(3) == HIGH) {
    SetLand(2);
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
