/* Use this copy */
/* File: sensors.ino */

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

    /* Variable Declarations */
    long BatterymV = -1;
    long SolarIrrmV = -1;
    long Humiditypct = -1;
    long PanelmV = -1;
    long Pressurepa = -1;
    long Tempdecic = -1;
    long RoofTempdecic = -1;

    /* Increase count */
    G_i++;











    

}
