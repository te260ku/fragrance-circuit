void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);

}

void loop() {
  if ( Serial.available() ) {
    char key;
    key = Serial.read();
    if (key == '9') {
      digitalWrite(2, HIGH);
    }
  }

}
