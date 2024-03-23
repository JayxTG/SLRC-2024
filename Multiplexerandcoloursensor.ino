#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <TCA9548.h>

// Create a TCA9548 object with the I2C address 0x70
TCA9548 multiplexer(0x70, &Wire);

// Create a TCS34725 object
Adafruit_TCS34725 colorSensor;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize the multiplexer
  multiplexer.begin();

  // Initialize the TCS34725 color sensor on channel 0
  multiplexer.selectChannel(0);

  // Check if the sensor is correctly connected
  if (colorSensor.begin()) {
    Serial.println("TCS34725 color sensor initialized and correctly connected!");
  } else {
    Serial.println("Failed to initialize TCS34725 color sensor!");
    while (1);
  }
}

void loop() {
  // Select the channel of the sensor
  multiplexer.selectChannel(0);

  // Read color values
  uint16_t red, green, blue, clear;
  colorSensor.getRawData(&red, &green, &blue, &clear);

  // Print color values
  Serial.print("Red: ");
  Serial.println(red);
  Serial.print("Green: ");
  Serial.println(green);
  Serial.print("Blue: ");
  Serial.println(blue);
  Serial.print("Clear: ");
  Serial.println(clear);

  delay(2000);
}