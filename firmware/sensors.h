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

long sensorHumidity(void);          /* Humidity Sensor */
long sensorHumidity_TempC(void);

long sensorTempdecic(void);         /* Temperature from pressure sensor */
long sensorRoofTempdecic(void);     /* Temperature from Temperature sensor*/          

long sensorBattery(void);
long sensorPanelmV(void)

