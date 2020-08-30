// Beispiel Sketch zur Bibliothek RelayModule
// Tobias Kuch 2020

#include <RelayModule.h>


RelayModule Relay;
void setup()
{
  Serial.begin(9600);
  bool InitOK = Relay.begin();
  if (InitOK)
    {
    Serial.println("Initalisierung OK");  
    } else
    {
    Serial.println("Initalisierung nicht OK. Module angeschlossen und richtig adressiert ?"); 
    }
}

void loop()
{
Relay.write(JD1,HIGH);
delay(1000);
Relay.write(JD2,HIGH);
delay(1000);
Relay.write(JD3,HIGH);
delay(1000);
Relay.write(JD4,HIGH);
delay(1000);
Relay.write(JD5,HIGH);
delay(1000);
Relay.write(JD6,HIGH);
delay(1000);
Relay.write(JD7,HIGH);
delay(1000);
Relay.write(JD8,HIGH);
delay(1000);
Relay.write(JD9,HIGH);
delay(1000);
Relay.write(JD10,HIGH);
delay(1000);
Relay.write(JD11,HIGH);
delay(1000);
Relay.write(JD12,HIGH);
delay(1000);
Relay.write(JD13,HIGH);
delay(1000);
Relay.write(JD14,HIGH);
delay(1000);
Relay.write(JD15,HIGH);
delay(1000);
Relay.write(JD16,HIGH);
delay(1000);
}