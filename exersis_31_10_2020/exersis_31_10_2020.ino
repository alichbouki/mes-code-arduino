int x,y;

void setup() {
  Serial.begin(9600);
  for(int i=9;i<12;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  x=analogRead(A1);
  y=analogRead(A0);
  Serial.print(x);
  Serial.print("---");
  Serial.println(y);
  
}
