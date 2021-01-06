/*programm: to blink leds continious*/

void setup() {
  // configure the pins in arduino
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
}

void loop() {
  for(int i=0;i<2;i++)
  {
    for(int j=0;j<2;j++)
    {
      digitalWrite(2,i);
      digitalWrite(3,j);
      delay(1000);
    }
 delay(500);
  }
  // put your main code here, to run repeatedly:

}
