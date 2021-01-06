/*programm: monitor the moisture values and control the motor according to moisture value */

void setup() {
  pinMode(A0,INPUT);//configure analog pin a0 as input
  pinMode(13,OUTPUT);//configure 13 pin as output
  Serial.begin(9600);
}

void loop() {
  long moisture = analogRead(A0);//reads the moisture value and stores in "moisture"
  Serial.println(moisture);//prints moisture
  if (moisture<=1000)
  {
    digitalWrite(13,0);
    Serial.println("motor off");//if moisture value less than equal to 1000 motor off
  }
  if (moisture> 1000)
  {
   digitalWrite(13,1);
    Serial.println("motor on");//if moisture value greater than to 1000 motor on
  }
  delay(2000);
}
