# Arduino MIDI Controller

This project is an Arduino-based MIDI controller that uses analog and digital inputs to send MIDI note signals. The code is designed to read input from six analog pins and two digital pins, mapped to specific MIDI notes.

## Hardware Requirements
- Arduino board (e.g., Uno, Nano)
- Analog sensors connected to A0-A5
- Switches connected to pins 6 and 7

## Software Setup
1. Install the MIDI library in the Arduino IDE:
   - Go to `Sketch -> Include Library -> Manage Libraries`.
   - Search for `MIDI` and install.

2. Upload the code to your Arduino.

## Usage
Connect the analog sensors and switches as specified. The code reads sensor values and triggers MIDI notes when values exceed a certain threshold.

## Code Overview
- `triggerPin[]`: Defines the analog pins for input.
- `switchPin[]`: Defines the digital pins for switches.
- `midiMap[]`: Maps each input to a MIDI note.
- `fungsi()` and `fungsiDigital()`: Functions that check input and send MIDI messages.
