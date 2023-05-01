#include "Onkyo.h"

ONKYO::ONKYO(HardwareSerial &serial) {
    dev_serial = &serial;
	dev_serial->begin(BAUD_RATE,SERIAL_CONFIG);
}

int ONKYO::cmd(String cmd){
	
	dev_serial->print("!1" + cmd + "\r");

	unsigned long currentMillis = millis();
	
	while(dev_serial->available() == 0)
	if (millis() - currentMillis > SERIAL_TIME_OUT) return 0;

    String incoming_string = dev_serial->readStringUntil(DEV_EC).substring(5,7);
	
	return strtoul(incoming_string.c_str(), NULL, 16);
}

uint8_t ONKYO::get_volume()
{
    // flush serial input buffer
    while(dev_serial->available())dev_serial->read();
      
    dev_serial->print("!1MVLQSTN\r");

    unsigned long currentMillis = millis();
    while(dev_serial->available() == 0)
    if (millis() - currentMillis > SERIAL_TIME_OUT) return 0;

    String incoming_string = dev_serial->readStringUntil(DEV_EC).substring(5,7);
    return (uint8_t) strtoul(incoming_string.c_str(), NULL, 16);
}

void ONKYO::volume(uint8_t vol)
{
    char buffer[9];	
	
    sprintf(buffer,"!1MVL%02X\r", vol);
	
    dev_serial->print(buffer);
}

void ONKYO::power(uint8_t pow)
{
    char buffer[9];

    sprintf(buffer,"!1PWR%02X\r", pow);
	
    dev_serial->print(buffer);
}