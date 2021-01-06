/*programm: to read the moisture vlaues using moisture sensor*/

void setup() {
 
pinMode(A0,INPUT);// using analog pin a0 reads sensor values

Serial.begin(9600);//serial monitor begins
}

void loop() {
  
  long value= analogRead(A0);//reads analog vlaues of sensor and stores in "value"
  Serial.println(value);//prints the moisture vlaues
  delay(1000);
}
