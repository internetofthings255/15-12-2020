/*programm: to print data on both the rows of lcd and make them to scroll at different direction*/

#include <LiquidCrystal.h>//initilalize the lcd library file
//defined the pins connected lcd to the arduino
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
//creation of object and class
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
void setup()
{
  lcd.begin(16,2);//lcd gets initialize
}
void lcdscrollright()//function used to scroll led to right
{
  for(int i=-8;i<16;i++)
  {
    for(int j=0;j<16;j++)
    {
      lcd.setCursor(j,0);//curser sets at jth column 0th row
      lcd.print(" ");
    }
  lcd.setCursor(i,0);//curser sets at ith column 0th row
  lcd.print("BHASKAR");
  delay(150);
  }
  
}
void lcdscrollleft()//function used to scroll led to left
{
  for(int k=16;k>-15;k--)
  {
    for(int l=0;l<16;l++)
    {
      lcd.setCursor(l,1);//curser sets at lth column 1st row
      lcd.print(" ");
    }
  lcd.setCursor(k,1);
  lcd.print("ENGLISH FACULTY");//curser sets at kth column 1st row
  delay(200);
  }
  
}

void loop()
{
  lcdscrollright();//used to call led scroll right function
  delay(200);
  lcdscrollleft();//used to call led scroll left function
  delay(200);
}
