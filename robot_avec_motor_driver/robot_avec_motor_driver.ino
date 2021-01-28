/*#include <IRremote.h>
IRrecv rec(2);  //here put receiver pin
decode_results res;
int x,y;

void setup() {
  for(int i=6;i<10;i++){pinMode(i,OUTPUT);}
  Serial.begin(9600);
  rec.enableIRIn();
  moto(6,1,7,0,8,1,9,0,5000);
}

void loop() {
  /*if (rec.decode(&res)){
    if(res.value==0xFD609F){
      moto(6,1,7,0,8,0,9,1,);
    }
    if(res.value==0xFD5AA5){
      moto(6,0,7,1,8,0,9,0);
    }
    if(res.value==0xFDD827){
      moto(6,0,7,0,8,1,9,0);
    }
    if(res.value==0xFD6897){
      moto(6,0,7,1,8,1,9,0);
    }
    if(res.value==0xFD58A7){
      moto(6,0,7,1,8,0,9,0);
    }
    Serial.println(res.value, HEX);
    rec.resume(); 
  }  
  /*x=analogRead(A0);
  y=analogRead(A1);
  if (x<=40){moto(6,0,7,1,8,0,9,1);}
  else if (x>=1000){moto(6,1,7,0,8,1,9,0);}
  if (y<=40){moto(6,0,7,1,8,1,9,0);}
  else if (y>=1000){moto(6,1,7,0,8,0,9,1);}
  
}



void moto(int out1, bool v1, int out2, bool v2, int out3, bool v3, int out4, bool v4, int d) {
  digitalWrite(6,v1);
  digitalWrite(7,v2);
  digitalWrite(8,v3);
  digitalWrite(9,v4);
  delay(d);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
  digitalWrite(9,0);
}*/

void setup(){
  
}
void loop(){
  
}
