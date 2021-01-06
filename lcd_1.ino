/*programm: to print a string or data on a lcd screen*/

#include <LiquidCrystal.h>//lcd library files
//defined the pins in lcd connected to pins in arduino uno
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
//creating class & object for lcd
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
void setup()
{
  lcd.begin(16,2);//lcd gets initialize
}
void loop()
{
  lcd.setCursor(0,0);//here the cursor places at 0th row & 0th column in lcd
  lcd.print("BHASKAR");
  lcd.setCursor(0,1);//here the cursor places at 1st row & 0th column in lcd
  lcd.print("satya sai");
  
}
