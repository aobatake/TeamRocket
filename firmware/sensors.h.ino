/*Use this copy */
/* File: sensors.h
   Header file for Sensor functions
*/


/* Libraries */
#include <SHT1x.h>                  /* Humidity Sensor */
#include <OneWire.h>                /*Temperature Sensor */
#include <DallasTemperature.h>      /* Temperature Sensor */
#include <Adafruit_BMP085.h>        /*Pressure Sensor */
#include <Adafruit_INA219.h>        /* solar irradiance */
#include <Arduino.h>                /* Arduino  */

/* Create instances of object */
extern OneWire oneWire1;
extern DallasTemperature dallas_amb_sen;

extern OneWire oneWire2;
extern DallasTemperature dallas_roof_sen;

extern SHT1x sht1x;

extern Adafruit_BMP085 bmp085;
extern Adafruit_INA219 ina219_Solar;



/*Initialization */
void sensors_init(void);

/* Retreiving the data */
long sensorPressure(void);
long sensorSolarIrrd(void);
long sensorHumidity(void);
long sensorHumidity_TempC(void);
long sensorHumidity_TempF(void);
long sensorTempC(void);
long sensorTempF(void);
long sensorBattery(void);
long sensorPanelmV(void)

