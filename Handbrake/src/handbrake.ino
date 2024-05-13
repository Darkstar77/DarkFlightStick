#include <Joystick.h>

//Define and Allocate Input Pins to memorable names
#define joyBrake A1
#define resetButton 2

//Initializing Axis as Integers, at a 0 default value
int brakeAxis_ = 0;

// Auto calibration variables.
int maxX = 0;
int minX = 1024;
int dzX = 1;

//Basic Filtering Analog Read Average variables.
int i = 0;
int cur = 0;
int filterSamples = 10;
int filterTally = 0;
int filterValue = 0;

//Defining the Joystick
Joystick_ Joystick(0x12, 0x04, 1, 0, true, false, false, false, false, false, false, false, false, false, false);

//Set Auto Send State
const bool initAutoSendState = true;

void setup() {
  //Set button pin mode
  pinMode(resetButton, INPUT_PULLUP);
  //Start Joystick - Needed to start the Joystick function libary
  Joystick.setXAxisRange(-127, 127);
  Joystick.begin();
}

void loop() {
  //Simpler average filter for the analog read
  for (i = 1; i <= filterSamples; i++){
    cur = analogRead(joyBrake);
    filterTally += cur;
    delay(1);
  }
  brakeAxis_ = filterTally/filterSamples;
  filterTally = 0;

  //Auto Calibration
  if (brakeAxis_ > maxX){
    maxX = brakeAxis_;
  }
  if (brakeAxis_ < minX){
    minX = brakeAxis_;
  }

  //Reset Auto Calibration in case of wonky behavior
  //This works from the keyswitch on the side of the base.
  if (!digitalRead(resetButton)){
    maxX = 0;
    minX = 1024;
    delay(10);
  }
  
  //Mapping the X Axis data from a 0-1023 to 0-255 range for a smoother action
  brakeAxis_ = map(brakeAxis_,minX+dzX,maxX-dzX,-127,127);
  
  //Set the Joystick X Axis value as the new, smoother, value
  Joystick.setXAxis(brakeAxis_);

//Small delay for debounce, though with the filter loop, probably not needed.
delay(10);
}
