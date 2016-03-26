/*******************************************
 *
 *    File: Transmit_Code.ino
 *    REIS Weatherbox Firmware
 *    
 *    Test .ino to check Transmission functions
 *
 ******************************************/

/* Program Libraries */
#include "transmit.h"
#include "config.h"

/* Arduino Libraries */
#include <EEPROM.h>

/* External Libraries */
#include <XBee.h>
#include <stdint.h>


/* Create Xbee Object */
XBee Gxbee = XBee();


schema_1 Gpacket;


/******************************************
 *
 *   Name:        setup
 *   Returns:     Nothing
 *   Parameter:   Nothing
 *   Description: Runs once at the start of the sequence.
 *                    Used for initialization. Place all
 *                    init scripts here.
 *
 *****************************************/
void setup(){

    /* Serial Initialization*/
    Serial.begin(9600);
    Gxbee.begin(Serial);


    pinMode(_PIN_XBEE_EN, OUTPUT);


    /* Packet initialization */

    clear_Packet();


    /* Generate a test packet */

    construct_Packet();

}

/******************************************
 *
 *   Name:        loop
 *   Returns:     Nothing
 *   Parameter:   Nothing
 *   Description: Main program function, runs constantly.
 *                    Executed after setup(), and will
 *                    continue running indefinitely,
 *                    unless conditions stop it.
 *
 *****************************************/
void loop(){

    /* Transmit the packet */

    transmit_Packet();

    /* Necessary delay to prevent overloading receiving end */
    delay(5000);
}
