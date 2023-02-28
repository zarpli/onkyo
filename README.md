# Onkyo
Arduino control library for Integra/Onkyo AV receivers

<p align="center"><img src=/img/onkyo.jpg width="700"></p>

# FFC 1.0mm 9 pin Connector

Onkyo AV receivers have a 9-pin connector usually located on the back of the equipment, this connector is used to re-program the main microcontroller and also has a UART TTL serial communication at 3.3V.

The following table illustrates the pinout.

|Pin|Description|Pin|Description|
|---|---|---|---|
|1||6||
|2||7||
|3||8||
|4||9||
|5||||

Serial Port **NO** is 5V tolerant. If you have Arduino UNO, MEGA, etc use a **Logic Level Converter.**

|Serial settings||
|---|---|
|Baud rate|9600|
|Data|8 bit|
|Parity|N|
|Stop|1 bit|

Here is the FCC connector as viewed from the front of the Main Board.

<img src=/images/DE-15-M.jpg width="200">
