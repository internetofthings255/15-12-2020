/*programm: using infrared sensor count the products */

void setup()
{
  //configuration of pins in arduino
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);//initialize the serial monitor
}
int count=0;
void loop()

{
  int value= digitalRead(2);//reads the sensor values
  
  if(value==0)
  {
    digitalWrite(13,1);//led on when detects an object
    delay(1000);
    count++;
  }
  if(value==1)
  {
    digitalWrite(13,0);//led off when doesnt detects the any object
    delay(1000);
  }
 Serial.println(count); //prints the count how many times object as detected
}
