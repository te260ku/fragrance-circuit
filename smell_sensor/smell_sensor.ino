const int pin_heater = 4;
const int pin_senser_on = 3;
const int pin_senser = A0;


void setup(){

  pinMode(pin_senser_on,OUTPUT);
  pinMode(pin_heater,OUTPUT);

  digitalWrite(pin_senser_on, LOW);
  digitalWrite(pin_heater, LOW);

  Serial.begin(9600);
}

 

int ReadSenser(){
  int val = 0;

  //センサー電源ON
  digitalWrite( pin_senser_on, HIGH );
  delay( 5 ); 
  val = analogRead( pin_senser );

  //センサー電源OFF
  digitalWrite( pin_senser_on, LOW );
  return val;

}


void Heat(){

  //8ms過熱
  digitalWrite( pin_heater, HIGH );
  delay( 8 );

  //237ms冷却
  digitalWrite( pin_heater, LOW );
  delay( 237 );
}


void loop(){
  int val = 0;

  // においに反応したら数値が上がるように取得値を逆転させる
  val = 1023 - ReadSenser();
  Heat();
  Serial.println(val);
}
