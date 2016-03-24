/*  File: sensors.cpp
    Function definitions for sensors
*/

/* Libraries */
#include "sensors.h"
#include "config.h"

/* Set pins */
OneWire oneWire1(PIN_AMB_TEMP);                /* Temperature pins and objects */
DallasTemperature dallas_amb_sen(&oneWire1);
OneWire oneWire2(PIN_ROOF_TEMP);
DallasTemperature dallas_roof_sen(&oneWire2);

SHT1x sht1x(PIN_HUMID_DATA, PIN_HUMID_CLK);

Adafruit_BMP085 bmp085;                       /* Pressure object */
Adafruit_INA219 ina219_Solar;                 /* Solar Irrd object */


/* Initialization */
void sensors_init(void)
{
 bmp085.begin();
 ina219_Solar.begin();   
    
}

/* Humidity */
long sensorHumidity(void)
{
    long value =sht1x.readHumidity();
    return value;
}


/* Temperature from humidity sensor */
long sensorHumidity_TempC(void)
{
    long value = sht1x.readTemperatureC();
    return value;
}


/* Pressure */
long sensorPressure(void)
{
    long value =  bmp085.readPressure();
    return value; 
}

/* Temperature from Pressure sensor */
long sensorTempdecic(void)
{
    long value =  bmp085.readTemperature()*10;
    return value;
}

/* Temperature Sensor */
long sensorRoofTempdecic(void)
{
    long value =  0;
    dallas_roof_sen.requestTemperatures();
    value = dallas_roof_sen.getTempCByIndex(0)*10;
    return value;
}

/*Solar Irradiance */
long sensorSolarIrrd(void)
{
 long value = analogRead(PIN_APOGEE_V)*5000.0/1023;
 return value;
}

/*Battery */
long sensorBattery(void)
{
    long value = analogRead(PIN_BATT)*5000.0/1023;
    return value;
}

/* Solar Panel */
long sensorPanelmV(void)
{
    long value = 2*analogRead(PIN_SOLAR_V)*5000.0/1023;
    return value;
}



