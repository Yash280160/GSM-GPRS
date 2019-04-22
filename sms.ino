void setup() 
{
 Serial.begin(9600);

}

void loop() 

{
  Serial.print("ATE0");
  Serial.print("\r\r");
  Serial.println("AT+CMGF=1");
  delay(1000);
    Serial.println("AT+CMGS=\"+918349783108\"\r");//AT+CMGS="+918349783108"
    delay(1000);
    Serial.println("hello everybody");+
    Serial.print("\r\n");
    delay(1000);
    Serial.println((char)26); // Ascii code of CNT +Z
  
    delay(1000000);

}
