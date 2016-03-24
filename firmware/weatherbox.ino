/* File: weatherbox.ino 
   The main driver for the weatherbox
*/

/* Libraries */
#include "config.h"
#include "sensors.h"
#include "transmit.h"
#include "schema.h"

/* External Libraries */
#include <EEPROM.h>
#include <SHT1x.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_INA219.h>
#include <Adafruit_BMP085.h>
#include <HIH613x.h>
#include <XBee.h>health; 

/* Global Variables for PAcket */
uint8_t G_Packet[MAX_SIZE];
/*schema_health G_ */


/* Global Xbee object */
XBee G_xbee = XBee();

/* Global count variable */
 int G_count;

void setup() {
  
/* Variable Initiaization */
G_count = 0;

/* Transmission method check*/


/* Initialization */
sensor_init();
Serial.begin(9600);
G_xbee.begin(Serial); /*what is serial?*/

/* Set power state */

/*Packet Initialization */


}


void loop() {

 /* Check health and run appropriate routine */

      /* If voltages are good, operate normally */
  
      /* Else if voltages aren't good, operate in power saving mode */
}
