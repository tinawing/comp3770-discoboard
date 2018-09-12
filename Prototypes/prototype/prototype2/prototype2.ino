#include <CapacitiveSensor.h>

CapacitiveSensor cs_2_4 = CapacitiveSensor(2,4);            // pin 4 is sensor pin for foil capacitive sensing

#define C4 262                                                // play C note
#define CAP_THRESHOLD 5                                     // this is basically the amount of "sensing" the capacitor does
                                                              // if you reduce it then the sensor detects more easily if increased it does the opposite
                                                              // EXPERIMENT WITH THIS VALUE

const int Buzz = 11;                                          // buzzer connected to pin 11

void setup() {
  // put your setup code here, to run once:
  
  cs_2_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(Buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // if cap sense activated, play C4 note
  while (cs_2_4.capacitiveSensor(1) > CAP_THRESHOLD){
    tone(Buzz,C4);
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    }

  digitalWrite(LED_BUILTIN, LOW);
  noTone(Buzz);
  
// blinking LED

//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(100);
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(100);

// BUZZER
  
//  tone(Buzz,262);
//  delay(100);
//  noTone(Buzz);
//  delay(100);
}
