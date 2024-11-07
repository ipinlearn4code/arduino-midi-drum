#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

unsigned long previousTime = 0;
const int interval = 1000;  // Waktu dalam milidetik, contoh: 1000ms (1 detik)


short triggerAmmounts = 6;
const int triggerPin[] = { A0, A1, A2, A3, A4, A5 };
int triggerValue[] = { 0, 0, 0, 0, 0, 0 };

short switchAmmounts = 2;
const int switchPin[] = { 6, 7 };

int midiMap[] = { 46, 38, 49, 61, 52, 43, 42, 36, 44 };  //KICK 36
bool isUsed[8];

int threshold = 10;

void setup() {
  Serial.begin(115200);
  for (short i = 0; i < triggerAmmounts + switchAmmounts; i++) {
    isUsed[i] = false;
  }
}

void loop() {
  for (short i = 0; i < triggerAmmounts; i++) {
    triggerValue[i] = analogRead(triggerPin[i]);
    isUsed[i] = fungsi(midiMap[i], triggerValue[i], isUsed[i]);
  }
  for (short i = 0; i < switchAmmounts; i++) {
    int dmap = i + 6;
    isUsed[dmap] = fungsiDigital(midiMap[dmap], digitalRead(switchPin[i]), isUsed[dmap]);
  }
}


boolean fungsi(int map, int value, bool isused) {
  if (map == 46 && isUsed[6]) {
    map = 66;
  }
  if (value > threshold) {
    if (!isused) {
      MIDI.sendNoteOn(map, value, 10);
      return true;
    } else {
      return true;
    }
  } else {
    return false;
  }
}

boolean fungsiDigital(int map, int con, bool isused) {
  if (con == 1) {
    if (!isused) {
      MIDI.sendNoteOn(map, 100, 10);
      return true;
    } else {
      return true;
    }
  } else {
    return false;
  }
}