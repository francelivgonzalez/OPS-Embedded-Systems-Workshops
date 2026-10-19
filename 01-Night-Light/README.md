\# Arduino Nano Automatic Night-Light



This project uses a photoresistor to detect changes in surrounding light. When the room gets dark, the Arduino turns on an LED. When enough light is detected, the LED turns off.



\## Components

\- Arduino Nano

\- Photoresistor (LDR)

\- LED

\- 10kΩ resistor

\- 220Ω resistor

\- Breadboard and jumper wires



\## How It Works

The photoresistor is connected to analog pin A0, and the LED is connected to digital pin D9. The program reads the sensor and compares its value to a threshold of 500 to determine whether the LED should be on or off.



\## Code

\[night\_light.ino](night\_light.ino)

