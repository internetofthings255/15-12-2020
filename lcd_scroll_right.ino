/*programm: to print a string on lcd screen and to scroll right only 1st row*/

#include <LiquidCrystal.h>//initialize the lcd library files
//defined the pins to connect lcd to arduino
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
//creation of class and object
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
void setup()
{
  lcd.begin(16,2);//lcd gets begin
}
void lcdscrollright()//function used to scroll right
{
  for(int i=-7;i<16;i++)
  {
    for(int j=0;j<16;j++)
    {
      lcd.setCursor(j,0);//curser sets at jth column 0th row
      lcd.print(" ");
    }
  lcd.setCursor(i,0);
  lcd.print("BHASKAR");
  lcd.setCursor(0,1);//curser sets at 0th column 1st row
  lcd.print("english faculty");
  delay(200);
  }
  
}

void loop()
{
  lcdscrollright();//calls the scroll right function
}
