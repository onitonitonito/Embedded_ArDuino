// to Learn : Text LCD pannel TEST
// refer to https://www.youtu.be/
#include <LiquidCrystal.h>        // declair LCD header file
/* Pannel PIN ARRAY
1.    Vss     GND
2.    Vdd     Suppy 5V
3.    v0      Contrast control
4.    RS      Register Selection signal
5.    R/W     R/W signal ( High=read / Low = write)
6.    Enable  R/W capability
7~10  D0~D3   Data transfer
11~14 D4~D7   Data transfer
15    LED+    Back light power supply = 5V
16    LED-    Back light GND
*/

LiquidCrystal lcd(12,11,5,4,3,2);     // initialize LCD pin SETUP list
/* initialize LCD Pin SETUP list
** 6 Pins Array ( 12= RS, 11= Enable, 5~2= D7~D4 )
*/
int trigPin = 0;
int echoPin = 1;

int data = 12;
long sr04_check() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  delay (200)
  return distancel
}

void Clcd_display(long data) {
  int j,k,l,m = 0;
  j = (data % 10000)/1000;        // place 1,000
  k = (data % 1000)/100;          // place 100
  l = (data % 100)/10;            // place 10
  m = (data % 10)/1;              // place 1

  lcd.setCursor(0,0);
  lcd.print("SR04 LKE LAB");
  lcd.setCursor(0,1);

  if (data >= 200)  {
    lcd.print ("Out of range")
  }
  else {
    lcd.print("Distance =")
    lcd.print(j);                  // place 1,000
    lcd.print(k);                  // place 100
    lcd.print(l);                  // place 10
    lcd.print(m);                  // place 1
  }
}

void setup() {
  lcd.begin(16,2);                    // Column & Line(row) = (16 x 2)
  pinMode(trigPin, OUTPUT);           //
  pinMode(echoPin, INPUT);            //
}

void loop() {
  long data = sr04_Check();
  Clcd_display(data);
}
