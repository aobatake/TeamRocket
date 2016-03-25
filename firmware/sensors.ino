/* File: sensors.ino */

/* Libraries */
#inlclude "sensors.h"
#include "config.h"

/* External Libraries */
#include <SHT1x.h>                  
#include <OneWire.h>                
#include <DallasTemperature.h>      
#include <Adafruit_BMP085.h>        
#include <Adafruit_INA219.h>    

/* Global Function Pointers */
void (*sensor_inti)(void);
long (*sensorPressure)(void);
long (*sensorSolarIrrd)(void);
long (*sensorHumidity)(void);
long (*sensorRoofTempdecic)(void); 
long (*sensorBattery)(void);
long (*sensorPanel)(void);   

/* Count for testing */
int G_i;

void setup() {
  /* initialize sensors */
  G_i = 0;
  sensorInit();

  /* Assign serial port */
  Serial.begin(9600);

}

void loop() {

    /* Variable Declarations & Initializations*/

    long SolarIrrmV = -1;
    long Humiditypct = -1;
    long Pressurepa = -1;
    long RoofTempdecic = -1;
    long PanelmV = -1;
    long BatterymV = -1;


    /* Increase count */
    G_i++;

    /* Get data for each sensor with a 1 second delay */
    SolarIrrdmv = sensorSolarIrrd();
    delay(1000);
    Humidity = sensorHumidity();
    delay(1000);
    RoofTempdecic = sensorRoofTempdecic();
    delay(1000);
    Pressurepa = sensorPressure();
    delay(1000);
    Panelmv = sensorPanel();
    delay(1000);
    Batterymv = sensorBattery();
    delay(1000); 


    /* Print data */
    Serial.print("-------Sensor Data Readings #");
    Serial.print(G_i);
    Serial.print("-------");

    Serial.print("\nSolarIrrmV Data:");
    Serial.println(SolarIrrmV);

    Serial.print("\nHumiditypct Data:");
    Serial.println(Humidity);

    Serial.print("\nPressurepa Data:");
    Serial.println(Pressurepa);
    
    Serial.print("\nRoofTempdecic Data:");
    Serial.println(RoofTempdecic);

    Serial.print("\nBatterymV Data:");
    Serial.println(BatterymV);

    Serial.print("\nPanelmV Data:");
    Serial.println(PanelmV);

}
