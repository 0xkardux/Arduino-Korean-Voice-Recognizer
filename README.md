# Arduino-Korean-Voice-Recognizer
아두이노에서 한국어 음성인식을 가능하게 해주는 코드 스니핏입니다.

## 테스트된 어플
App name : Arduino Voice Control  
URL : https://play.google.com/store/apps/details?id=appinventor.ai_cempehlivan92.Arduino_Sesli_Kontrol&hl=ko

## 설명
**MAX_BYTE**  
MAX_BYTE를 통해서 최대 글자수를 설정할 수 있습니다. 다만 Arduino Uno의 경우 8개의 단어 사용시 메모리의 한계로 35의 MAX_BYTE에서 안정적입니다. 그 이상도 이론적으로 설정 가능하나 안정성은 테스트 되지 않았습니다.  
**동작원리**  
한글과 영어 단어를 String으로 정의한후 기본함수를 이용해 Byte배열로 변환합니다. 이후 App에서 블루투스 모듈(HC06)을 통해 음성 데이터를 보낼 때 저장된 바이트 배열과 수신된 바이트 배열을 비교해서 같을 경우 동작을 수행하는 Code Snippet입니다. 

