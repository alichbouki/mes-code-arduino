#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

char Keys[4][3] = {  //[Rows]  [Columns]
  {'#','0','*'},
  {'9','8','7'},
  {'6','5','4'},
  {'3','2','1'}};
byte RP[4] = {5,6,7,8};
byte CP[3] = {2,3,4};
int codeF=000;
int x1,x2,x3,x4;
int x;
int r=1947;

LiquidCrystal_I2C lcd(0x27,16,2);
Keypad KP=Keypad(makeKeymap(Keys),RP,CP,4,3);


void setup(){
  lcd.begin(16,2);
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.clear();
  
  for (int i=10;i<14;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(9,INPUT_PULLUP);

  lcd.setCursor(0,0);
  lcd.print("arduino cofr for");
  lcd.setCursor(0,1);
  lcd.print("by ali chbouki");
  delay(5000);
  lcd.clear();

  
}

void loop() {
  int sw=digitalRead(9);
  if (sw==0){
    while(x1==0){x1=KP.getKey();}
    x1=x1-48;
    while(x2==0){x2=KP.getKey();}
    x2=x2-48;
    while(x3==0){x3=KP.getKey();}
    x3=x3-48;
    while(x4==0){x4=KP.getKey();}
    x4=x4-48;
    x=x1*1000+x2*100+x3*10+x4;

    if (x==r){
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
    else if (x=!r){
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
  else if (sw==1){
    
  }
}
