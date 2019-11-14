#include <Servo.h>

Servo myservo_1;//Servoオブジェクトの宣言
Servo myservo_2;
char data[10];   // 文字列格納用
char data_2[10];   // 文字列格納用
int i = 0;  // 文字数のカウンタ

  
void setup() {
  Serial.begin(9600);
  //pinMode(13, OUTPUT);
  //digitalWrite(13, LOW);  //  初期化
  myservo_1.attach(9);//servo変数をピンに割り当てる、ここでは9番ピン
  myservo_2.attach(10);
  myservo_1.write(0);//角度を指定、ここでは90度
  myservo_2.write(0);
}

String serialRead(){
  // データ受信したとき
  if (Serial.available()) {
    // 1文字ずつ読み込み
    data[i] = Serial.read();
    // 文字数が10以上 or 終端文字なら終了
    if (i > 10 || data[i] == '\0') i = 0;
    else { i++; }
    if(data[0] == "S"){
      for(int j=0; j++; j<10) data_2[j] == data[j+1];
    }
  }
  return String(data_2);
}

void loop() {
  //if (Serial.available()){
    String cmd = serialRead();
    float fcmd = cmd.toFloat();
    Serial.print(fcmd);//送信。受信データをそのまま送り返す。
    myservo_1.write(fcmd);
    //myservo_2.write(fcmd);
    //delay(1000); 
 // }
}
