#include <Servo.h>

Servo Right_1;//Servoオブジェクトの宣言
Servo Right_2;
Servo Left_1;
Servo Left_2;
String str;
String cmds[4] = {"\0"}; // 分割された文字列を格納する配列 
  
void setup() {
  Serial.begin(9600);
  Right_1.attach(9);//servo変数をピンに割り当てる、ここでは9番ピン
  Right_2.attach(10);
  Left_1.attach(11);
  Left_2.attach(12);
  Right_1.write(0);
  Right_2.write(0);
  Left_1.write(0);//角度を指定
  Left_2.write(0);
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
      if(index == 4){
      //Serial.println(index);
  // 結果表示    
        float fcmds_1 = cmds[0].toFloat();
        float fcmds_2 = cmds[1].toFloat();
        float fcmds_3 = cmds[2].toFloat();
        float fcmds_4 = cmds[3].toFloat();
        Right_1.write(fcmds_1);
        Right_2.write(fcmds_2);
        Left_1.write(fcmds_3);
        Left_2.write(fcmds_4);
        cmds[0] = '\0'; 
        cmds[1] = '\0';
        cmds[2] = '\0'; 
        cmds[3] = '\0'; 
               
        Serial.print("o");//送信。
        //Serial.println(cmds[0]);
        //Serial.println(cmds[1]);
      }
      
    }
    
    //delay(1000); 
 // }
}
