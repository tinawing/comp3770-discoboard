#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// declaring pins
const int echoPin = 9;
const int trigPin = 8;
const int Buzz = 11;

// declaring MIDI stuff
// MIDI.sendControlChange takes 3 values: ControlNumber, MIDI value, Channel
// Guessing midiCN and midiCh values for now
byte midiCN = 1;
byte midiVal = 0;
byte midiCh = 1;

byte prevVal = 0;

// MIDI instead of frequency values
int c4 = 60;                                  // middle C
int c4_d4 = 61;
int d4 = 62;
int d4_e4 = 63;
int e4 = 64;
int f4 = 65;
int f4_g4 = 66;
int g4 = 67;
int g4_a4 = 68;
int a4 = 69;
int a4_b4 = 70;
int b4 = 71;
int c5 = 72;
int c5_d5 = 73;
int d5 = 74;
int d5_e5 = 75;
int e5 = 76;
int f5 = 77;
int f5_g5 = 78;
int g5 = 79;
int g5_a5 = 80;
int a5 = 81;
int a5_b5 = 82;
int b5 = 83;
int c6 = 84;
int notes[] = {c4, c4_d4, d4, d4_e4, e4, f4, f4_g4, g4, g4_a4, a4, a4_b4, b4, c5, c5_d5, d5, d5_e5, e5, f5, f5_g5, g5, g5_a5, a5, a5_b5, b5, c6};       // array storing all notes

long duration, distance;

void updateValues(int i) {
  prevVal = midiVal;
  midiVal = notes[i];
  Serial.print("Midi value: ");
  Serial.println(midiVal);
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(Buzz, OUTPUT);

  MIDI.begin();
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);                 // init -- clearing trig pin
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);                // sending out ultrasonic signal
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin,HIGH);           // catch the signal from the echo pin when it arrives

  Serial.print("Duration: ");
  Serial.println(duration);
  
  distance = (duration/2)/29.1;               // formula for converting time into distance (cm)
                                              // using speed of sound = 340 m/s

  Serial.print("Distance: ");
  Serial.println(distance);                   // println prints thing in brackets and adds new line

  // instead of tone directly, change the midi value
  if (distance >= 4 && distance <= 63)
  {
    if (distance >= 4 && distance <= 5)      //C4 (middle C)
        updateValues(0);
    else if (distance >= 6 && distance <= 7) //C4_D4
        updateValues(1);          
    else if (distance >= 8 && distance <= 9) //D4
        updateValues(2);              
    else if (distance >= 10 && distance <= 11) //D4_E4
        updateValues(3);                
    else if (distance >= 12 && distance <= 15) //E4
        updateValues(4);            
    else if (distance >= 16 && distance <= 17) //F4
        updateValues(5);                
    else if (distance >= 18 && distance <= 19) //F4_G4
        updateValues(6);               
    else if (distance >= 20 && distance <= 21) //G4
        updateValues(7);    
    else if (distance >= 22 && distance <= 23) //G4_A4
        updateValues(8);        
    else if (distance >= 24 && distance <= 25) //A4
        updateValues(9);   
    else if (distance >= 26 && distance <= 27) //A4_B4
        updateValues(10);          
    else if (distance >= 28 && distance <= 31) //B4
        updateValues(11);         
    else if (distance >= 32 && distance <= 33) //C5
        updateValues(12);     
    else if (distance >= 34 && distance <= 35) //C5_D5
        updateValues(13);
    else if (distance >= 36 && distance <= 37) //D5
        updateValues(14);     
    else if (distance >= 38 && distance <= 39) //D5_E5
        updateValues(15);    
    else if (distance >= 40 && distance <= 43) //E5 
        updateValues(16);           
    else if (distance >= 44 && distance <= 45) //F5 
        updateValues(17);            
    else if (distance >= 46 && distance <= 47) //F5_G5
        updateValues(18);           
    else if (distance >= 48 && distance <= 49) //G5 
        updateValues(19);          
    else if (distance >= 50 && distance <= 51) //G5_A5
        updateValues(20);             
    else if (distance >= 52 && distance <= 53) //A5 
        updateValues(21);          
    else if (distance >= 54 && distance <= 55) //A5_B5
        updateValues(22);     
    else if (distance >= 56 && distance <= 59) //B5
        updateValues(23);   
    else if (distance >= 60 && distance <= 63) //C6
        updateValues(24);       
  }

  if (prevVal != midiVal) {
    // send MIDI value
    MIDI.sendControlChange(midiCN, midiVal, midiCh);
  }
  
  
}
