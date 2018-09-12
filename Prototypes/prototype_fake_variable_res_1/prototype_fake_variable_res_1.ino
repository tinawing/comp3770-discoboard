const int potPin = 2;                             // pin acting as dial on variable resistor
const int Buzz = 11;                              // buzzer

int note = 262;                             // note to play through buzzer (initialised to middle C)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Buzz, OUTPUT);
}

int val = 0;

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(potPin);
  Serial.print(val, DEC);
  Serial.print("\n");

  note = val;
  tone(Buzz, note);

  delay(1000);
}
