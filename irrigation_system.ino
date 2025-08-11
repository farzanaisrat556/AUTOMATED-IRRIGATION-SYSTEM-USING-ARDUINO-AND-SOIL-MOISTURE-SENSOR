// Define the pin for the soil moisture sensor
const int sensorPin = A0;

// Define the pin for the relay (pump)
const int relayPin = 2; // Assuming pump is on pin 2

// Define the threshold values for soil moisture
// These values may need to be adjusted based on your sensor and environment
const int wetThreshold = 300; // Sensor value below this means soil is wet
const int dryThreshold = 700; // Sensor value above this means soil is dry

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);
  
  // Set the relay pin as an output
  pinMode(relayPin, OUTPUT);
  
  // Initially turn off the relay (pump)
  // This assumes an active-low relay, where HIGH turns it off
  digitalWrite(relayPin, HIGH); 
}

void loop() {
  // Read the soil moisture sensor value
  int sensorValue = analogRead(sensorPin);

  // Print the sensor value to the serial monitor for debugging
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  
  // Check moisture level and control the pump
  if (sensorValue <= wetThreshold) {
    // Soil is wet, no watering needed
    Serial.println("Soil is wet. Watering is not needed.");
    // Turn off the pump (assuming an active-low relay)
    digitalWrite(relayPin, HIGH); 
  } else if (sensorValue >= dryThreshold) {
    // Soil is dry, watering is needed
    Serial.println("Soil is dry. Watering is needed.");
    // Turn on the pump (assuming an active-low relay)
    digitalWrite(relayPin, LOW);
  } else {
    // Soil moisture is within the acceptable range
    Serial.println("Soil moisture is within the acceptable range.");
    // Turn off the pump
    digitalWrite(relayPin, HIGH);
  }
  
  // Add a short delay to avoid rapid readings and spamming the serial monitor
  delay(500); 
}
