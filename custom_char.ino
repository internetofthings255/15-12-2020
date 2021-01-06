/*programm: to print a custom charactor(symbol) in lcd screen*/

#include <LiquidCrystal.h>//initializing lcd libraries
//defined the pins connected in lcd to arduino
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
//creation of class and object
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
//created a function to call entire custom characters binary code
byte customChar[] = {  
  B00110,
  B00110,
  B00110,
  B11111,
  B11111,
  B00110,
  B00110,
  B00110
};
byte customChar1[] = {
  B01110,
  B10001,
  B10001,
  B00100,
  B01110,
  B11111,
  B01110,
  B00100
};


void setup()
{
  lcd.begin(16,2);//lcd starts initializing
  lcd.createChar(0, customChar);//sets the custom charactor 1
  lcd.createChar(1, customChar1);//sets the custom charactor 2
}
void loop()
{
  lcd.setCursor(8,0);//cursor sets at 8th column 0th row
  lcd.write((byte)0);//prints the custom charactor 1
  delay(200);
  lcd.setCursor(10,1);//cursor sets at 10th column 1st row
  lcd.write((byte)1);//prints the custom charactor 2
  
}
