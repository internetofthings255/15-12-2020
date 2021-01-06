/*programm: leds get blink in an order as serial lighting serup*/

void setup() {
  //configuration of pins in arduino
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
Serial.begin(9600);//serial monitor begins
}

void loop() {
   for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
       for(int m=0;m<2;m++)
       {
      digitalWrite(2,i);
     
      digitalWrite(3,j);
       
      digitalWrite(4,m);
      //prints which light has turned on
       Serial.print(i);
       Serial.print(j);
       Serial.println(m);
      delay(500);
    }
  }
}
Serial.println("----------------------");
}
