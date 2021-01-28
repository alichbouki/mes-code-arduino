#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27,16,2);

unsigned long x;    
int trig=2,echo=3;

void setup() {
  lcd.begin(16,2);
  lcd.init();
  lcd.setBacklight(HIGH);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  lcd.print("arduino regle");
  lcd.setCursor(0,1);
  lcd.print("bi ali chbouki");
  delay(3000);
  lcd.clear();
}

void loop() {
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  x=pulseIn(echo,HIGH);
  lcd.setCursor(0,0);
  lcd.print("la distanse est:");
  lcd.setCursor(0,1);
  lcd.print(x);
  delay(2000);
}
