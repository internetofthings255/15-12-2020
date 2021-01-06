/*programm of  serial lighting setup as led number turn on based on number given in serialmonitor*/

void setup() {
  //configured the pins in arduino
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);//serial monitor gets initialize
}

void loop() {
 int value= Serial.parseInt();//reads the inpupt in serialmonitor and stores in "value"
 if(value==1)//led 1 on if value is 1
 {
  digitalWrite(2,1);
  digitalWrite(3,0);
  digitalWrite(4,0);
  Serial.print(" led 1 on ");
 }
 if(value==2)//led 2 on if value is 2
 {
  digitalWrite(3,1);
  digitalWrite(2,0);
  digitalWrite(4,0);
  Serial.println(" led 2 on ");
 }
 if(value==3)//led 3 on if value is 3
 {
  digitalWrite(4,1);
  digitalWrite(3,0);
  digitalWrite(2,0);
  Serial.println(" led 3 on ");
 }
 if(value==4)//all leds off if value is 4
 {
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(2,0);
 }
 if(value==5)//all leds on if value is 5
 {
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(2,1);
 }
}
