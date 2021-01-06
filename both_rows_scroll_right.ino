/*programm: to print the strings on both the rows of lcd and make them to scroll to right*/

#include <LiquidCrystal.h>//initialize the lcd library files
//defined the pins connected in lcd to arduino
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
//creation of class and object for lcd
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);
void setup()
{
  lcd.begin(16,2);//lcd starts beginning
}
void lcdscrollright()//function used to scroll the data to right
{
  int i,k;//initilalizing variables
  for(i=-7,k=-15;i<16,k<16;i++,k++)
  {
    for(int j=0;j<16;j++)
    {
      lcd.setCursor(j,0);//cursor sets at "j"th colulmn and 0th row
      lcd.print(" ");
      lcd.setCursor(j,1);//cursor sets at "j"th colulmn and 1st row
      lcd.print(" ");
      
    }
  lcd.setCursor(i,0);//cursor sets at "i"th colulmn and 0th row
  lcd.print("BHASKAR");
  lcd.setCursor(k,1);//cursor sets at "i"th colulmn and 1st row
  lcd.print("english faculty");
  delay(200);
  }
  
}

void loop()
{
  lcdscrollright();//calls the function of scrollright
}
