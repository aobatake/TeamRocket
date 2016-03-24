/* File: schema.h */

/* Schema from the SCEL website Kenny said to use this one */
typedef struct {
    uint16_t schema;
    uint16_t address;    // Address of Arduino 
    uint32_t uptime_ms;   // Time since start of program
    uint8_t  n;      // number of data points in packet 0..30
    uint16_t batt_mv[15]; // Battery Voltage (in milli volts)
    uint16_t panel_mv[15];  // Panel Voltage (in milli volts)
    uint32_t bmp085_press_pa; // Pressure Value (in pascals)
    int16_t bmp085_temp_decic;  // Temperature Value (in celsius)
    uint16_t humidity_centi_pct;
    uint16_t apogee_w_m2[60];
} schema_1;

/* Schema that include two temperatures */
/*
typedef struct {
    uint16_t schema = 2;     //Schema ID number
    uint16_t address;        //Address of Arduino
    uint32_t uptime_ms;      //Time since the start of program
    uint8_t overflow_num;    //Number of times function millis() overflowed
    uint8_t n;               //Number of data points in packet (0...30)
    uint16_t batt_mv[15];    //Battery voltage (millivolts)
    uint16_t panel_mv[15];   //Panel voltage (millivolts)
    uint32_t bmp085_press_pa;  //Pressure value (pascals)
    int16_t bmp085_temp_decic;   //Temperature value (celsius)
    uint16_t humidity_centi_pct; //Humidity value (centi-pascals)
    uint16_t apogee_w_m2[60];    //Solar Irradiance (millivolts)
    int16_t dallas_roof_c[15];   //Outside temperature value (celcius)
} schema_2;
*/


/* Struct for Health Check */
typedef struct {
  uint16_t schema;  //Schema ID number
  uint16_t address; //ADdress of Arduino
  uint32_t uptime_ms; //Time since the start of program
  uint16_t batt_mv; //Battery voltage (millivolts)
} schema_5;
