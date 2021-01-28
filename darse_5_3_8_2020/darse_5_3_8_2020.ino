int red1=2;
int yellow1=3;
int green1=4;
int red2=5;
int yellow2=6;
int green2=7;

void setup() {
  pinMode(red1,OUTPUT);
  pinMode(yellow1,OUTPUT);
  pinMode(green1,OUTPUT);
  pinMode(red2,OUTPUT);
  pinMode(yellow2,OUTPUT);
  pinMode(green2,OUTPUT);
}

void loop() {
  digitalWrite(red1,HIGH);
  digitalWrite(yellow1,LOW);
  digitalWrite(green1,LOW);
  
  digitalWrite(red2,LOW);
  digitalWrite(yellow2,LOW);
  digitalWrite(green2,HIGH);

  delay(5000);

  digitalWrite(red1,HIGH);
  digitalWrite(yellow1,LOW);
  digitalWrite(green1,LOW);
  
  digitalWrite(red2,LOW);
  digitalWrite(yellow2,HIGH);
  digitalWrite(green2,LOW);

  delay(1000);

  digitalWrite(red1,LOW);
  digitalWrite(yellow1,LOW);
  digitalWrite(green1,HIGH);

  digitalWrite(red2,HIGH);
  digitalWrite(yellow2,LOW);
  digitalWrite(green2,LOW);

  delay(5000);

  digitalWrite(red1,LOW);
  digitalWrite(yellow1,HIGH);
  digitalWrite(green1,LOW);
  
  digitalWrite(red2,HIGH);
  digitalWrite(yellow2,LOW);
  digitalWrite(green2,LOW);

  delay(1000);
}
