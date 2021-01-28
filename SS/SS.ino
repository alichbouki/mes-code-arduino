#include <SevSeg.h>
SevSeg ss;
void setup(){
  byte numDigits = 4;   
  byte digitPins[] = {2, 3, 4, 5};//مقاومة عند كل ديجيت بين
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  ss.begin(COMMON_ANODE, numDigits, digitPins,segmentPins);
  ss.setBrightness(10);} //هذا الأمر غير ضروري لمعظم الشاشاتvoid loop(){
  ss.setNumber(1234,3);  //should show 1.234
  ss.refreshDisplay();}  // Must run repeatedly;
