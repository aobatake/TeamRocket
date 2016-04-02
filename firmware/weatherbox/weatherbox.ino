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
#include <Adafruit_INA219.h>
#include <Adafruit_BMP085.h>
#include <XBee.h>
#include <EEPROM.h>

/* Global Variables for Packet */
uint8_t GPacket[MAX_SIZE];

/* Global Xbee object */
XBee Gxbee = XBee();

/* Global count variable */
 int G_count;

/* Global Function Pointers */
void (*sensor_inti)(void);
long (*sensorPressure)(void);
long (*sensorSolarIrrd)(void);
long (*sensorHumidity)(void);
long (*sensorRoofTempdecic)(void); 
long (*sensorBattery)(void);
long (*sensorPanel)(void); 
void (*packetClear)(void);
void (*packetConstruct)(void);
void (*pakcetTransmit)(void);



void setup() {
  
/* Variable Initiaization */
G_count = 0;

/* Transmission method check*/


/* Initialization */
sensor_init();
Serial.begin(9600);
Gxbee.begin(Serial); /*what is serial?*/

/* Set power state */

/*Packet Initialization */


}


void loop() {

 /* Check health and run appropriate routine */

      /* If voltages are good, operate normally */
  
      /* Else if voltages aren't good, operate in power saving mode */
}
