int halfShutterPin = 0; //Output pin to control half shutter
int shutterPin = 1;  //Output pin to control full shutter
int delayPin = A3;  //Input pin to set the time between photos
int toHalfShutterPin = 4;  //Input pin to set whether or not to use half shutter
int modePin = 2;  //Input pin to set the shooting mode

bool toHalfShutter;
bool mode;
long delayDuration = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(halfShutterPin, OUTPUT);
  pinMode(shutterPin, OUTPUT);
  pinMode(delayPin, INPUT);
  pinMode(toHalfShutterPin, INPUT);
  pinMode(modePin, INPUT);
  
  //Determine the shooting mode
  mode = (digitalRead(modePin) == HIGH);
  
}

// the loop routine runs over and over again forever:
void loop() {
  

  //Determine the duration of the delay between  photos
  delayDuration = analogRead(delayPin);
  
  //scale delay for timing between 1 second and 60 seconds
  delayDuration = ((float(delayDuration) / 1023) * (60 - 1) + 1) * 1000;

  // Autofocus operation
//  toHalfShutter = (digitalRead(toHalfShutterPin) == HIGH);
//  if(toHalfShutter) halfShutter();
  
  // AE lock operation
  digitalWrite(halfShutterPin, digitalRead(toHalfShutterPin));
  
  if(mode)
    timeLapse();
  else
    starTrail();
}

// ********Uncomment for autofocus operation***********
//void halfShutter() {
//  digitalWrite(halfShutterPin, HIGH);
//  delay(500);
//  digitalWrite(halfShutterPin, LOW);
//  delay(100);
//}

void timeLapse() {
  digitalWrite(shutterPin, HIGH);
  delay(500);
  digitalWrite(shutterPin, LOW);
  delay(delayDuration);
}

void starTrail() {
  digitalWrite(shutterPin, HIGH);
  delay(delayDuration);
  digitalWrite(shutterPin, LOW);
  delay(1000);
}
