
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages - I had to use the existing example sketch as a starting point
// as a fresh sketch refused to work ! Very odd.

// Implements a simplex tranciver with very cheap ook modules.

String inputString = "";         // a string to hold incoming data
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile
char msg[RH_ASK_MAX_MESSAGE_LEN];
int x = 0;
RH_ASK driver(2400, 11, 6, 5);
// RH_ASK driver(2000, 2, 4, 5); // ESP8266: do not use pin 11
unsigned long wait1 = 0;
void sendit() {
  //inputString.toCharArray(msg, inputString.length());
  driver.send((uint8_t *)msg, inputString.length());
    //driver.waitPacketSent();
     inputString = "";
     x = 0;
      //delay(200);
}

void setup()
{
    Serial.begin(2400);	  
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    
  //inputString = "h";
 if ( (wait1 + 10) < millis() ) {
  if ( inputString.length() > 0 ) { sendit(); } 
 
 }


//rx bit

uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
    {
	//int i; -- dunno why this was here ?
        //digitalWrite(rxlightpin, HIGH);
	// Message with a good checksum received, dump it.
	Serial.write(buf, buflen);
        //digitalWrite(rxlightpin, LOW);
        
    }


 
}

void serialEvent() {
  while (Serial.available()) { 
    if ( inputString.length() < RH_ASK_MAX_MESSAGE_LEN ) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    
    msg[inputString.length()] = inChar;
    
    inputString += inChar;
    
    }
    else
    {sendit();}
    }
    
    wait1 = millis();
    }
