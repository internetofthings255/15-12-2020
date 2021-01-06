/*programm : to print the data on lcd and make them to scroll left*/

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
void lcdscrollleft()//function used to scroll the lcd left
{
  for(int i=16;i>-7;i--)
  {
    for(int j=0;j<16;j++)
    {
      lcd.setCursor(j,0);//curser sets at jth column 0th row
      lcd.print(" ");
    }
  lcd.setCursor(i,0);//curser sets at ith column 0th row
  lcd.print("BHASKAR");
  lcd.setCursor(0,1);//curser sets at 0th column 1st row
  lcd.print("satya sai");
  delay(200);
  }
  
}

void loop()
{
  lcdscrollleft();//calls the lcd scroll left function
}
