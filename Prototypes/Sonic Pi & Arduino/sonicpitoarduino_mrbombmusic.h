#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

const int NPots = 3;
int potPin[NPots] = {A0, A1, A2};

int potCState[NPots] = {0};
int potPState[NPots] = {0};
int potVar = 0;

int midiCState[NPots] = {0};
int midiPState[NPots] = {0};

int timeout = 300;
int varThreshold = 3;
boolean potMoving = true;
unsigned long pTime[NPots] = {0};
unsigned long timer[NPots] = {0};

byte midiCh = 1;
byte note = 36;
byte cc = 1;

void setup() {
Serial.begin(115200);

}

void loop() {

for (int i = 0; i < NPots; i++) {
  potCState[i] = analogRead(potPin[i]);
  midiCState[0] = map(potCState[0], 0, 1023, 0 , 44); //Mapped to Sample rate
  midiCState[1] = map(potCState[1], 0, 1023, 0 , 16); // Mapped to Bits
  midiCState[2] = map(potCState[2], 0, 1023, 0 , 127); // Mapped to Cutoff

  potVar = abs(potCState[i] - potPState[i]);

  if(potVar > varThreshold) {
pTime[i] = millis();
  }
  timer[i] = millis() - pTime[i];

  if(timer[i] < timeout) {
potMoving = true;
  }
  else {
potMoving = false;
  }
  if(potMoving == true) {
    if(midiPState[i] != midiCState[i]) {
    //  Serial.println(midiCState);
    MIDI.sendControlChange(cc + i, midiCState[i], midiCh + i);
      potPState[i] = potCState[i];
      midiPState[i] = midiCState[i];
    }
  }
}
}