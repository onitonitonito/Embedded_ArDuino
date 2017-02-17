#include <DHT.h>
#define DHTPIN 2 //온습도 센서 핀
#define DHTTYPE DHT11 // 온습도 센서 타입
int pan = 4; // 팬 핀
//int nclls = 7; // 수위 센서 핀

DHT dht(DHTPIN, DHTTYPE);

void setup() {

Serial.begin(9600);
Serial.println("Start Humidity!");
dht.begin();
pinMode (pan, OUTPUT); //팬 셋업
pinMode (7, INPUT); //수위 센서 셋업

}

void loop() {
  float humi = dht.readHumidity();//습도 센서 읽기
  int nclls = digitalRead(7); //수위 센서 읽기

if (isnan(humi)){ //습도 센서 측정 부분

}else{
   Serial.print("Humidity: ");
   Serial.print(humi); //습도 센서 값
   Serial.println(" %\t");
   Serial.println(nclls); // 수위 센서 기본 값 (HIGH = 0/ LOW = 1)
   if(humi>=60 ){ //습도가 45 이상 일 경우
    if(nclls==HIGH){ //수위 센서 0으로 확인 된 경우
      digitalWrite(pan,HIGH); // 팬을 실행

    }
    else{  // 아닐경우
    digitalWrite(pan,LOW); // 팬을 종료

    }
   }
    else // 습도가 45 미만
    {
      if(nclls==HIGH) // 수위가 0으로 확인 된 경우
      {
      digitalWrite(pan,LOW); // 팬을 종료
      }else{
        digitalWrite(pan,LOW); //수위가 1으로 된 경우 팬 종료
      }
     }
}
}
