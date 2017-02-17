// to Learn : digitalWrite(pin#=0~7,digital on/off)
// refer to https://www.youtu.be/
#include <stdio.h>

byte seven_seg_digits[10][8]  = {
  {0,0,1,1,1,1,1,1},            // 0
  {0,0,0,0,0,1,1,0},            // 1
  {0,1,0,1,1,0,1,1},            // 2
  {0,1,0,0,1,1,1,1},            // 3
  {0,1,1,0,0,1,1,0},            // 4
  {0,1,1,0,1,1,0,1},            // 5
  {0,1,1,1,1,1,0,1},            // 6
  {0,0,1,0,0,1,1,1},            // 7
  {0,1,1,1,1,1,1,1},            // 8
  {0,1,1,0,1,1,1,1},            // 9
};

// pinsetting
int switch1_Pin = A1;           // Analog switch #1
int switch2_Pin = A2;           // Analog switch #2
int switch3_Pin = A3;           // Analog switch #3
int switch4_Pin = A4;           // Analog switch #4
int switch5_Pin = A5;           // Analog switch #5

int Fnd_a = 0;
int Fnd_b = 1;
int Fnd_c = 2;
int Fnd_d = 3;
int Fnd_e = 4;
int Fnd_f = 5;
int Fnd_g = 6;
int Fnd_dot = 7;

void setup() {
  pinMode(Fnd_a, OUTPUT);
  pinMode(Fnd_b, OUTPUT);
  pinMode(Fnd_c, OUTPUT);
  pinMode(Fnd_d, OUTPUT);
  pinMode(Fnd_e, OUTPUT);
  pinMode(Fnd_f, OUTPUT);
  pinMode(Fnd_g, OUTPUT);
  pinMode(Fnd_dot, OUTPUT);

  pinMode(switch1_Pin,INPUT);
  pinMode(switch2_Pin,INPUT);
  pinMode(switch3_Pin,INPUT);
  pinMode(switch4_Pin,INPUT);
  pinMode(switch5_Pin,INPUT);

  writeDot(0);

  void writeDot(byte dot) {     // Dot LED Off.
    digitalWrite(7,dot);        // pin=7, 0=array all off
  }

  void NumberDisplay(byte num); { // Show num on FND
    int j;
    for (j=7; j>=0; j--)  {       // a ~ g
      digitalWrite(j, seven_seg_digits[num][j]);
    }
  }
}

void loop() {
  if (digitalRead(switch1_Pin) == LOW)  {
    NumberDisplay(1);                   // Show NUM1 using DISP.func
  }
  else if (digitalRead(switch2_Pin) == LOW) {
    NumberDisplay(3);                   // Show NUM3 using DISP.func
  }
  else if (digitalRead(switch3_Pin) == LOW) {
    NumberDisplay(5);                   // Show NUM5 using DISP.func
  }
  else if (digitalRead(switch4_Pin) == LOW) {
    NumberDisplay(7);                   // Show NUM7 using DISP.func
  }
  else if (digitalRead(switch5_Pin) == LOW) {
    NumberDisplay(9);                   // Show NUM9 using DISP.func
  }
  else { NumberDisplay(0); }
}
