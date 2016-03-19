/* Use this copy */
/*  File: sensors.cpp
    Function definitions for sensors
*/


/* Libraries */
#include "sensors.h"
#include "config.h"

/* Set pins */
OneWire oneWire1(_PIN_AMB_TEMP);                /* Temperature pins */
DallasTemperature dallas_amb_sen(&oneWire1);
OneWire oneWire2(_PIN_ROOF_TEMP);
DallasTemperature dallas_roof_sen(&oneWire2);
SHT1x sht1x(PIN_HUMID_DATA, PIN_HUMID_CLK);

Adafruit_BMP085 bmp085;                       /* Pressure pins */
Adafruit_INA219 ina219_Solar;                 /*   pins */




/* Initialization */
void sensors_init(void)
{
 bmp085.begin();
 ina219_Solar.begin();   
    
}


/*Temperature */

long sensorTempC(void)
{
  long value = Dallas.getTempC();
  return value;
}

long sensorTempF(void)
{
    long value = Dallas.getTempF();
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

long sensorHumidity_TempF(void)
{
    long value = sht1x.readTemperatureF();
    return value;
}


/* Pressure */

long sensorPressure(void)
{
    long value =  bmp085.readPressure();
    return value;
    
}


/*Battery */
long sensorBattery(void)
{
    long value = analogRead(PIN_BATT)*5000.0/1023;
    return value;
}


/*Solar Irradiance */
 Solar irradiance 
long sensorSolarIrrd(void)
{
 long value = analogRead(PIN_SOLAR_IRRA)*5000.0/1023;
 return value;
}

/* Solar Panel */
/*
long sensorPanelmV(void){
    long value = 2*analogRead(_PIN_SOLAR_V)*5000.0/1023;
    return value;
}
*/


