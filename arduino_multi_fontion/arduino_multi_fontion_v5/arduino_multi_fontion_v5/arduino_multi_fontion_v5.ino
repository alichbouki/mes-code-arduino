#include <Wire.h>                   // }Inclure les libreuries
#include <LiquidCrystal_I2C.h>      //}


LiquidCrystal_I2C lcd (0x27, 16, 2);  //Difinire le constructor de la library I2C

int tem, lingt, hal, water;     //Definire les variable des valeur pour les valeurs
int waterPin = 3;               //Definire la pate de detection de l'eau

int btn1 = 1 /*your key*/, btn2 = 2 /*your key*/, btn3 = 3 /*your key*/, btn4 = 4 /*your key*/;        //Definire les Key des boutons, pour les conetres veuiller checker ce lien /home/ali-gamer/Arduino/arduino_multi_fontion/arduino_multi_fontion_v5/lir_IR_signal/lir_IR_signal.ino 

void setup() {
  lcd.begin(16, 2);               //}
  lcd.init();#include <IRremote.h>               //}                     // }Demarer la LCD I2C
  lcd.setBacklight(HIGH);         //}

  pinMode(waterPin, INPUT);         //Definire le fonctinemon de la pate du detecteure de l'eau

  lcd.print("arduino multi");           //}
  lcd.setCursor(0, 1);                  // }
  lcd.print("fonction");                //  }
  delay(3000);                          //   }
  lcd.clear();                          //    }L'afichage de proprieter du projer (du prototipe)
  lcd.setCursor(0, 0);                  //   }
  lcd.print("by Ali Chbouki");          //  }
  delay(2000);                          // }
  lcd.clear();                          //}

  Serial.begin(9600);         //Demarage du Serial moniteur
}

void loop() {
  int in = Serial.parseInt();
    
    while (in /*le in serial*/ == btn1) {
      lingt = analogRead(A0);
      lingt = map(lingt, 0, 1023, 0, 100);
      lcd.clear();  
      lcd.setCursor(5, 0);
      lcd.print("lingt:");
      lcd.setCursor(6, 1);
      lcd.print(lingt);
      lcd.setCursor(10, 1);
      lcd.print("%");
      delay(1000);
    }

    while (in /**/ == btn2) {
      tem = analogRead(A1);
      tem = map(tem, 0, 1023, 0, 100);
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("tem:");
      lcd.setCursor(6, 1);
      lcd.print(tem);
      lcd.setCursor(10, 1);
      lcd.print("%");
      delay(1000);
    }

    while (in /**/ == btn3) {
      hal = analogRead(A2);
      hal = map(hal, 0, 1023, 0, 100);
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("hal:");
      lcd.setCursor(6, 1);
      lcd.print(hal);
      lcd.setCursor(10, 1);
      lcd.print("%");
      delay(1000);
    }

    while (in /**/ == btn4) {
      water = digitalRead(4);
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
      delay(1000);
    }
}
