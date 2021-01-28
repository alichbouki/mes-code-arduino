#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int codeF=000;

void setup(){
  lcd.begin(16,2);
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.clear();
  
  for (int i=10;i<14;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(7,INPUT_PULLUP);

  lcd.setCursor(0,0);
  lcd.print("arduino cofr for");
  lcd.setCursor(0,1);
  lcd.print("by ali chbouki");
  delay(5000);
  lcd.clear();
}

void loop(){
  int code1=analogRead(A0);
  int code2=analogRead(A1);
  int code3=analogRead(A2);
  int sw=digitalRead(7);

  code1=map(code1,0,1023,0,100);
  code2=map(code2,0,1023,0,100);
  code3=map(code3,0,1023,0,100);

  int codeR=code1+code2+code3;

  lcd.setCursor(0,0);
  lcd.print(code1);
  lcd.setCursor(1,0);
  lcd.print(code2);
  lcd.setCursor(2,0);
  lcd.print(code3);
  lcd.clear();

  if (sw==0){
    if (codeR==codeF){
      tone (10,350,1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("code corecte");
      for (int i=0;i<3;i++){
        digitalWrite(12,HIGH);
        delay(100);
        digitalWrite(12,LOW);
        delay(100);
      }
      digitalWrite(11,HIGH);
      delay(3000);
      digitalWrite(11,LOW);
      lcd.clear();
    }
    else if (codeR<codeF || codeR>codeF){
      tone (10,200,1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("code not corcte");
      for (int i=0;i<2;i++){
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
      }
    }
  }
  else if (sw==1){}
}
