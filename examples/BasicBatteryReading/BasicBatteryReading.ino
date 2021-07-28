/**
 **************************************************
 *
 * @file        BasicBatteryReading.ino
 * @brief       This example is to show how BQ27441-G1 can be used for basic battery readings
 *
 *
 *
 * @authors     @ soldered.com, Robert Peric
 * @link        www.solde.red/333065
 ***************************************************/

#include "BQ27441-G1-SOLDERED.h"

BQ27441 battery;
const unsigned int BATTERY_CAPACITY = 1200; //Battery that I tested this with had 1200 mAh

void setup()
{
    Serial.begin(115200);

    // Use battery.begin() to initialize the BQ27441-G1A and confirm that it's
    // connected and communicating.
    if (!battery.begin()) // begin() will return true if communication is successful
    {
        // If communication fails, print an error message and loop forever.
        Serial.println("Error: Unable to communicate with BQ27441.");
        Serial.println("  Check wiring and try again.");
        while (1)
            ;
    }
    Serial.println("Connected to BQ27441!");

    // Uset battery.setCapacity(BATTERY_CAPACITY) to set the design capacity
    // of your battery.
    battery.setCapacity(BATTERY_CAPACITY);
}

void loop()
{
    // Read battery stats from the BQ27441-G1A
  unsigned int soc = battery.soc();  // Read state-of-charge (%)
  unsigned int volts = battery.voltage(); // Read battery voltage (mV)
  int current = battery.current(AVG); // Read average current (mA)
  unsigned int fullCapacity = battery.capacity(FULL); // Read full capacity (mAh)
  unsigned int capacity = battery.capacity(REMAIN); // Read remaining capacity (mAh)
  int power = battery.power(); // Read average power draw (mW)
  int health = battery.soh(); // Read state-of-health (%)

  // Now print out those values:
  String toPrint = String(soc) + "% | ";
  toPrint += String(volts) + " mV | ";
  toPrint += String(current) + " mA | ";
  toPrint += String(capacity) + " / ";
  toPrint += String(fullCapacity) + " mAh | ";
  toPrint += String(power) + " mW | ";
  toPrint += String(health) + "%";
  
  Serial.println(toPrint);

  delay(2000);
}
