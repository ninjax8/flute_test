#include <AccelStepper.h>

#define DIR 2
#define STEP 3
const int ledPin = 13;
const int relayPin =  12;      // the number of the LED pin
int relayState = LOW;             // relayState used to set the LED
unsigned long previousMillis1 = 0;        // will store last time LED was updated
long OnTime1 = 250;           // milliseconds of on-time
long OffTime1 = 750;          // milliseconds of off-time

AccelStepper stepper(AccelStepper::DRIVER, STEP, DIR);

volatile int16_t startPos = 200;
volatile int16_t endPos = -200;

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  stepper.setSpeed(500);
  stepper.setAcceleration(500);
}

void loop() {


  // put your main code here, to run repeatedly:

  if (stepper.currentPosition() < startPos) {
    stepper.moveTo(startPos);
    stepper.run();
  }

  else if (stepper.currentPosition() >= startPos) {
    stepper.stop();
    digitalWrite(ledPin,HIGH);
  }


  if (stepper.currentPosition() > endPos) {
    stepper.moveTo(endPos);
    stepper.run();
  }
  else if (stepper.currentPosition() <= endPos) {
    stepper.stop();
    digitalWrite(ledPin,LOW);
  }
//  if(digitalRead(ledPin) == LOW){
//  unsigned long currentMillis = millis();
//        if((relayState == HIGH) && (currentMillis - previousMillis1 >= OnTime1))
//    {
//      relayState = LOW;  // Turn it off
//      previousMillis1 = currentMillis;  // Remember the time
//      digitalWrite(relayPin, relayState);  // Update the actual LED
//    }
//    else if ((relayState == LOW) && (currentMillis - previousMillis1 >= OffTime1))
//    {
//      relayState = HIGH;  // turn it on
//      previousMillis1 = currentMillis;   // Remember the time
//      digitalWrite(relayPin, relayState);    // Update the actual LED
//    }
//  }

}
