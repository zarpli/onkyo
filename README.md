# Onkyo
Control library for Integra/Onkyo AV receivers

<p align="center"><img src=/img/onkyo.jpg width="700"></p>

# FFC Non-ZIF 1.0mm 9 pin connector

Onkyo AV receivers have a 9-pin connector usually located on the back of the equipment, this connector is used to re-program the main microcontroller and also has a UART TTL serial communication at 3.3V.

<p align="center"><img src=/img/FCC1MM9PNZ.png width="500"></p>

The following table illustrates the pinout.

|Pin|Description|Pin|Description|
|---|---|---|---|
|1||6||
|2|GND|7|RXD|
|3|TXD|8||
|4||9||
|5|3.3V @ 20mA|||


Serial Port **NO** is 5V tolerant. If you have Arduino UNO, MEGA, etc use a **Logic Level Converter.**

|Serial settings||
|---|---|
|Baud rate|9600|
|Data|8 bit|
|Parity|N|
|Stop|1 bit|


Example of FCC connector as viewed from the back of the receivers.

<p align="center"><img src=/img/PORT9PIN.png></p>

# General commands

|command|argument|description|
|---|---|---|
|power|value [0-1]|power OFF or Power ON the unit|
|volume|value [0-255]|set the volume to value argument|
|get_volume|none|return current volume|

# ISCP commands

The commands are defined in the [ISCP](doc/ISCP_ONKYO_V115.pdf) specs document.

<p align="center"><img src=/img/ISCP.png width="500"></p>

example: "AMT" + "01" = "AMT01" sets audio muting on.

# Basic Example

```C++
#include <ONKYO.h>

// Instantiate a ONKYO object and Attach to Serial2
ONKYO TX_SR606(Serial2);

void setup(){

Serial.begin(9600);
while(!Serial);

Serial.println("TEST Onkyo Control Library");

while(TX_SR606.cmd("PWRQSTN") == 0) // Gets the System Power Status
{
  // Power ON command
  TX_SR606.cmd("PWR01");

  Serial.println("Waiting TX-SR606 Power-Up");
  delay(1000);
}

// Select Input TAPE
TX_SR606.cmd("SLI20");

// Sets Master Volume to 48
TX_SR606.volume(48);

// Mute OFF command
TX_SR606.cmd("AMT00");
}

void loop(){

Serial.println("Current Volume : " + (String) TX_SR606.get_volume());

delay(500);

}
```
# Use with Docklight

[Docklight](https://docklight.de/) is a testing, analysis and simulation tool for serial communication protocols.

Use the following project to use Onkyo receiver connected to a PC.

[onkyo.ptp](docklight/onkyo.ptp)

<img src=https://raw.githubusercontent.com/zarpli/onkyo/main/img/docklight.png>

# YouTube
<a href="https://www.youtube.com/watch?v=QVzbw9zAXnw" target="_blank"><img src="http://img.youtube.com/vi/QVzbw9zAXnw/0.jpg" alt="YouTube" width="400" border="10"/></a>

