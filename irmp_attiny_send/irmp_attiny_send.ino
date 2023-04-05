#include <Arduino.h>
#define SEND_NEC
#include "PinDefinitionsAndMore.h"
//#define IR_OUTPUT_IS_ACTIVE_LOW
#define IRSND_IR_FREQUENCY          38000
#define IRSND_PROTOCOL_NAMES        1 // Enable protocol number mapping to protocol strings - requires some FLASH.
#define IRSND_SUPPORT_NEC_PROTOCOL        1

#include <irsnd.hpp>

IRMP_DATA irsnd_data;

void setup() {

    irsnd_init();
    irsnd_data.protocol = IRMP_NEC_PROTOCOL;
    irsnd_data.address = 0x08AA;
    irsnd_data.command = 0xF7; 
    irsnd_data.flags = 2; 

}

void loop() 
{
    irsnd_send_data(&irsnd_data, true);
    delay(10);
}
