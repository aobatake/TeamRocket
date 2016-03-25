/* File: schema.h */

/* Schema from the SCEL website Kenny said to use this one */
typedef struct {
    uint16_t schema;
    uint16_t address;    // Address of Arduino 
    uint32_t uptime_ms;   // Time since start of program
    uint8_t  n;      // number of data points in packet 0..30
    uint16_t batt_mv[7]; // Battery Voltage (in milli volts)
    uint16_t panel_mv[7];  // Panel Voltage (in milli volts)
    uint32_t bmp085_press_pa; // Pressure Value (in pascals)
    uint16_t humidity_centi_pct; //Humidity Value
    uint16_t apogee_w_m2[35]; // Solar Irradiance Value
    int16_t dallas_roof_c[7];   //Outside temperature value (celcius)
} schema_1;

/* Struct for Health Check */
typedef struct {
  uint16_t schema;  //Schema ID number
  uint16_t address; //ADdress of Arduino
  uint32_t uptime_ms; //Time since the start of program
  uint16_t batt_mv; //Battery voltage (millivolts)
} schema_5;
