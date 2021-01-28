#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27,16,2);

int valSol, btn=2, valBtn;

void setup() {
  lcd.begin(16,2);
  lcd.init();
  lcd.setBacklight(HIGH);

  pinMode(btn,INPUT_PULLUP);

  lcd.print("arduino multi");
  lcd.setCursor(0,1);
  lcd.print("fonction");
  delay(3000);
  lcd.clear();
}

void loop() { 
  Valeur = analogRead(A0);
  btnVal = digitalRead(btn);

  lcd.print(val);

  if (btnVal == 0){
    lcd.print("hello, world! my name is Ali Chbouki");
    delay(500);
    for(int i=0;i<21;i++){
      lcd.scrollDisplayLeft();
      delay(300);
    }
  }
  else if (btnVal == 1){}
}
