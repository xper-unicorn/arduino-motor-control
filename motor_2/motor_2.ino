#include <Servo.h>

Servo myservo_1;//Servoオブジェクトの宣言
Servo myservo_2;
String str;
String cmds[2] = {"\0"}; // 分割された文字列を格納する配列 
  
void setup() {
  Serial.begin(9600);
  myservo_1.attach(9);//servo変数をピンに割り当てる、ここでは9番ピン
  myservo_2.attach(10);
  myservo_1.write(0);//角度を指定
  myservo_2.write(0);
}


String serialRead(){
  // データ受信したとき
  if (Serial.available()>0) {
    str = Serial.readStringUntil('\n');
    return str;
  }
  return "NULL";
}

int split(String data, char delimiter, String *dst){
    int index = 0;
    int arraySize = (sizeof(data)/sizeof((data)[0]));  
    int datalength = data.length();
    for (int i = 0; i < datalength; i++) {
        char tmp = data.charAt(i);
        if ( tmp == delimiter ) {
            index++;
            if ( index > (arraySize - 1)) return -1;
        }
        else dst[index] += tmp;
    }
    return (index + 1);
}
 
void loop() {
    String cmd = serialRead();  
    if(cmd == "NULL");
    else{
      //Serial.println(cmd);
      int index = split(cmd, ',', cmds);
      if(index == 2){
      //Serial.println(index);
  // 結果表示    
        float fcmds_1 = cmds[0].toFloat();
        float fcmds_2 = cmds[1].toFloat();
     
        myservo_1.write(fcmds_1);
        myservo_2.write(fcmds_2);
        cmds[0] = '\0'; 
        cmds[1] = '\0';
             
        Serial.print("ok");//送信。
        //Serial.println(cmds[0]);
        //Serial.println(cmds[1]);
      }
      
    }
    
    //delay(1000); 
 // }
}
