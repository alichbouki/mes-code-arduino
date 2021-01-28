/***********

arduino car wid ir remote consicte avoir une voiture et de la controler avec une télécomande.
La voiture peux avoir une posibiliter de s'areter devon un obstacle avec un module ultra sont.

NB1 : tous qui est écrit devon lui de "uls",c'est pour l'ultara sons.
NB2 : je vais vous laisser le code de lire le code du la télécomande pour changer les codes d'aprer la votre

écrit par ALI CHBOUKI le 9/2/2020

************/

/*************************************/
/*                                   */
/*         les lébreuris             */
/*                                   */
/*************************************/

#include <IRremote.h>        //l'activation de la lébreuri de "IRremote"

IRrecv rec(4);               
decode_results res;

/************************************/
/*                                  */
/*         les variable             */
/*                                  */
/************************************/

int trig=3,echo=2,sp=11,x;   //uls 

int droit1=6,droit2=7,gauch1=8,gauch2=9;    //vous pouvais changer les pors des votre besoin

/*************************************/
/*                                   */
/*         le void sutup             */
/*                                   */
/*************************************/

void setup() {
  pinMode(gauch1, OUTPUT);      //idontifier que les pors utiliser sont des OUTPUT
  pinMode(gauch2, OUTPUT);      //idontifier que les pors utiliser sont des OUTPUT
  pinMode(droit2, OUTPUT);      //idontifier que les pors utiliser sont des OUTPUT
  pinMode(droit1, OUTPUT);      //idontifier que les pors utiliser sont des OUTPUT
  pinMode(trig,OUTPUT);         //uls
  pinMode(echo,INPUT);          //uls
  rec.enableIRIn();             //c'est pour la lébreuri
}

/************************************/
/*                                  */
/*         le void loop             */
/*                                  */
/************************************/

void loop() {
  digitalWrite(trig,LOW);    //uls
  delay(2);                  //uls
  digitalWrite(trig,HIGH);   //uls
  delayMicroseconds(2);      //uls
  digitalWrite(trig,LOW);    //uls
  x=pulseIn(echo,HIGH);      //uls
  if (rec.decode(&res)) {                                                            //prandre le code qui vins du la télécomande et le décoder
    if (res.value == 0xFD609F) {up(droit2, droit1);up(gauch1, gauch2);}              //vous pouvais changer les code des votre télécomande
    if (res.value == 0xFD5AA5) {up(droit2, droit1);stope(gauch1, gauch2);}           //vous pouvais changer les code des votre télécomande
    if (res.value == 0xFDD827) {up(gauch1, gauch2);stope(droit2, droit1);}           //vous pouvais changer les code des votre télécomande
    if (res.value == 0xFD689) {down(droit2, droit1);down(gauch1, gauch2);}           //vous pouvais changer les code des votre télécomande
    if (res.value == 0xFD58A7) {stope(droit2, droit1);stope(gauch1, gauch2);}        //vous pouvais changer les code des votre télécomande
    rec.resume();                                                                    //c'est pour la lébreuri
  }
  if (x<1000) {stope(droit2, droit1);stope(gauch1, gauch2);}       //uls
}

/*********************************************/
/*                                           */
/*           les fonction utiliser           */
/*                                           */
/*********************************************/

void up(int out1, int out2){            //cette fonction ser a bouger les rous d'une coter vair l'avant
  digitalWrite(out1, HIGH);
  digitalWrite(out2, LOW);
}

void down(int out1, int out2) {         //cette fonction ser a bouger les rous d'une coter vair l'arier
  digitalWrite(out1, LOW);
  digitalWrite(out2, HIGH);
}

void stope(int out1, int out2) {        //cette fonction ser a fair areter les rous d'une coter de bouger
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
}

/****************************************************************/
/*                                                              */
/*           le code de lire le signal du télécomande           */
/*                                                              */
/****************************************************************/

/*
#include <IRremote.h> 
IRrecv recv(3);    
decode_results res;

void setup() {
  Serial.begin(9600);
  recv.enableIRIn();
}

void loop() {
  if (recv.decode(&res)) {
    Serial.println(res.value, HEX);
    recv.resume();}
  delay(100);
}
*/
