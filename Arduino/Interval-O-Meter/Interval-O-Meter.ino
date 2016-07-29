int focusPin = 1;
int shutterPin = 0;
int delayPin = A3;
int toFocusPin = 4;
int modePin = 2;

bool toFocus;
bool mode;
long delayDuration = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(focusPin, OUTPUT);
  pinMode(shutterPin, OUTPUT);
  pinMode(delayPin, INPUT);
  pinMode(toFocusPin, INPUT);
  pinMode(modePin, INPUT);
  
  
  
}

// the loop routine runs over and over again forever:
void loop() {
  // Read the mode and delay duration only once to prevent accidental changes
  // This also means there can be no intentional changes
  mode = (digitalRead(modePin) == HIGH);
  delayDuration = analogRead(delayPin);
  
  //scale delay for timing between 1 second and 60 seconds
  delayDuration = ((float(delayDuration) / 1023) * (60 - 1) + 1) * 1000;
  
  toFocus = (digitalRead(toFocusPin) == HIGH);
  
  
  if(toFocus) focus();
  if(mode)
    timeLapse();
  else
    starTrail();
}

void focus() {
  digitalWrite(focusPin, HIGH);
  delay(500);
  digitalWrite(focusPin, LOW);
  delay(100);
}

void timeLapse() {
  digitalWrite(shutterPin, HIGH);
  delay(100);
  digitalWrite(shutterPin, LOW);
  delay(delayDuration);
}

void starTrail() {
  digitalWrite(shutterPin, HIGH);
  delay(delayDuration);
  digitalWrite(shutterPin, LOW);
  delay(100);
}