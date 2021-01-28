#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Stepper.h>
#include <IRremote.h>

int spr = 64 ;

int ledR = 7, ledG = 6;

LiquidCrystal_I2C lcd (0x27, 16, 2);

Stepper moto (spr,  2, 4 , 3 , 5 );
IRrecv rec(9);
decode_results res;

void setup() {
  lcd.begin(16, 2);
  lcd.init();
  lcd.setBacklight(HIGH);
  moto.setSpeed(500);

  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  if (rec.decode(&res)) {
    if (res.value == 0xE318261B) {
      lcd.print("OPEN");

      digitalWrite(ledG, HIGH);
      digitalWrite(ledR, LOW);

      moto.step(10 * spr);
    }
    if (res.value == 0x73CE633) {
      lcd.print("CLOSE");

      digitalWrite(ledR, HIGH);
      digitalWrite(ledG, LOW);

      moto.step(-60 * spr);
    }
  }
}
