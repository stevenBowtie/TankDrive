/* Basic USB Joystick Example
   Teensy becomes a USB joystick

   You must select Joystick from the "Tools > USB Type" menu

   Pushbuttons should be connected to digital pins 0 and 1.
   Wire each button between the digital pin and ground.
   Potentiometers should be connected to analog inputs 0 to 1.

   This example code is in the public domain.
*/

void setup() {
  for(byte i=0; i<28; i++){
    pinMode(i, INPUT_PULLUP);
  }
}

void loop() {
  // read analog inputs and set X-Y position
  Joystick.X(analogRead(A0));
  Joystick.Y(analogRead(A1));
  Joystick.sliderRight(analogRead(A2));
  Joystick.Zrotate(analogRead(A3));
  Joystick.sliderLeft(analogRead(A4));
  

  // read the digital inputs and set the buttons
  Joystick.button(1, digitalRead(17));
  Joystick.button(2, digitalRead(16));
  Joystick.button(8, digitalRead(15));
  Joystick.button(7, !digitalRead(14));
  Joystick.button(5, !digitalRead(13));
  Joystick.button(4, !digitalRead(12));
  Joystick.button(3, !digitalRead(11));
  Joystick.button(10, !digitalRead(10));
  Joystick.button(9, !digitalRead(9));
  Joystick.button(6, !digitalRead(8));
  Joystick.button(14, !digitalRead(7));
  Joystick.button(13, !digitalRead(6));
  Joystick.button(12, !digitalRead(5));
  Joystick.button(11, !digitalRead(4));
  Joystick.button(17, !digitalRead(3));
  Joystick.button(16, !digitalRead(2));
  Joystick.button(15, !digitalRead(1));
  Joystick.button(20, !digitalRead(0));
  Joystick.button(19, !digitalRead(27));
  Joystick.button(18, !digitalRead(26));
  Joystick.button(23, !digitalRead(25));
  Joystick.button(22, !digitalRead(24));
  Joystick.button(21, !digitalRead(23));
  // a brief delay, so this runs 20 times per second
  delay(50);
}

