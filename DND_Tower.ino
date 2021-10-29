int LEDs[] = {PIN_PC0, PIN_PC1, PIN_PA3, PIN_PA4, PIN_PA5, PIN_PB2, PIN_PB1, PIN_PB0};
int maxFadeDistance = 3;        // Don't turn on LEDs more than 3 pins away
int maxB = 255;                 // Brightness range for LED is 0 - 255
int brightnesses[] = {          // To expand the fade across more pins, divide by
  maxB,                         //     a larger number and add more divisions:
  (int)(maxB - ((float) 1 / 3 * maxB)),
  (int)(maxB - ((float) 2 / 3 * maxB)),
  0
};

int pinOn = 0;
int pinDistance = 0;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 100;           // interval at which to blink (milliseconds)

void setup()
{

  for ( int i = 0; i < (sizeof( LEDs ) / sizeof(LEDs[0])); i++)
  {
    pinMode( LEDs[i], OUTPUT ); // Explicitly set up each pin as input
    analogWrite( LEDs[i], 255);
    delay(300);
  }

}

//void loop() {
//  if ( pinOn > 8) {
//    pinOn = 0;
//  }
//  analogWrite( LEDs[pinOn], 255 );  // Use pwm to set brightness
//  delay(100);
//  analogWrite( LEDs[pinOn], 0 );
//  pinOn++;
//}

void loop() {
  if ( pinOn >= (sizeof( LEDs ) / sizeof(LEDs[0]))) {
    pinOn = 0;
  }
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    for ( int i = 0; i < (sizeof( LEDs ) / sizeof(LEDs[0])); i++) {
      pinDistance = pinOn - i;
      if ( pinDistance < 0 )                // If negative, map to positive distance away
        pinDistance = (sizeof( LEDs ) / sizeof(LEDs[0])) + pinDistance;
      if ( pinDistance > maxFadeDistance )  // Always turn off LED's > than X steps away
        pinDistance = maxFadeDistance;
      analogWrite( LEDs[i], brightnesses[pinDistance] );  // Use pwm to set brightness
    }
    pinOn++;
  }
}
