// to Learn :
// refer to https://www.youtu.be/
int Switch1_Pin = 0;        // Switch 1
int Switch2_Pin = 1;        // Switch 2
int Switch3_Pin = 2;        // Switch 3
int DIR1 = 3;               // L293D signal - DIR1
int DIR2 = 4;               // L293D signal - DIR2
int EN1 = 5;                // L293D signal - EN1

void Motor_ccw()  {           // Rotate Counter Clock Wise
  digitalWrite(DIR1, HIGH);   // 1 Direction to go
  digitalWrite(DIR2, LOW);    // 2 Direction is stop
  digitalWrite(EN1, HIGH);    // Motor Enavle signal
}

void Motor_cw()  {           // Rotate Clock Wise
  digitalWrite(DIR1, LOW);   // 1 Direction is stop
  digitalWrite(DIR2, HIGH);  // 2 Direction to go
  digitalWrite(EN1, HIGH);   // Motor Enavle signal
}

void Motor_stop() {
  digitalWrite(DIR1, HIGH);  // 1 Direction to go
  digitalWrite(DIR2, HIGH);  // 2 Direction to go
  digitalWrite(EN1, LOW);   // Motor disEnavle signal
}

void setup() {
  Serial.begin(9600);

}


void loop() {



}
