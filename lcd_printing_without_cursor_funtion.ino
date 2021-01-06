/*programm: to print the data on lcd screen*/

#include <LiquidCrystal.h>//lcd library files initialize
//defined pins connected on lcd to arduino
#define RS 2
#define E 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
//creation of class and object
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

void setup() {
  
lcd.begin(16,2);//lcd gets begin
}

void loop() {
  // put your main code here, to run repeatedly:

lcd.print("KITTY IAS");//prints the data
delay(300);
}
