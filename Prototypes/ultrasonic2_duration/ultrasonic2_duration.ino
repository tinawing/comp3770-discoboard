const int echoPin = 3;
const int trigPin = 2;
const int Buzz = 11;

//int note = 262;                              // middle C

int c4 = 266;                                  // middle C
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
float distance;

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

  Serial.print("Duration: ");
  Serial.println(duration);
  
  distance = (duration/2)/29.1;                 // formula for converting time into distance (cm)
                                              // using speed of sound = 340 m/s

  Serial.print("Distance: ");
  Serial.println(distance);                   // println prints thing in brackets and adds new line

  if (distance >= 4 && distance <= 63)
  {
    if (distance >= 4 && distance <= 7)      //For a distance between 4 and 7, it plays C4 (middle C)
      tone(Buzz, notes[0]);
    else if (distance >= 8 && distance <= 11)
        tone(Buzz, notes[1]);      //For a distance between 8 and 11, it plays D4
    else if (distance >= 12 && distance <= 15)
        tone(Buzz, notes[2]);      //For a distance between 12 and 15, it plays E4
    else if (distance >= 16 && distance <= 19)
        tone(Buzz, notes[3]);      //For a distance between 16 and 19, it plays F4
    else if (distance >= 20 && distance <= 23)
        tone(Buzz, notes[4]);      //For a distance between 20 and 23, it plays G4
    else if (distance >= 24 && distance <= 27)
        tone(Buzz, notes[5]);      //For a distance between 24 and 27, it plays A4
    else if (distance >= 28 && distance <= 31)
        tone(Buzz, notes[6]);      //For a distance between 28 and 31, it plays B4
    else if (distance >= 32 && distance <= 35)
        tone(Buzz, notes[7]);      //For a distance between 32 and 35, it plays C5
    else if (distance >= 36 && distance <= 39)
        tone(Buzz, notes[8]);      //For a distance between 36 and 39, it plays D5
    else if (distance >= 40 && distance <= 43)
        tone(Buzz, notes[9]);      //For a distance between 40 and 43, it plays E5 
    else if (distance >= 44 && distance <= 47)
        tone(Buzz, notes[10]);      //For a distance between 44 and 47, it plays F5 
    else if (distance >= 48 && distance <= 51)
        tone(Buzz, notes[11]);      //For a distance between 48 and 51, it plays G5 
    else if (distance >= 52 && distance <= 55)
        tone(Buzz, notes[12]);      //For a distance between 52 and 55, it plays A5 
    else if (distance >= 56 && distance <= 59)
        tone(Buzz, notes[13]);      //For a distance between 56 and 59, it plays B5 
    else if (distance >= 60 && distance <= 63)
        tone(Buzz, notes[14]);      //For a distance between 60 and 63, it plays C6 
  }  

  else {
    noTone(Buzz);
  }
}
