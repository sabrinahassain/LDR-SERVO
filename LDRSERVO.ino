/* WHEN THE LDR DETECTS LIGHT, THE VALUE INCREASES AND THE SERVO MOTOR  MOVES*/ 

#include <Servo.h>

int ldrPin = A0;     // LDR connected to analog pin A0
int ldrValue = 0;     // Variable to store LDR value
Servo lightIndicator; // Create servo object

int servoPin = 9;    // Servo connected to pin 9

void setup() {
  // Initialize the servo
  lightIndicator.attach(servoPin);
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the value from the LDR (0 to 1023)
  ldrValue = analogRead(ldrPin);

  // Map the LDR value to a servo angle (0 to 180 degrees)
  int servoAngle = map(ldrValue, 0, 1023, 0, 180);

  // Set the servo position based on the LDR value
  lightIndicator.write(servoAngle);

  // Wait for a short period before reading again
  delay(100);
}
