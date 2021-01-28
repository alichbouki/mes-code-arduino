#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Stepper.h>

int spr=64;
unsigned long x;    
int trig=3,echo=2;

Stepper moto (spr,8,10,9,11);
LiquidCrystal_I2C lcd (0x27 ,12,2);

void setup() {
  lcd.begin(16,2);
  lcd.init();
  lcd.setBacklight(HIGH);

  moto.setSpeed(100);

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,OUTPUT);
  pinMode(12,INPUT);
  pinMode(13,OUTPUT);

  lcd.setCursor(0,0);
  lcd.print("arduino sicur");
  lcd.setCursor(0,1);
  lcd.print("by ali chbouki");
  delay(3000);
  digitalWrite(5,HIGH);
}

void loop() {
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  x=pulseIn(echo,HIGH);
  
  int motion=digitalRead(6);
  int sw=digitalRead(12);
  int laz=analogRead(A0);

  if (motion==1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("motion detecter");
  }
  else if(motion==0){}

  while(laz<2000){panicMode();}
}

void panicMode(){
  
}
