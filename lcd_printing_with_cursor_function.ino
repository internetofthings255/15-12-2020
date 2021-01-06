/*programm: to print data on both rows in lcd using cursor function*/

#include <LiquidCrystal.h>//initialize the lcd library files
//defined the pins connected in lcd to arduino
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
//creation of class and object
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);//lcd gets begin
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);//curser sets at 0th column 0th row
lcd.print("KITTY IAS");
lcd.setCursor(9,1);//curser sets at 9th column 1st row
lcd.print("--*007*");
delay(300);
}
