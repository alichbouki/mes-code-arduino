#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd (0x27,16,2);
IRrecv rec(7);               
decode_results res;

int tem,lingt,hal;
int water;
int x=0;
unsigned long du;
int trig=12,echo=13;

void setup() {
  lcd.begin(16,2);
  lcd.init();
  lcd.setBacklight(HIGH);
  rec.enableIRIn();
  
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

  Serial.begin(9600);
}

void loop() {
  if (rec.decode(&res)) {
    while (res.value == 0xFD4AB5){
      lingt=analogRead(A0);
      lingt=map(lingt,0,1023,0,100);
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("lingt:");
      lcd.setCursor(6,1);
      lcd.print(lingt);
      lcd.setCursor(10,1);
      lcd.print("%");
      delay(1000);
    }
    
    while (res.value == 0xFD0AF5) {
      tem=analogRead(A1);
      tem=map(tem,0,1023,0,100);
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("tem:");
      lcd.setCursor(6,1);
      lcd.print(tem);
      lcd.setCursor(10,1);
      lcd.print("%");
      delay(1000);
    }
    
    while (res.value == 0xFD08F7) {
      hal=analogRead(A2);
      hal=map(hal,0,1023,0,100);
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("hal:");
      lcd.setCursor(6,1);
      lcd.print(hal);
      lcd.setCursor(10,1);
      lcd.print("%");
      delay(1000);
    }   
    
    while (res.value == 0xFD6A95) {
      water=digitalRead(4);
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
      delay(1000);
    }
    
    while (res.value == 0xFD2AD5) {
      digitalWrite(trig,LOW);
      delay(2);
      digitalWrite(trig,HIGH);
      delayMicroseconds(2);
      digitalWrite(trig,LOW);
      du=pulseIn(echo,HIGH);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("distense time:");
      lcd.setCursor(0,1);
      lcd.print(du);
      delay(1000);
    } 
    Serial.println(res.value,HEX);
    rec.resume();
  }
}
