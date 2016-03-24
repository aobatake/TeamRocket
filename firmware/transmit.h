/* File: Transmit.h */

/* Libraries */
#include "schema.h"
#include "config.h"
#include "sensors.h"

/* External Libraries */
#include <EEPROM.h>
#inlcude <XBee.h>

#define MAX_SIZE 100
/* Global Variable for Packet */
extern uint8_t Gpacket[MAX_SIZE];

/* Gloabal XBee object */
extern XBee Gxbee;

/* Check for previous includes */
#ifndef TRANSMIT_H
#define TRANSMIT_H

/* Clear Packet */
void clear_Packet(void);

/*Construct Packet */
void construct_Packet(void);

/* Transmit Packet */
void transmit_Packet(void);

#endif







