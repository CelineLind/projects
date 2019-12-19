//////////////////////////////////////
// Christmas Tree Box Project
// link to blogpost: *will add when published*
// by Celine L
// Dec 2019
//////////////////////////////////////

// pin numbers
int ledPins[] = {3,4,5,6,7,8,9,10,11,12}; // pin numbers of the LEDs
const int buttonPin = 2; // button pin

// variables that will change
int buttonState = 0; // for reading the pushbutton state
int pattern = 1;
int buttonPresses = 0; // used for changing the pattern
int loops = 0;

void setup(){
  int index;
  for(index = 0; index <= 10; index++){
    pinMode(ledPins[index],OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}


void loop(){
  if (pattern == 1){
    oneAfterAnotherNoLoop(); // Light up all the LEDs in turn
    LoopNext();
  }
  else if (pattern == 2){
    GreenRedChange();
    LoopNext();
  }
  else if (pattern == 3){
    Waterfall();
    LoopNext();
  }
}


void CheckForButtonPress(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH){
    buttonPresses++;
  }
}


void LoopNext(){
  loops++;
  if (loops > 8){ // loops a pattern 8 times, then moves to next pattern
    loops = 0;
    pattern++;
    if (pattern > 3){
      pattern = 1;
    }
  }
}


void oneAfterAnotherNoLoop(){
  int delayTime = 150; // time (milliseconds) to pause between
  digitalWrite(ledPins[9], LOW); // turn off yellow
  
  // turn all the LEDs on individually
  for (int i = 0; i <= 10; i++){
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    CheckForButtonPress();
  }

  delay(delayTime); // wait delayTime milliseconds

  // turn all the LEDs off individually
  for (int i = 10; i >= 0; i--){
    digitalWrite(ledPins[i], LOW);
    delay(delayTime);
    CheckForButtonPress();
  }

  // check if button was pressed and should move onto next pattern
  if (buttonPresses > 0){
    pattern++;
    buttonPresses = 0;
    loops = 0;
  }
  
}


void GreenRedChange(){
  int delayTime = 1000;
  
  // turn on yellow the whole time
  digitalWrite(ledPins[9], HIGH);
  CheckForButtonPress();
  
  // turn on all red
  digitalWrite(ledPins[8], HIGH);
  digitalWrite(ledPins[6], HIGH);
  CheckForButtonPress();
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[0], HIGH);
  CheckForButtonPress();
  
  // turn off all green
  digitalWrite(ledPins[7], LOW);
  digitalWrite(ledPins[5], LOW);
  CheckForButtonPress();
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[1], LOW);
  CheckForButtonPress();

  // delay
  delay(delayTime);
  CheckForButtonPress();

  // turn off all red
  digitalWrite(ledPins[8], LOW);
  digitalWrite(ledPins[6], LOW);
  CheckForButtonPress();
  digitalWrite(ledPins[4], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[0], LOW);
  CheckForButtonPress();

  // turn on all green
  digitalWrite(ledPins[7], HIGH);
  digitalWrite(ledPins[5], HIGH);
  CheckForButtonPress();
  digitalWrite(ledPins[3], HIGH);
  digitalWrite(ledPins[1], HIGH);
  CheckForButtonPress();

  // delay
  delay(delayTime);
  CheckForButtonPress();

  // check if button was pressed and should move onto next pattern
  if (buttonPresses > 0){
    pattern++;
    buttonPresses = 0;
    loops = 0;
  }
  
}


void TurnAllOff(){
  // turn all the LEDs off:
  digitalWrite(ledPins[9], LOW); //Turn off LED #7 (pin 9)
  
  digitalWrite(ledPins[8], LOW); //Turn off LED #7 (pin 9)
  
  digitalWrite(ledPins[7], LOW); //Turn off LED #7 (pin 9)

  CheckForButtonPress();
  
  digitalWrite(ledPins[6], LOW); //Turn off LED #6 (pin 8)
  
  digitalWrite(ledPins[5], LOW); //Turn off LED #5 (pin 7)
  
  digitalWrite(ledPins[4], LOW); //Turn off LED #4 (pin 6)

  CheckForButtonPress();
  
  digitalWrite(ledPins[3], LOW); //Turn off LED #3 (pin 5)
  
  digitalWrite(ledPins[2], LOW); //Turn off LED #2 (pin 4)
  
  digitalWrite(ledPins[1], LOW); //Turn off LED #1 (pin 3)
  
  digitalWrite(ledPins[0], LOW); //Turn off LED #0 (pin 2)

  CheckForButtonPress();
}


void Waterfall(){
  int delayTime = 1000;
  TurnAllOff();
  
  // turn on yellow the whole time
  digitalWrite(ledPins[9], HIGH);
  CheckForButtonPress();
  
  // have one LED on at a time
  for (int i = 8; i >= 0; i--){
    digitalWrite(ledPins[i], HIGH);
    if (i < 8){
      digitalWrite(ledPins[i+1], LOW);
    }
    delay(delayTime);
    CheckForButtonPress();
  }

  // check if button was pressed and should move onto next pattern
  if (buttonPresses > 0){
    pattern++;
    loops = 0;
    buttonPresses = 0;
  }
  
}
