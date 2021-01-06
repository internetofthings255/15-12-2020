/*programm: to connect the proximity infrared sensor(P.I.R) to arduino uno
 if motion detects the led gets on otherwise off
*/
void setup()
{
  pinMode(2,INPUT);//declaration of 2nd pin as input
  pinMode(13,OUTPUT);//declaration of 13th pin as output
  Serial.begin(9600);
}
void loop()
{
  int value=digitalRead(2);// reads the pir sensor values and stores in "value"
  if (value==0)
  {
    digitalWrite(13,0);//no motion detected so led off
    
  }
  if (value==1)
  {
    digitalWrite(13,1);//motion detected so led on
    Serial.println("person detected");
  }
  delay(200);
}
