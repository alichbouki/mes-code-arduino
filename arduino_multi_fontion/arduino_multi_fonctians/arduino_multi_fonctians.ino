#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27,16,2);

int tem,lingt,hal;
int water;
int x=0;
unsigned long du;
int trig=12,echo=13;

void setup() {
  lcd.begin(16,2);
  lcd.init();
  lcd.setBacklight(HIGH);
  
  pinMode(4,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
  lcd.print("arduino multi");
  lcd.setCursor(0,1);
  lcd.print("fonction");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("by Ali Chbouki");
  delay(2000);
  lcd.clear();
}

void loop() {
  lingt=analogRead(A0);
  tem=analogRead(A1);
  hal=analogRead(A2);
  
  water=digitalRead(4);
  
  lingt=map(lingt,0,1023,0,100);
  tem=map(tem,0,1023,0,100);
  hal=map(hal,0,1023,0,100);
  
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  du=pulseIn(echo,HIGH);
  
  if (x==0){
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("lingt:");
    lcd.setCursor(6,1);
    lcd.print(lingt);
    lcd.setCursor(10,1);
    lcd.print("%");
  }

  else if (x==1){
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("tem:");
    lcd.setCursor(6,1);
    lcd.print(tem);
    lcd.setCursor(10,1);
    lcd.print("%");
  }

  else if (x==2){
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("hal:");
    lcd.setCursor(6,1);
    lcd.print(hal);
    lcd.setCursor(10,1);
    lcd.print("%");
  }

  else if (x==3){
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("water:");
    if (water==0){
      lcd.setCursor(0,1);
      lcd.print("water water!!");
    }
    else if (water==1){
      lcd.setCursor(0,1);
      lcd.print("no water...!!");
    }
  }
  else if (x==4){
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("distense time:");
    lcd.setCursor(0,1);
    lcd.print(du);
  }
  else if (x>4){x=0;}
}
