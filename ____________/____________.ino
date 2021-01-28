/*
red_led_serie_X = 2;
yelow_led_serie_X = 3;
green_led_serie_X = 4;

red_led_serie_Y = 5;
yelow_led_serie_Y = 6;
green_led_serie_Y = 7;
*/

int s;

void setup() {
  for (int i=2;i<8;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  s++;
  delay(10000);

  if (s=3){digitalWrite(2,HIGH);}
  else {digitalWrite(2,LOW);}

  if (s=2){digitalWrite(3,HIGH);}
  else {digitalWrite(3,LOW);}

  if (s=1){digitalWrite(4,HIGH);}
  else {digitalWrite(4,LOW);}

  if (s=1){digitalWrite(5,HIGH);}
  else {digitalWrite(5,LOW);}

  if (s=2){digitalWrite(6,HIGH);}
  else {digitalWrite(6,LOW);}

  if (s=3){digitalWrite(6,HIGH);}
  else {digitalWrite(6,LOW);}

  if (s>=3){s=0;}
  else {}
}
