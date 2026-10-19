\# Arduino Nano Infrared Tripwire Alarm



This project uses an infrared transmitter and receiver to create a tripwire security system. When something interrupts the infrared beam, the Arduino triggers an alarm.



\## Components

\- Arduino Nano

\- Infrared transmitter and break-beam receiver

\- Passive buzzer

\- LED and current-limiting resistor

\- Breadboard and jumper wires



\## How It Works

The infrared receiver is connected to D2, the buzzer to D9, and the LED to D8. The program monitors the receiver and activates the alarm when the beam is interrupted.



The code assumes the receiver outputs HIGH when the beam is interrupted.



\## Code

\[ir\_tripwire\_alarm.ino](ir\_tripwire\_alarm.ino)





