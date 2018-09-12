const int echoPin = 9;
const int trigPin = 8;
const int Buzz = 11;

int c4 = 262;                                  // middle C
int d4 = 294;
int e4 = 330;
int f4 = 349;
int g4 = 392;
int a4 = 440;
int b4 = 494;
int c5 = 523;
int d5 = 587;
int e5 = 659;
int f5 = 698;
int g5 = 784;
int a5 = 880;
int b5 = 988;
int c6 = 1047;
int notes[] = {c4, d4, e4, f4, g4, a4, b4, c5, d5, e5, f5, g5, a5, b5, c6};       // array storing all notes

long duration;
float distance, note;

// function for calculating Hz value
long calculateNote(int distance, int proper_note) {
  int i = proper_note/4 - 1;
  int calculated_note = (distance - proper_note)*((notes[i+1]-notes[i])/4) + notes[i];  // 'distance' from last proper note multiplied by
                                                                                   // proportion of difference between closest 2 proper notes
                                                                                   // added to lower note
  
  Serial.print("Calculated note: ");
  Serial.println(calculated_note);
  
  return calculated_note;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  pinMode(Buzz, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);                 // init -- clearing trig pin
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);                // sending out ultrasonic signal
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin,HIGH);           // catch the signal from the echo pin when it arrives
  distance = (duration/2)/29.1;               // formula for converting time into distance (cm)
                                              // using speed of sound = 340 m/s

  Serial.print("Distance: ");
  Serial.println(distance);                   // println prints thing in brackets and adds new line

  // scale from C4 (middle C) to C6
  if (distance >= 4 && distance <= 62)
  {
    if (distance >= 4 && distance <= 7) {     //For a distance 4, it plays C4 (middle C)
      note = calculateNote(distance, 4);
      tone(Buzz, note);
    }
    else if (distance >= 8 && distance <= 11) {
      note = calculateNote(distance, 8);
      tone(Buzz, note);                       //For a distance 8, it plays D4
    }
    else if (distance >= 12 && distance <= 15) {
      note = calculateNote(distance, 12);
      tone(Buzz, note);                       //For a distance 12, it plays E4
    }
    else if (distance >= 16 && distance <= 19) {
      note = calculateNote(distance, 16);
      tone(Buzz, note);                       //For a distance 16, it plays F4
    }
    else if (distance >= 20 && distance <= 23) {
      note = calculateNote(distance, 20);
      tone(Buzz, note);                       //For a distance 20, it plays G4
    }
    else if (distance >= 24 && distance <= 27) {
      note = calculateNote(distance, 24);
      tone(Buzz, note);                       //For a distance 24, it plays A4
    }
    else if (distance >= 28 && distance <= 31) {
      note = calculateNote(distance, 28);
      tone(Buzz, note);                       //For a distance 28, it plays B4
    }
    else if (distance >= 32 && distance <= 35) {
      note = calculateNote(distance, 32);
      tone(Buzz, note);                       //For a distance 32, it plays C5
    }
    else if (distance >= 36 && distance <= 39) {
      note = calculateNote(distance, 36);
      tone(Buzz, note);                       //For a distance 36, it plays D5
    }
    else if (distance >= 40 && distance <= 43) {
      note = calculateNote(distance, 40);
      tone(Buzz, note);                       //For a distance 40, it plays E5 
    }
    else if (distance >= 44 && distance <= 47) {
      note = calculateNote(distance, 44);
      tone(Buzz, note);                       //For a distance 44, it plays F5 
    }
    else if (distance >= 48 && distance <= 51) {
      note = calculateNote(distance, 48);
      tone(Buzz, note);                       //For a distance 48, it plays G5 
    }
    else if (distance >= 52 && distance <= 55) {
      note = calculateNote(distance, 52);
      tone(Buzz, note);                       //For a distance 52, it plays A5 
    }
    else if (distance >= 56 && distance <= 59) {
      note = calculateNote(distance, 56);
      tone(Buzz, note);                       //For a distance 56, it plays B5 
    }
    else tone(Buzz, notes[14]);                  //For a distance 60-62, it plays C6
  }  
  else {
    noTone(Buzz);
  }
}
