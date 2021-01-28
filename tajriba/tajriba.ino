int x;

void setup() {
  
  pinMode(3,OUTPUT);
  
  //Serial.begin(9600);
  
}

void loop() {
  
  x=analogRead(A0);
  
  //Serial.print(x);Serial.print("---");
  
  x=map(x,0,1023,0,255);
  
  analogWrite(3,x);
  
  //Serial.println(x);
}
