/* File: Transmit.cpp  */

/* Libraries */
#include "transmit.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*	Name:	clear_Packet
*	Returns:	Nothing
*	Description:
*	Clears/Init packet schema info
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * */
void clear_Packet(void) {
	
	/* Variables for indexes */
	int i,j;

	/* Clear/init values in packet */
	Gpacket.address = EEPROM.read(2) | (EEPROM.read(3) << 8);;
	Gpacket.uptime_ms = 0;
	Gpacket.n = 0;
	Gpacket.bmp085_press_pa = 0;
	Gpacket.bmp085_temp_decic = 0;
	Gpacket.humidity_centi_pct = 0;

	/* Clear/init values with multiple points */ 
	for(i = 0 ; i < 60; i++){

		j = i/4;

		/* Polled every 4 seconds */
		Gpacket.batt.mv[j] = 0;
		Gpacket.panel_mv[j] = 0;
		Gpacket.dallas_roof_c[j] = 0;

		/* Polled every second */
		Gpacket.apogee_w_m2[i] = 0;

	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*	Name: construct_Packet
*	Returns: Nothing
*	Description: Creates a packet with data from sensors.
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * */
void contruct_Packet(void) {
	
	/*index Variable */
	int n = Gpacket.n;
	
	/* Initialize  Sensor Variables */
 	long BatterymV = 0;
    long SolarIrrmV = 0;
    long SolarIrr_w_m2 = 0;
    long Humiditypct = 0;
    long PanelmV = 0;
    long Pressurepa = 0;
    long Tempdecic = 0;
    long Dallas_RoofTemp_c = 0;
    unsigned long uptime;


    /* Get Sensor Data */
 	BatterymV = sensorsBattery();
    PanelmV = sensorPanelmV();
    SolarIrrmV = sensorPressure();
    Humiditypct = sensorSolarIrrd();
    Pressurepa = sensorHumidity();
    Tempdecic = sensorRoofTempdecic();

    /*Update uptime */
    uptime = millis();
    Gpacket.uptime_ms = uptime;

    /* Pack power data */
    Gpacket.batt_mv[n/4] = BatterymV;
    Gpacket.panel_mv[n/4] = PanelmV;
    
    /* Pack sensor data */
    Gpacket.bmp085_press_pa = Pressurepa;
    Gpacket.humidity_centi_pct = Humiditypct;
    Gpacket.apogee_w_m2[n] = SolarIrrmV;
    G_BINpacket.dallas_roof_c[n/4] = Dallas_RoofTemp_c;

    /* Increment index */
    G_BINpacket.n += 1;

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
*	Name: transmit_Packet
*	Returns: Nothing
*	Description: Sends Packet using Xbbe arduino library
*				 ,sent as a binary packet.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * */
void transmit_Packet(void) {
    
    /* Enable XBee */
    digitalWrite(_PIN_XBEE_EN, HIGH);


    /* Variable to contain length */
    int len = 0;

    /* Obtain address of receiving end */
    XBeeAddress64 addr64 = XBeeAddress64(0,0);
    
    /* Packet to be transmitted */
    uint8_t payload[MAX_SIZE];

    /* Clear the payload */
    memset(payload, '\0', sizeof(payload));

    /* Obtain length of the packet */
    len = sizeof(G_BINpacket);

    /* Transfer information into payload */
    memcpy(payload, &G_BINpacket, len);

   /* Transfer the payload */
    ZBTxRequest zbTx = ZBTxRequest(addr64, payload, len);
    G_xbee.send(zbTx); //!!Prints packet to serial monitor

}