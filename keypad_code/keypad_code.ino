#include <Servo.h>
#include <Keypad.h>  //تذكر أن حجم اللوحة 4*4

char Keys[4][3] = {  //[Rows]  [Columns]
  {'#','0','*'},
  {'9','8','7'},
  {'6','5','4'},
  {'3','2','1'}};
byte RP[4] = {5,6,7,8};
byte CP[3] = {2,3,4};
Keypad KP=Keypad(makeKeymap(Keys),RP,CP,4,3); // تكوين الكائن
Servo moto;

int x1,x2,x3,x4;
int x;

void setup(){
  Serial.begin(9600);
  for (int i=10;i<13;i++){pinMode(i,OUTPUT);}
  while(x1==0){x1=KP.getKey();}
  while(x2==0){x2=KP.getKey();}
  while(x3==0){x3=KP.getKey();}
  while(x4==0){x4=KP.getKey();}
  x=x1*1000+x2*100+x3*10+x4;
  moto.attach(11);
}

void loop(){
  if (x==4587){
    moto.write(170);
    tone(12,450,250);
  }
  else {
    digitalWrite(10,1);
    tone(12,450,250);
    delay(250);
    digitalWrite(10,0);
    delay(250);
    moto.write(15);
  }
}
