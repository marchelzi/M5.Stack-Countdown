#include <M5Stack.h>

int second;
int minute = 0;
void cdn()
{
  if (minute < 0){
      M5.Lcd.setCursor(0, 14);
      M5.Lcd.printf("Not Running \r\n");
    }
    else {
    for (second; second >= 0; second--) {
      delay(100);
       if (M5.BtnA.read() == 1){
        second = second;
        break;
      }else{
      M5.Lcd.setCursor(0, 14);
      M5.Lcd.printf("%0.2d mins %0.2d secs \r\n", minute, second);
      if (second == 0)
      {
        minute--;
        second = 59;
        M5.Speaker.beep();
      }
      else {
        M5.Speaker.mute();
      }
       if (minute == 0 == second) {
        M5.Speaker.beep();
        break;
      }
    }
    }
    }
}
void plusmin(){
    minute++;
    M5.Lcd.setCursor(0, 14);
    M5.Lcd.printf("%0.2d mins %0.2d secs \r\n", minute, second);
}
void minmin(){
   if (minute <= 0){
      M5.Lcd.setCursor(0, 14);
      M5.Lcd.printf("Can't Minus \r\n");
    }
    else{
    minute--;
    M5.Lcd.setCursor(0, 14);
    M5.Lcd.printf("%0.2d mins %0.2d secs \r\n", minute, second);
  }
}
void setup() {
  // Initialize the M5Stack object
  M5.begin();
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("Countdown Timer: \r\n");
  M5.Lcd.printf("%0.2d mins %0.2d secs \r\n", minute, second);
}

void loop() {
  if (M5.BtnA.wasReleasefor(1000)) {
    cdn();
  }
  if (M5.BtnB.wasPressed()) { 
   plusmin();
  }
  if (M5.BtnC.wasPressed()) {
  minmin();
  }

  M5.update();
}
