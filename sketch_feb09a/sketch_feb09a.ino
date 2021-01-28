#include <EEPROM.h>

int x;
int add;

void setup() {
  delay(15000);
  Serial.begin(9600);
}

void loop() {
  x=analogRead(A0);
  if (x<1020){EEPROM.write(add,x); add=add+2;}
  Serial.println(x);
  delay(3000);
}
