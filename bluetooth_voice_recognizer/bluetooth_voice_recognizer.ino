#include <SoftwareSerial.h>

SoftwareSerial hc06(12,13); //bluetooh module의 Tx, Rx

const int X0 = 3;
const int X1 = 4;
const int X2 = 5;
const int X3 = 6;
const int X4 = 7;
const int X5 = 8;
const int X6 = 9;
const int X7 = 10;

void setup() {
  Serial.begin(9600);
  Serial.println("최대 33개의 글자만 정의 가능");
  hc06.begin(9600);
  pinMode(X0, OUTPUT);
  pinMode(X1, OUTPUT);
  pinMode(X2, OUTPUT);
  pinMode(X3, OUTPUT);
  pinMode(X4, OUTPUT);
  pinMode(X5, OUTPUT);
  pinMode(X6, OUTPUT);
  pinMode(X7, OUTPUT);

  // 릴레이 기본 OFF
  digitalWrite(X0, HIGH);
  digitalWrite(X1, HIGH);
  digitalWrite(X2, HIGH);
  digitalWrite(X3, HIGH);
  digitalWrite(X4, HIGH);
  digitalWrite(X5, HIGH);
  digitalWrite(X6, HIGH);
  digitalWrite(X7, HIGH);
  
}

const int MAX_BYTE = 100;
byte bytes_text[MAX_BYTE];

void loop() {

  
  // 단어 추가
  String word_1 = "네모";  // 단어 선언(영어 한글 상관 없음)
  byte word_1_bytes[MAX_BYTE];  // 바이트로 바꿀 바이트 배열 선언
  memset(word_1_bytes, 0, MAX_BYTE);  // 바이트 배열 0으로 초기화
  word_1.getBytes(word_1_bytes, MAX_BYTE);  // 문자열을 바이트 배열로 변환

  String word_2 = "세모";
  byte word_2_bytes[MAX_BYTE];
  memset(word_2_bytes, 0, MAX_BYTE);
  word_2.getBytes(word_2_bytes, MAX_BYTE); 

  String word_3 = "별";
  byte word_3_bytes[MAX_BYTE];
  memset(word_3_bytes, 0, MAX_BYTE);
  word_3.getBytes(word_3_bytes, MAX_BYTE); 

  String word_4 = "넷";
  byte word_4_bytes[MAX_BYTE];
  memset(word_4_bytes, 0, MAX_BYTE);
  word_4.getBytes(word_4_bytes, MAX_BYTE); 

  String word_5 = "더하기";
  byte word_5_bytes[MAX_BYTE];
  memset(word_5_bytes, 0, MAX_BYTE);
  word_5.getBytes(word_5_bytes, MAX_BYTE); 

  String word_6 = "빼기";
  byte word_6_bytes[MAX_BYTE];
  memset(word_6_bytes, 0, MAX_BYTE);
  word_6.getBytes(word_6_bytes, MAX_BYTE); 

  String word_7 = "곱하기"; 
  byte word_7_bytes[MAX_BYTE];
  memset(word_7_bytes, 0, MAX_BYTE);
  word_7.getBytes(word_7_bytes, MAX_BYTE); 

  String word_8 = "나누기";
  byte word_8_bytes[MAX_BYTE];
  memset(word_8_bytes, 0, MAX_BYTE);
  word_8.getBytes(word_8_bytes, MAX_BYTE); 


  // 블루투스 모듈로부터 단어 수집
  byte received_bytes[MAX_BYTE];
  memset(received_bytes, 0, MAX_BYTE);
  int received_byte;
  
  if(hc06.available()){
    Serial.println("수신된 바이트 데이터");
    for(int i=0; i<100; i++){
      received_byte = hc06.read();
      received_bytes[i] = received_byte;
      delay(5);
      if(hc06.available()){
        continue;
      }else{
        printBytes(received_bytes);
        break;
      }
    }
  }

  // 단어 비교 및 동작
  if(memcmp(received_bytes, word_1_bytes, MAX_BYTE) == 0){
    Serial.println("매치된 바이트 데이터:");
    printBytes(word_1_bytes);
    Serial.println("입력된 글자는 word_1와(과) 일치합니다");
    digitalWrite(X0, LOW);
    delay(1000);
    digitalWrite(X0, HIGH);
  }

  else if(memcmp(received_bytes, word_2_bytes, MAX_BYTE) == 0){
    Serial.println("매치된 바이트 데이터:");
    printBytes(word_2_bytes);
    Serial.println("입력된 글자는 word_2와(과) 일치합니다");
    digitalWrite(X1, LOW);
    delay(1000);
    digitalWrite(X1, HIGH);
  }
  
  else if(memcmp(received_bytes, word_3_bytes, MAX_BYTE) == 0){
    Serial.println("매치된 바이트 데이터:");
    printBytes(word_3_bytes);
    Serial.println("입력된 글자는 word_3와(과) 일치합니다");
    digitalWrite(X2, LOW);
    delay(1000);
    digitalWrite(X2, HIGH);
  }
  else if(memcmp(received_bytes, word_4_bytes, MAX_BYTE) == 0){
    Serial.println("매치된 바이트 데이터:");
    printBytes(word_4_bytes);
    Serial.println("입력된 글자는 word_4와(과) 일치합니다");
    digitalWrite(X3, LOW);
    delay(1000);
    digitalWrite(X3, HIGH);
  }
  else if(memcmp(received_bytes, word_5_bytes, MAX_BYTE) == 0){
    Serial.println("매치된 바이트 데이터:");
    printBytes(word_5_bytes);
    Serial.println("입력된 글자는 word_5와(과) 일치합니다");
    digitalWrite(X4, LOW);
    delay(1000);
    digitalWrite(X4, HIGH);
  }
  else if(memcmp(received_bytes, word_6_bytes, MAX_BYTE) == 0){
    Serial.println("매치된 바이트 데이터:");
    printBytes(word_6_bytes);
    Serial.println("입력된 글자는 word_6와(과) 일치합니다");
    digitalWrite(X5, LOW);
    delay(1000);
    digitalWrite(X5, HIGH);
  }
  else if(memcmp(received_bytes, word_7_bytes, MAX_BYTE) == 0){
    Serial.println("매치된 바이트 데이터:");
    printBytes(word_7_bytes);
    Serial.println("입력된 글자는 word_7와(과) 일치합니다");
    digitalWrite(X6, LOW);
    delay(1000);
    digitalWrite(X6, HIGH);
  }
  else if(memcmp(received_bytes, word_8_bytes, MAX_BYTE) == 0){
    Serial.println("매치된 바이트 데이터:");
    printBytes(word_8_bytes);
    Serial.println("입력된 글자는 word_8와(과) 일치합니다");
    digitalWrite(X7, LOW);
    delay(1000);
    digitalWrite(X7, HIGH);
  }
}

// 이하 개발용 함수
void printBytes(byte text_bytes[]){
  for(int i=0; i<100; i++){
      Serial.print(text_bytes[i]);
      Serial.print(" ");
  }
  Serial.println("END");
}

void types(String a){Serial.println("it's a String");}
void types(int a)   {Serial.println("it's an int");}
void types(char* a) {Serial.println("it's a char*");}
void types(float a) {Serial.println("it's a float");} 
