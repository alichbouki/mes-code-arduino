#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd (0x27, 16, 2);
IRrecv rec(7);            //la pate du lecteur IR
decode_results res;

#define tempin A1         //la pate du detecteur du temperature
#define lingtpin A0       //la pate du detecteur d'eclairage
#define halpin A2         //la pate du detecteur du chan magnitic
#define trig 2            //la pate trig de l'utra son
#define echo 3            //la pate echo de l'utra son
#define waterpin 4        //la pate du detecteur d'eau

int tem, lingt, hal;
int water;
int zap;
unsigned long du;  

void setup() {
  lcd.begin(16, 2);
  lcd.init();
  lcd.setBacklight(HIGH);
  rec.enableIRIn();

  pinMode(waterpin, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  lcd.print("arduino multi");
  lcd.setCursor(0, 1);
  lcd.print("fonction");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("by Ali Chbouki");
  delay(2000);
  lcd.clear();

  Serial.begin(9600);

}

void loop() {

  if (rec.decode(&res)) {

    if (res.value == 0xFD4AB5) {
      zap = 1;
    }
    if (res.value == 0xFD0AF5) {
      zap = 2;
    }
    if (res.value == 0xFD08F7) {
      zap = 3;
    }
    if (res.value == 0xFD6A95) {
      zap = 4;
    }
    if (res.value == 0xFD2AD5) {
      zap = 5;
    }
    
    Serial.println(res.value, HEX);
    rec.resume();
  }
  if (zap == 1) {
    lingt = analogRead(lingtpin);
    lingt = map(lingt, 0, 1023, 0, 100);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("lighting :");
    lcd.setCursor(6, 1);
    lcd.print(lingt);
    lcd.setCursor(10, 1);
    lcd.print("%");
    delay(500);
  }

  if (zap == 2) {
    tem = analogRead(tempin);
    tem = map(tem, 0, 1023, 0, 100);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("temperature:");
    lcd.setCursor(6, 1);
    lcd.print(tem);
    lcd.setCursor(10, 1);
    lcd.print("%");
    delay(500);
  }

  if (zap == 3) {
    hal = analogRead(halpin);
    hal = map(hal, 0, 1023, 0, 100);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Magnetic :");
    lcd.setCursor(6, 1);
    lcd.print(hal);
    lcd.setCursor(10, 1);
    lcd.print("%");
    delay(500);
  }

  if (zap == 4) {
    water = digitalRead(waterpin);
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("water:");
    if (water == 0) {
      lcd.setCursor(0, 1);
      lcd.print("water water!!");
    }
    else if (water == 1) {
      lcd.setCursor(0, 1);
      lcd.print("no water...!!");
    }
    delay(500);
  }

  if (zap == 5) {
    digitalWrite(trig, LOW);
    delay(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(2);
    digitalWrite(trig, LOW);
    du = pulseIn(echo, HIGH);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("distance time:");
    lcd.setCursor(0, 1);
    lcd.print(du);
    delay(500);
  }
}
