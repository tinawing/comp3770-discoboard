const int echoPin = 3;
const int trigPin = 2;
const int Buzz = 11;

int note = 262;

long duration;
int distance;

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
  distance = duration*0.034/2;                // formula for converting time
                                              // using speed of sound = 340 m/s = 0.034 cm/microseconds

  Serial.print("Distance: ");
  Serial.println(distance);                   // println prints thing in brackets and adds new line

  if (distance < 5) {
    tone(Buzz, note);                         // play Middle C
  }

  else {
    int x = distance - 5;
    note = note + 2*x;
    Serial.print("Frequency: ");
    Serial.println(note);
    tone(Buzz, note);
    note = 262;                               // reset
  }
}
