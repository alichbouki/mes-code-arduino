
/*
Author: Danny van den Brande, Arduinosensors.nl. BlueCore Tech.
Simple Temp and Humidity Sensor with the LCD 1602A.
You can also use the I2C for the LCD 1602A i 
already put the required Lines in the CODE.
All you need to do is find the right address for your I2C @ #define I2C_ADDR
in the code you can find the most used addresses.
 */
#include <Wire.h> // Uncomment when using the I2C!
#include <LiquidCrystal_I2C.h> //we use this when we are using a screen with a I2C
//Uncomment #include <LiquidCrystal_I2C.h>  and remove #include <LiquidCrystal.h> 
//if you are using a LCD 1602A with a I2C.
//#include <LiquidCrystal.h> 
#include <DHT.h> 

//i2C Addresses: PCF8574 = 0x20, PCF8574A = 0x38,PCF8574AT = 0x3F < the adresses for most used lcd 1602 Lcds.
//Uncomment all #define here below when using a I2C.
#define I2C_ADDR          0x3F   //<< I2C address look at the back of you I2C to see which on you have.
#define BACKLIGHT_PIN      3
#define En_pin             2
#define Rw_pin             1
#define Rs_pin             0
#define D4_pin             4
#define D5_pin             5
#define D6_pin             6
#define D7_pin             7


int DHT11Sensor = 7;
int DHT11value; 
#define DHTPIN A5
 
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);

//Uncomment the line LiquidCrystal_I2C and remove LiquidCrystal when using a I2C.  
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//<Remove when using the I2C.
LiquidCrystal_I2C      lcd(I2C_ADDR, En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin); //<<Uncomment when using the I2C.

byte degree[8] ={ B00001100,
                  B00010010,
                  B00010010,
                  B00001100,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,};
void setup()
{
Serial.begin(9600); 
lcd.begin(16,2); 
lcd.clear(); 
lcd.createChar(0, degree);
}
 
void loop()
{
float h = dht.readHumidity(); 
float t = dht.readTemperature(); 
lcd.setCursor(0,0);
lcd.print("Temp : ");
lcd.print(" ");
lcd.setCursor(7,0);
lcd.print(t,1);
lcd.setCursor(12,0);

lcd.write((byte)0);
//lcd.print((char)223);// Print degree symbol.
 
lcd.setCursor(0,1);
lcd.print("Humid: ");
lcd.print(" ");
lcd.setCursor(7,1);
lcd.print(h,1);
lcd.setCursor(12,1);
lcd.print("%");
 
delay(2000);
}
