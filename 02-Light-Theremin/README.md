\# Arduino Nano Light-Controlled Theremin



This project uses a photoresistor to change the pitch of a speaker depending on the amount of light detected.



\## Components

\- Arduino Nano

\- Photoresistor (LDR)

\- 10kΩ resistor

\- Passive buzzer or piezo speaker

\- Breadboard and jumper wires



\## How It Works

The photoresistor is connected to A0, and the speaker is connected to D9. The Arduino reads the light level and uses `map()` to convert the sensor reading into a frequency between 200 and 2000 Hz. The `tone()` function generates the sound.



\## Code

\[light\_theremin.ino](light\_theremin.ino)





