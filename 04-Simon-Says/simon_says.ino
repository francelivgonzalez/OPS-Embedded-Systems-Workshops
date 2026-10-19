
/*Arduino Nano Simon Says Memory Game
 * OPS Embedded Systems Workshops
 *
 * Displays a sequence of LEDs that the player
 * must repeat using four push buttons.
 * Each successful round adds another step.
 */

// LED and button pins
const int ledPins[4] = {2, 3, 4, 5};
const int buttonPins[4] = {6, 7, 8, 9};

const int maxSequence = 50;
int sequence[maxSequence];

int sequenceLength = 1;

void setup() {
    Serial.begin(9600);

    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
        pinMode(buttonPins[i], INPUT_PULLUP);
    }

    // Generate different sequences between resets
    randomSeed(analogRead(A0));

    Serial.println("Simon Says Game Started!");
}

void loop() {
    // Add another random step to the sequence
    sequence[sequenceLength - 1] = random(0, 4);

    Serial.print("Round: ");
    Serial.println(sequenceLength);

    delay(1000);

    // Display the sequence
    for (int i = 0; i < sequenceLength; i++) {
        flashLED(sequence[i]);
        delay(300);
    }

    // Check the player's input
    bool correct = true;

    for (int i = 0; i < sequenceLength; i++) {
        int pressedButton = waitForButton();

        if (pressedButton != sequence[i]) {
            correct = false;
            break;
        }

        flashLED(pressedButton);
    }

    if (correct) {
        Serial.println("Correct! Next round.");
        delay(1000);

        if (sequenceLength < maxSequence) {
            sequenceLength++;
        } else {
            Serial.println("You completed all 50 rounds!");
            sequenceLength = 1;
            delay(2000);
        }
    } else {
        Serial.println("Wrong sequence! Game Over.");

        // Flash all LEDs three times
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < 4; i++) {
                digitalWrite(ledPins[i], HIGH);
            }

            delay(250);

            for (int i = 0; i < 4; i++) {
                digitalWrite(ledPins[i], LOW);
            }

            delay(250);
        }

        // Restart the game
        sequenceLength = 1;
        delay(1000);
    }
}

// Flash the selected LED
void flashLED(int index) {
    digitalWrite(ledPins[index], HIGH);
    delay(400);
    digitalWrite(ledPins[index], LOW);
}

// Wait until a player presses a button
int waitForButton() {
    while (true) {
        for (int i = 0; i < 4; i++) {
            if (digitalRead(buttonPins[i]) == LOW) {

                // Wait for the button to be released
                while (digitalRead(buttonPins[i]) == LOW) {
                    delay(10);
                }

                delay(30);
                return i;
            }
        }
    }
}
