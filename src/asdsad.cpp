#include "ONKYO.h"

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
