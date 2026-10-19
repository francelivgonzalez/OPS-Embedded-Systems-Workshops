\# Arduino Nano Simon Says Memory Game



This project recreates the Simon Says memory game using an Arduino Nano, four LEDs, and four push buttons.



\## Components

\- Arduino Nano

\- Four LEDs

\- Four current-limiting resistors

\- Four push buttons

\- Breadboard and jumper wires



\## How It Works

The Arduino generates a random sequence of LED flashes that the player has to repeat using the buttons. Each correct round adds another step to the sequence. If the player enters the wrong sequence, the LEDs flash and the game restarts.



The LEDs use pins D2 through D5, and the buttons use D6 through D9.



\## Code

\[simon\_says.ino](simon\_says.ino)





