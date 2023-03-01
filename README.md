# ONKYO
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
|5|3.3V|||


Serial Port **NO** is 5V tolerant. If you have Arduino UNO, MEGA, etc use a **Logic Level Converter.**

|Serial settings||
|---|---|
|Baud rate|9600|
|Data|8 bit|
|Parity|N|
|Stop|1 bit|


Example of FCC connector as viewed from the back of the receivers.

<p align="center"><img src=/img/PORT9PIN.png></p>
