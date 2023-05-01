#include "Arduino.h"

#define BAUD_RATE     		9600
#define SERIAL_CONFIG		SERIAL_8N1
#define	SERIAL_TIME_OUT		1000

#define DEV_EC				0x1A		// Device End Character

#define VOL_MIN	        	0x00
#define VOL_MAX	        	0x4A		// 74
#define VOL_CALL			0x19		// 25

#define POWER_OFF			0x00
#define POWER_ON			0x01

class ONKYO
{
public:

ONKYO(HardwareSerial &serial);

int 	cmd(String);
uint8_t get_volume();
void 	volume(uint8_t);
void 	power(uint8_t);

private:

HardwareSerial* dev_serial;

};


