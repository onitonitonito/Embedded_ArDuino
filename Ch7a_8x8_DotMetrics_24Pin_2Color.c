/*
 * Show messages on an 8x8 led matrix, scrolling from right to left.
 * Uses FrequencyTimer2 library to constantly run an interrupt routine
 * at a specified frequency. This refreshes the display without the
 * main loop having to do anything.
 */

 // to Learn :
 // refer to https://www.youtu.be/

#include <FrequencyTimer2.h>
//
#define SPACE { \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 0, 0}  \
}
#define H { \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 1, 1, 1, 1, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}  \
}
#define E { \
  {0, 1, 1, 1, 1, 1, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 1, 0}  \
}
#define L { \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 1, 0}  \
}
#define O { \
  {0, 0, 0, 1, 1, 0, 0, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 1, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 0, 0, 1, 0, 0}, \
  {0, 0, 0, 1, 1, 0, 0, 0}  \
}
#define W { \
  {1, 0, 0, 0, 0, 0, 0, 1},\
  {1, 0, 0, 0, 0, 0, 1, 0},\
  {1, 0, 0, 0, 0, 0, 1, 0},\
  {0, 1, 0, 1, 0, 0, 1, 0},\
  {0, 1, 0, 1, 0, 1, 0, 0},\
  {0, 1, 0, 1, 0, 1, 0, 0},\
  {0, 0, 1, 1, 0, 1, 0, 0},\
  {0, 0, 0, 1, 1, 0, 0, 0},\
}
#define R { \
  {1, 1, 1, 1, 1, 0, 0, 0},\
  {1, 0, 0, 0, 1, 0, 0, 0},\
  {1, 0, 0, 0, 1, 0, 0, 0},\
  {1, 1, 1, 1, 1, 0, 0, 0},\
  {1, 0, 1, 0, 0, 0, 0, 0},\
  {1, 0, 0, 1, 0, 0, 0, 0},\
  {1, 0, 0, 0, 1, 0, 0, 0},\
  {1, 0, 0, 0, 0, 1, 0, 0},\
}
#define D { \
  {1, 1, 1, 1, 1, 0, 0, 0},\
  {1, 1, 0, 0, 1, 1, 0, 0},\
  {1, 1, 0, 0, 0, 1, 1, 0},\
  {1, 1, 0, 0, 0, 1, 1, 0},\
  {1, 1, 0, 0, 0, 1, 1, 0},\
  {1, 1, 0, 0, 0, 1, 1, 0},\
  {1, 1, 0, 0, 1, 1, 0, 0},\
  {1, 1, 1, 1, 1, 0, 0, 0},\
}
#define Lk { \
  {0, 1, 0, 1, 0, 0, 1, 0},  \
  {0, 1, 0, 1, 0, 1, 0, 0}, \
  {0, 1, 0, 1, 1, 0, 0, 0}, \
  {0, 1, 0, 1, 0, 1, 0, 0}, \
  {0, 1, 0, 1, 0, 0, 1, 0}, \
  {0, 1, 0, 1, 0, 0, 0, 1}, \
  {0, 1, 0, 0, 0, 0, 0, 0}, \
  {0, 1, 1, 1, 1, 1, 1, 0} \
}
#define N0 { \
  {0, 0, 0, 1, 1, 1, 0, 0},  \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 1, 1, 1, 0, 0} \
}
#define N1 { \
  {0, 0, 0, 0, 1, 0, 0, 0},  \
  {0, 0, 0, 1, 1, 0, 0, 0}, \
  {0, 0, 0, 0, 1, 0, 0, 0}, \
  {0, 0, 0, 0, 1, 0, 0, 0}, \
  {0, 0, 0, 0, 1, 0, 0, 0}, \
  {0, 0, 0, 0, 1, 0, 0, 0}, \
  {0, 0, 0, 0, 1, 0, 0, 0}, \
  {0, 0, 0, 1, 1, 1, 0, 0} \
}
#define N2 { \
  {0, 0, 0, 1, 1, 1, 0, 0},  \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 1, 1, 1, 0, 0}, \
  {0, 0, 1, 0, 0, 0, 0, 0}, \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 1, 1, 1, 1, 0} \
}
#define N3 { \
  {0, 0, 0, 1, 1, 1, 0, 0},  \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 1, 1, 1, 0, 0}, \
  {0, 0, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 0, 0, 0, 1, 0}, \
  {0, 0, 1, 0, 0, 0, 1, 0}, \
  {0, 0, 0, 1, 1, 1, 0, 0} \
}

byte col = 0;
byte leds[8][8];

// pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
int pins[17]= {-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,A0,A1};

/* col[xx] of leds = pin yy on led matrix
int cols[8] = {pins[13], pins[3], pins[4], pins[10], pins[06],pins[11], pins[15], pins[16]}; */
int cols1[8] = {pins[1], pins[2], pins[3], pins[4], pins[5],pins[6], pins[7], pins[8]};
int cols2[8] = {pins[9], pins[10], pins[11], pins[12], pins[13],pins[14], pins[15], pins[16]};
/*
row[xx] of leds = pin yy on led matrix
*/
int rows[8] = {pins[24], pins[23], pins[22], pins[21], pins[4],pins[3], pins[2], pins[1]};

const int DS = A2;
const int ST_CP = A3;
const int SH_CP = A4;
/*
표현할 문자 패턴, numPatterns 의 갯수에 맞게 표시
Define 부에서 각 문자별로 정의 됨.  */

const int numPatterns = 16;                 //Total number of Charactor

#define Row_Sig_AllOff8

byte patterns[numPatterns][8][8] = {        //Using 8x8 Matrix, Show 16 letters
  H,E,L,L,O,W,O,R,L,D,SPACE,Lk,N0,N1,N2,N3
};

byte col = 0;
byte leds[8][8];
int pattern = 0;

void clearLeds()  {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 0;
    }
  }
}

void setPattern(int pattern) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = patterns[pattern][i][j];
    }
  }
}

void RowPulseControl(unsigned char data)  {
  switch(data)  {
    case 0:
      shiftRegister(0x80); break;     // 1st row
    case 1:
      shiftRegister(0x40); break;     // 2nd row
    case 2:
      shiftRegister(0x20); break;     // 3rd row
    case 3:
      shiftRegister(0x10); break;     // 4th row
    case 4:
      shiftRegister(0x08); break;     // 5th row
    case 5:
      shiftRegister(0x04); break;     // 6th row
    case 6:
      shiftRegister(0x02); break;     // 7th row
    case 7:
      shiftRegister(0x01); break;     // 8th row
    case Row_Sig_AllOff:
      shiftRegister(0x00); break;     // whole pin's signal OUT.
  }
}

// Interrupt routine
void display() {
  static bool toggle = 0;
  static unsigned cnt_time = 0;
  static unsigned char cnt = 0;
  RowPulseControl(Row_Sig_AllOff);  // former ROW pins SIG OFF.
  cnt_time++;
  if (cnt_time == 1000) {
    cnt_time = 0;
    pattern++;
    if (pattern > 10) {
      pattern = 0;
      toggle = 1;
    }
  }

  cnt++;                           // add row
  /*
  */
  if (cnt == 8)   {
    cnt = 0;
  }

  for (int col = 0; col<8 ; col++)  {
    switch(toggle)  {
      case 0:
        if (leds[cnt][col] == 1)  {
          digitalWrite(cols[col]. LOW);   // Yellow LED ON.
        }
        else  {
          digitalWrite(cols[col], HIGH);  // Yellow LED OFF.
        }
        digitalWrite(cols2[col],HIGH);    // Red LED OFF.
      break;

      case 1:
        if (leds[cnt][col] == 1)  {
          digitalWrite(cols2[col], LOW);  // Red LED ON.
        }
        else  {
          digitalWrite(cols2[col], HIGH); // Red LED OFF.
        }
        digitalWrite(cols[col], HIGH);    // Yellow LED OFF.
      break;
    }
  }
  RowPulseControl(cnt);                   // Row pin OUTPUT control
  /* before escape (Timer / Counter Interrrupt service routine),
    Row signal should be comtroled
  */
}

void shiftRegister(unsigned char data)  { // 74HC595 Shipt Reg-IC control func.
  int i = 0;
  digitalWrite(ST_CP, LOW)                // Ratch OFF

  for (i=0; i<8; i++) {
    digitalWrite(SH_CP, LOW);                 // flip prop clock pin = LOW
    if (data &(0x80>>i)) digitalWrite(DS, HIGH);  // Serial Data Pin HIGH?
    else digitalWrite(DS, LOW);                   // Serial Data pin LOW ?
    digitalWrite(SH_CP, HIGH);                    // flip-flap Clock pin HIGH
  }

  digitalWrite(ST_CP, HIGH);              // Ratch ON.
}

void setup() {
  /* 8x8-24pin Dot's PIN Array --> Set OUTPUT port
   (0,1,2,3,4,5,6~13,A0,A1)  Using for LOOP  */
  for (int i = 1; i <= 17; i++) {     // sets the pins as output
    pinMode(pins[i], OUTPUT);
  }
  pinMode(SH_CP, OUTPUT);         // Ratch Clock Pin --> OUTPUT port set
  pinMode(ST_CP, OUTPUT);         // Flip-plop clock Pin --> OUTPUT port set
  pinMode(DS, OUTPUT);            // Serial Data INPUT pin --> OUTPUT port set

  // clear memory for 8x8 dot.
  clearLeds();

  // Turn off toggling of pin 11
  FrequencyTimer2::disable();

  // Set refresh rate (interrupt timeout period)
  FrequencyTimer2::setPeriod(1000);

  // Set interrupt routine to be called
  FrequencyTimer2::setOnOverflow(display);
}

void loop() {
  setPattern(pattern);        // 8x8 Dot. copy Module Text function
}
