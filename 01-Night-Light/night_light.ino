
/* Arduino Nano Automatic Night-Light
 * OPS Embedded Systems Workshops
 * Uses a photoresistor to detect ambient light.
 * Turns an LED on when it gets dark and off when bright.
 */

const int lightSensor = A0;
const int ledPin = 9;
const int threshold = 500;

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int lightLevel = analogRead(lightSensor);

    Serial.print("Light Level: ");
    Serial.println(lightLevel);

    if (lightLevel < threshold) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }

    delay(200);
}