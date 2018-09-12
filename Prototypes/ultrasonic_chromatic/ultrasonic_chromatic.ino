const int echoPin = 9;
const int trigPin = 8;
const int Buzz = 11;

//int note = 262;                              // middle C

int c4 = 262;                                  // middle C
int c4_d4 = 277;
int d4 = 294;
int d4_e4 = 311;
int e4 = 330;
int f4 = 349;
int f4_g4 = 370;
int g4 = 392;
int g4_a4 = 415;
int a4 = 440;
int a4_b4 = 466;
int b4 = 494;
int c5 = 523;
int c5_d5 = 554;
int d5 = 587;
int d5_e5 = 622;
int e5 = 659;
int f5 = 698;
int f5_g5 = 740;
int g5 = 784;
int g5_a5 = 831;
int a5 = 880;
int a5_b5 = 932;
int b5 = 988;
int c6 = 1047;
int notes[] = {c4, c4_d4, d4, d4_e4, e4, f4, f4_g4, g4, g4_a4, a4, a4_b4, b4, c5, c5_d5, d5, d5_e5, e5, f5, f5_g5, g5, g5_a5, a5, a5_b5, b5, c6};       // array storing all notes

long duration, distance;

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
  
  distance = (duration/2)/29.1;               // formula for converting time into distance (cm)
                                              // using speed of sound = 340 m/s

  Serial.print("Distance: ");
  Serial.println(distance);                   // println prints thing in brackets and adds new line

  if (distance >= 4 && distance <= 63)
  {
    if (distance >= 4 && distance <= 5)      //C4 (middle C)
      tone(Buzz, notes[0]);
    else if (distance >= 6 && distance <= 7)
        tone(Buzz, notes[1]);                //C4_D4
    else if (distance >= 8 && distance <= 9)
        tone(Buzz, notes[2]);                //D4
    else if (distance >= 10 && distance <= 11)
        tone(Buzz, notes[3]);                //D4_E4
    else if (distance >= 12 && distance <= 15)
        tone(Buzz, notes[4]);                //E4
    else if (distance >= 16 && distance <= 17)
        tone(Buzz, notes[5]);                //F4
    else if (distance >= 18 && distance <= 19)
        tone(Buzz, notes[6]);                //F4_G4
    else if (distance >= 20 && distance <= 21)
        tone(Buzz, notes[7]);                //G4
    else if (distance >= 22 && distance <= 23)
        tone(Buzz, notes[8]);                //G4_A4
    else if (distance >= 24 && distance <= 25)
        tone(Buzz, notes[9]);                //A4
    else if (distance >= 26 && distance <= 27)
        tone(Buzz, notes[10]);                //A4_B4
    else if (distance >= 28 && distance <= 31)
        tone(Buzz, notes[11]);                //B4
    else if (distance >= 32 && distance <= 33)
        tone(Buzz, notes[12]);                //C5
    else if (distance >= 34 && distance <= 35)
        tone(Buzz, notes[13]);                //C5_D5
    else if (distance >= 36 && distance <= 37)
        tone(Buzz, notes[14]);                //D5
    else if (distance >= 38 && distance <= 39)
        tone(Buzz, notes[15]);                //D5_E5
    else if (distance >= 40 && distance <= 43)
        tone(Buzz, notes[16]);                //E5 
    else if (distance >= 44 && distance <= 45)
        tone(Buzz, notes[17]);               //F5 
    else if (distance >= 46 && distance <= 47)
        tone(Buzz, notes[18]);                //F5_G5
    else if (distance >= 48 && distance <= 49)
        tone(Buzz, notes[19]);               //G5 
    else if (distance >= 50 && distance <= 51)
        tone(Buzz, notes[20]);                //G5_A5
    else if (distance >= 52 && distance <= 53)
        tone(Buzz, notes[21]);               //A5 
    else if (distance >= 54 && distance <= 55)
        tone(Buzz, notes[22]);                //A5_B5
    else if (distance >= 56 && distance <= 59)
        tone(Buzz, notes[23]);               //B5 
    else if (distance >= 60 && distance <= 63)
        tone(Buzz, notes[24]);               //C6 
  }  

  else {
    noTone(Buzz);
  }
}
