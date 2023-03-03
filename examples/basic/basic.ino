/*
Zarpli - Tecnología Interactiva
01032023 Alejandro Zárate
https://github.com/zarpli/onkyo/

DESCRIPTION
====================
  
Basic example of the ONKYO library.
*/

#include <ONKYO.h>

// Instantiate a ONKYO object and Attach to Serial2
ONKYO TX_SR606(Serial2);

void setup(){

Serial.begin(9600);
while(!Serial);

Serial.println("TEST Onkyo Control Lybrary");

while(TX_SR606.cmd("PWRQSTN") == 0) // Gets the System Power Status
{
  // Power ON command
  TX_SR606.cmd("PWR01");

  Serial.println("Waiting TX-SR606 Power-Up");
  delay(1000);
}

// Select Input TAPE
TX_SR606.cmd("SLI20");

// Sets Master Volume to 48 (0x30)
TX_SR606.cmd("MVL30");

// Mute OFF command
TX_SR606.cmd("AMT00");
}

void loop(){

Serial.println("Current Volume : " + String(TX_SR606.cmd("MVLQSTN")));

delay(500);

}
