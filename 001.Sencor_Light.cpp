/**
  暗いところで光る列のライト
*/
// 光センサ検知の値
int val = 0;
// ターン用のフラグ
int check = 0;
// 点灯タイム
int const UP_TIME = 100;

void setup(){
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

}

void loop(){
  // 光センサの値を検知
  val = analogRead(0);
  // 光の明度を判定
  if (val < 50) {
    // 行き
    if (check == 0) {
      // 点灯
      for (int i = 2; i <= 8; i++) {
        digitalWrite(i, HIGH);
        delay(UP_TIME);
      }
      // 消灯
      for (int i = 2; i <= 8; i++) {
        digitalWrite(i, LOW);
        delay(UP_TIME);
      }
      // 行ったフラグを切り替える
      check = 1;
    } else {
      for (int i = 8; i >= 2; i--) {
        digitalWrite(i, HIGH);
        delay(UP_TIME);
      }
      for (int i = 8; i >= 2; i--) {
        digitalWrite(i, LOW);
        delay(UP_TIME);
      }
      check = 0;
    }
  }
}