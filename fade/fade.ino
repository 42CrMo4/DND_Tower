/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

int led1 = PIN_PC0;           // the PWM pin the LED is attached to
int led2 = PIN_PC1;           // the PWM pin the LED is attached to
int led3 = PIN_PA3;           // the PWM pin the LED is attached to
int led4 = PIN_PA4;           // the PWM pin the LED is attached to
int led5 = PIN_PA5;           // the PWM pin the LED is attached to
int led8 = PIN_PB0;           // the PWM pin the LED is attached to
int led7 = PIN_PB1;           // the PWM pin the LED is attached to
int led6 = PIN_PB2;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  digitalWrite(led1, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led1, brightness - 50);
  analogWrite(led2, 255 - brightness);
  analogWrite(led3, brightness - 50);
  analogWrite(led4, 255 - brightness);
  analogWrite(led5, brightness - 50);
  analogWrite(led6, 255 - brightness);
  analogWrite(led7, brightness - 50);
  analogWrite(led8, 255 - brightness);
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
