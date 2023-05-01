#include "Arduino.h"

#define BAUD_RATE     		9600
#define SERIAL_CONFIG		SERIAL_8N1
#define	SERIAL_TIME_OUT		1000

#define DEV_EC				0x1A			//Device End Character

class ONKYO
{
public:

ONKYO(HardwareSerial &serial);

int 	cmd(String);

private:

HardwareSerial* dev_serial;

};


