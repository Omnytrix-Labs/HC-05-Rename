#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);   // 10 pin RX | 11 pin to TX of bluetooth

void setup() 
{
  pinMode(9, OUTPUT);    // connect enable pin of bluetooth to 9 pin of arduino
  digitalWrite(9, HIGH); 
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);
}

void loop()
{
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  if (Serial.available())
    BTSerial.write(Serial.read());
}
