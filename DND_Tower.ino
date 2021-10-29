int LEDs[] = {PIN_PC0, PIN_PC1, PIN_PA3, PIN_PA4, PIN_PA5, PIN_PB2, PIN_PB1, PIN_PB0};
int maxFadeDistance = 3;        // Don't turn on LEDs more than 3 pins away
int maxB = 255;                 // Brightness range for LED is 0 - 255
int brightnesses[] = {          // To expand the fade across more pins, divide by
  maxB,                         //  a larger number and add more divisions:
  (int)(maxB - ((float) 1 / 3 * maxB)),
  (int)(maxB - ((float) 2 / 3 * maxB)),
  0
};
const long interval = 100;       // interval at which to blink (milliseconds)

int pinOn = 0;
int pinDistance = 0;
unsigned long previousMillis = 0;// will store last time LED was updated

void setup()
{

  for ( int i = 0; i < (sizeof( LEDs ) / sizeof(int)); i++)
  {
    pinMode( LEDs[i], OUTPUT ); // Explicitly set up each pin as input
    analogWrite( LEDs[i], 255);
    delay(300);
  }

}

void loop() {
  unsigned long currentMillis = millis();
  
  if ( pinOn >= (sizeof( LEDs ) / sizeof(LEDs[0]))) {
    pinOn = 0;
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;         // save the last time you blinked the LED
    for ( int i = 0; i < (sizeof( LEDs ) / sizeof(int)); i++) {
      pinDistance = pinOn - i;
      if ( pinDistance < 0 )                // If negative, map to positive distance away
        pinDistance = (sizeof( LEDs ) / sizeof(int)) + pinDistance;
      if ( pinDistance > maxFadeDistance )  // Always turn off LED's > than X steps away
        pinDistance = maxFadeDistance;
      analogWrite( LEDs[i], brightnesses[pinDistance] );  // Use pwm to set brightness
    }
    pinOn++;
  }
}
