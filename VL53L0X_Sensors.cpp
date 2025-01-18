
#include "VL53L0X_Sensors.h"

// Create sensor objects
Adafruit_VL53L0X sensor1 = Adafruit_VL53L0X();
Adafruit_VL53L0X sensor2 = Adafruit_VL53L0X();
Adafruit_VL53L0X sensor3 = Adafruit_VL53L0X();

// Define XSHUT pins for each sensor
#define XSHUT1 19
#define XSHUT2 18
#define XSHUT3 13

void initializeSensors() {
    // Initialize XSHUT pins
    pinMode(XSHUT1, OUTPUT);
    pinMode(XSHUT2, OUTPUT);
    pinMode(XSHUT3, OUTPUT);

    // Put all sensors in shutdown mode
    digitalWrite(XSHUT1, LOW);
    digitalWrite(XSHUT2, LOW);
    digitalWrite(XSHUT3, LOW);

    delay(10);

    // Initialize sensor 1
    digitalWrite(XSHUT1, HIGH);  // Enable sensor 1
    delay(10);                   // Allow it to boot
    if (!sensor1.begin(0x30)) {  // Assign address 0x30
        Serial.println("Failed to initialize sensor 1!");
        while (1);
    }
    Serial.println("Sensor 1 initialized at 0x30");

    // Initialize sensor 2
    digitalWrite(XSHUT2, HIGH);  // Enable sensor 2
    delay(10);                   // Allow it to boot
    if (!sensor2.begin(0x31)) {  // Assign address 0x31
        Serial.println("Failed to initialize sensor 2!");
        while (1);
    }
    Serial.println("Sensor 2 initialized at 0x31");

    // Initialize sensor 3
    digitalWrite(XSHUT3, HIGH);  // Enable sensor 3
    delay(10);                   // Allow it to boot
    if (!sensor3.begin(0x32)) {  // Assign address 0x32
        Serial.println("Failed to initialize sensor 3!");
        while (1);
    }
    Serial.println("Sensor 3 initialized at 0x32");
}

void getSensorData() {
    VL53L0X_RangingMeasurementData_t measure;

    // Read sensor 1
    sensor1.rangingTest(&measure, false);
    Serial.print("Right sensor: ");
    if (measure.RangeStatus != 4) {
        Serial.print(measure.RangeMilliMeter);
    } else {
        Serial.print("Out of range");
    }
    Serial.println(" mm");

    // Read sensor 2
    sensor2.rangingTest(&measure, false);
    Serial.print("Left sensor: ");
    if (measure.RangeStatus != 4) {
        Serial.print(measure.RangeMilliMeter);
    } else {
        Serial.print("Out of range");
    }
    Serial.println(" mm");

    // Read sensor 3
    sensor3.rangingTest(&measure, false);
    Serial.print("Front sesnor: ");
    if (measure.RangeStatus != 4) {
        Serial.print(measure.RangeMilliMeter);
    } else {
        Serial.print("Out of range");
    }
    Serial.println(" mm");
}
