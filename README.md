# Arduino MIDI Controller

This project is an Arduino-based MIDI controller that uses analog and digital inputs to send MIDI note signals. The code is designed to read input from analog and digital pins, mapped to specific MIDI notes.

## Hardware Requirements
- Arduino board (e.g., Uno, Nano, etc)
- Analog sensors connected to A0-A5
- Switches connected to pins 6 and 7

## Software Requirements
- [MIDI Library for Arduino](https://github.com/FortySevenEffects/arduino_midi_library)

  Optional (If you want to use your pc as midi player)
- [Hairless MIDI to Serial Bridge](https://projectgus.github.io/hairless-midiserial/)
- [loopMIDI](https://www.tobias-erichsen.de/software/loopmidi.html) (for creating virtual MIDI ports)
- ML Drums, or another drum plugins that support midi controller input

## Installation
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

Now, your Arduino will function as a MIDI controller, sending notes to your laptop’s MIDI player!

## Using Your Laptop as a MIDI Player
To use your laptop as a MIDI player and receive signals from the Arduino, follow these steps:

1. **Set Up Hairless MIDI to Serial Bridge**:
   - Download and install **Hairless MIDI to Serial Bridge**.
   - Open Hairless and select your Arduino’s COM port as the **Serial port**.
   - Set the **Baud rate** in Hairless to 115200 (to match the code).
   - Select your virtual MIDI port (created in loopMIDI) as the **MIDI Out**.

2. **Create a Virtual MIDI Port with loopMIDI**:
   - Download and install **loopMIDI**.
   - Open loopMIDI and create a new virtual MIDI port (e.g., name it "ArduinoMIDI").
   - Select this virtual port as the **MIDI Out** in Hairless.

3. **Configure Your MIDI Player Software**:
   - Open your MIDI player software or DAW (Digital Audio Workstation).
   - Set the input to the virtual MIDI port you created in loopMIDI (e.g., "ArduinoMIDI").
   - Your MIDI player software should now receive MIDI signals from the Arduino.
