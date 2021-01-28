/*#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);*/

//************************//

int trig=3,echo=2;
long x;
int droit1=6,droit2=7,gauch1=8,gauch2=9;
int lup=12,ldo=11,br=10;
bool p;
String S;

//************************//

void setup() {
  Serial.begin(9600);
  
  pinMode(gauch1, OUTPUT);      
  pinMode(gauch2, OUTPUT);
  pinMode(droit2, OUTPUT);
  pinMode(droit1, OUTPUT); 
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(lup,OUTPUT);
  pinMode(ldo,OUTPUT);
  pinMode(br,OUTPUT);
    
  /*lcd.begin(16, 2);
  lcd.init();
  lcd.setBacklight(HIGH);

  lcd.setCursor(0,0);
  lcd.print("arduino car");
  lcd.setCursor(0, 1);
  lcd.print("by Ali Chbouki");
  delay(3000);
  lcd.clear();*/
}

//************************//

void loop() {
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  x=pulseIn(echo,HIGH);
  if (x<1000) {
    stope(droit2, droit1);stope(gauch1, gauch2);
    p=1;
  } 
  if (  ) {up(droit2, droit1);up(gauch1, gauch2);p=0;}
  if (  ) {up(droit2, droit1);stope(gauch1, gauch2);p=0;}         
  if (  ) {up(gauch1, gauch2);stope(droit2, droit1);p=0;}   
  if (  ) {down(droit2, droit1);down(gauch1, gauch2);p=0;
  if (  ) {stope(droit2, droit1);stope(gauch1, gauch2);p=1;} 
  if (  ){digitalWrite(lup,HIGH);digitalWrite(ldo,HIGH);}
  if (  ){digitalWrite(lup,HIGH);digitalWrite(ldo,LOW);}
  if (  ){digitalWrite(lup,LOW);digitalWrite(ldo,HIGH);}
  if (  ){digitalWrite(lup,LOW);digitalWrite(ldo,LOW);}
  
  if (p==0){digitalWrite(br,LOW);}
  else if (p==1){digitalWrite(br,HIGH);}
}

//************************//

void up(int out1, int out2){
  digitalWrite(out1, HIGH);
  digitalWrite(out2, LOW);
}

void down(int out1, int out2) { 
  digitalWrite(out1, LOW);
  digitalWrite(out2, HIGH);
}

void stope(int out1, int out2) {
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
}
