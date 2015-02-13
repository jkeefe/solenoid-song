/*
  Modification of the BLINK example code.
  Instead of running an LED, I put a solenoid
  on the LED pin, and made it tap out a rhythm
 
  John Keefe
  http://johnkeefe.net
  February 2015
 
  */
 
// assign the pin variable to pin 13
int led = 13;

// these are note tones, but beats
// 4 is roughly a quarter note; 8 a half note
int notes[] = {4, 3, 1, 4, 8, 4, 4}; 

// this runs once:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// this repeats forever:
void loop() {
  
  // loop through the array of notes
  // got this sizeof example code from
  // http://arduino.cc/en/Reference/sizeof
  for (int i = 0; i < (sizeof(notes)/sizeof(int)); i++) {
  
    // do something with notes[i]
    // so calling the "ding" function and passing
    // the "note" number from the array
    ding(notes[i]);
  
  }
  
  delay(3000); // wait three seconds before doing it again

}

void ding(int beat) { 
  digitalWrite(led, HIGH);   // Send HIGH voltage level to the solenoid
  delay(50);                 // for just 50 milliseconds (quick hit)
  digitalWrite(led, LOW);    // send LOW voltage to the pin
  delay(100 * beat);         // pause for the length of the beat
}
