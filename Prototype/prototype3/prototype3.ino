#define resolution 8
#define mains 50  // 60: north america, japan; 50: most other places

#define refresh 2 * 1000000 / mains


#define C4 262                                                // play C note

int maxval = 20; //This value was obtained by experimenting. Touch the pad
                 //connetced to pin eight. The value in the serial window
                 //corresponding to pin 8 will be maxval.     

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(8, INPUT);
  pinMode(Buzz, OUTPUT);

  startTimer();
}

void loop() {  
  
  Serial.print(time(8, B00000001), DEC);
  Serial.print(" ");
  
  
 x = time(8, B00000001), DEC;

 //write to LED_BUILTIN
//analogWrite()

/* This works for both common anode and cathode LEDs. However, 
   analogWrite(R, 255) will make the red in common anode RGB LED
   off and analogWrite(R, 0) will give it full brightness. The 
   opposite for common cathode. */
} 

// Everything below doesnt need to be changed... 

long time(int pin, byte mask) {
  unsigned long count = 0, total = 0;
//  while(checkTimer() < refresh) {
    // pinMode is about 6 times slower than assigning
    // DDRB directly, but that pause is important
    pinMode(pin, OUTPUT);
    PORTH = 0;
    pinMode(pin, INPUT);
    while((PINH & mask) == 0){
      count++;
    total++;
    }
//  }

  startTimer();
  return (count << resolution) / total;
}

extern volatile unsigned long timer0_overflow_count;

void startTimer() {
  timer0_overflow_count = 0;
  TCNT0 = 0;
}

unsigned long checkTimer() {
  return ((timer0_overflow_count << 8) + TCNT0) << 2;
}


