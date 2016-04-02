/*    File: routine.cpp */

/* Libraries */
#include "routine.h"

/* routine */
void routine(int *count)
{
    /* Variable Initialization */
    long wait_ms = 1000;
    unsigned long transmit_timer = millis();
    
    /* Poll sensors and construct packet */
    construct_Packet();

    /* Increment the poll count */
    (*count)++:

    /* Transmit after 3 polls */
    if((*count)>= 3)
    {
      transmit_Packet();
      clear_Packet();
      (*count) = 0;
      
    }

   /* Wait to ensure we poll exactly every second */
   whiile(millis() - transmit_timer) <= wait_ms);
  
}

