
/*Arduino Nano Light-Controlled Theremin
 * OPS Embedded Systems Workshops
 * Uses a photoresistor to detect changes in light.
 * Changes the pitch of a buzzer based on light intensity.
 */

// Pin assignments
const int lightSensor = A0;
const int buzzerPin = 9;

// Frequency range in Hz
const int minFrequency = 200;
const int maxFrequency = 2000;

void setup() {
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Read the light level
    int lightLevel = analogRead(lightSensor);

    // Convert light readings into sound frequencies
    int frequency = map(lightLevel, 0, 1023,
                        minFrequency, maxFrequency);

    // Play the corresponding frequency
    tone(buzzerPin, frequency);

    // Display readings for debugging
    Serial.print("Light Level: ");
    Serial.print(lightLevel);
    Serial.print(" | Frequency: ");
    Serial.println(frequency);

    delay(50);
}
