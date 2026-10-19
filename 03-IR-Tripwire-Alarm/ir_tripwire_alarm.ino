
/*Arduino Nano Infrared Tripwire Alarm
 * OPS Embedded Systems Workshops
 *
 * Monitors an infrared beam between a transmitter
 * and receiver. When the beam is interrupted,
 * a buzzer and LED are activated.
 */

// Pin assignments
const int irReceiver = 2;
const int buzzerPin = 9;
const int ledPin = 8;

void setup() {
    pinMode(irReceiver, INPUT_PULLUP);
    pinMode(buzzerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    // Read the infrared receiver
    int beamState = digitalRead(irReceiver);

    // LOW means the beam is detected for this setup
    // HIGH means the beam has been interrupted
    if (beamState == HIGH) {
        digitalWrite(ledPin, HIGH);
        tone(buzzerPin, 1000);

        Serial.println("ALERT: Tripwire triggered!");
    } else {
        digitalWrite(ledPin, LOW);
        noTone(buzzerPin);

        Serial.println("Beam detected. System armed.");
    }

    delay(100);
}
