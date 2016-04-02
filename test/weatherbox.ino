/* File: weatherbox.ino 
   The main driver for the weatherbox
*/

/* Libraries */
#include "config.h"
#include "sensors.h"
#include "transmit.h"
#include "schema.h"

/* External Libraries */
#include <SHT1x.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_BMP085.h>
#include <XBee.h>
#include <EEPROM.h>

/* Global Variables for Packet */
uint8_t GPacket[MAX_SIZE];

/* Global Xbee object */
XBee Gxbee = XBee();

/* Global count variable */
int G_count;

void setup() {
/* Initialization */
sensor_init();
Serial.begin(9600);
Gxbee.begin(Serial); /*what is serial?*/

/*Packet Initialization */
clear_Packet();

}


void loop() {

  routine(&G_count);
}


