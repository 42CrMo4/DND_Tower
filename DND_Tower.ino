int LEDs[] = {5, 6, 9, 10, 11};
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

void setup()
{

  for ( int i = 0; i < (sizeof( LEDs )); i++)
  {
    if ( LEDs[i] )               // Check if not null
      pinMode( LEDs[i], OUTPUT ); // Explicitly set up each pin as input
  }

}

void loop() {
  if ( pinOn > sizeof( LEDs )) {
    pinOn = 0;
  }
  for ( int i = 0; i < sizeof( LEDs ); i++) {
    pinDistance = pinOn - i;
    if ( pinDistance < 0 )                // If negative, map to positive distance away
      pinDistance = sizeof( LEDs ) - i;
    if ( pinDistance > maxFadeDistance )  // Always turn off LED's > than X steps away
      pinDistance = maxFadeDistance;
    analogWrite( LEDs[i], brightnesses[pinDistance] );  // Use pwm to set brightness
  }
  pinOn ++;
}
