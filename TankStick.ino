/* Basic USB Joystick Example
   Teensy becomes a USB joystick

   You must select Joystick from the "Tools > USB Type" menu

   Pushbuttons should be connected to digital pins 0 and 1.
   Wire each button between the digital pin and ground.
   Potentiometers should be connected to analog inputs 0 to 1.

   This example code is in the public domain.
*/

int throttle = 0;
int brake    = 0;
int rotateMin = 300;
int rotateMax = 874;
int xaxis = 0;
int xmin = 100;
int xzero = 488;
int xmax = 930;
int yaxis = 0;
int ymin = 132;
int yzero = 456;
int ymax = 800;

void setup() {
  for(byte i=0; i<28; i++){
    pinMode(i, INPUT_PULLUP);
  }
}

void loop() {
  Serial.printf("%i, %i, %i, %i, %i, %i\n",analogRead(A0),analogRead(A1),analogRead(A2),analogRead(A3),analogRead(A4));
  // read analog inputs and set X-Y position
  if(analogRead(A0) > xzero){
    xaxis = (analogRead(A0)-xzero)*(512.0/(xmax-xzero))+512;
  } else{
    xaxis = 512-(xzero-analogRead(A0))*(512.0/(xzero-xmin));
  }
  Serial.println(xaxis);
  Joystick.X(constrain(xaxis,0,1024));
  if(analogRead(A1) > yzero){
    yaxis = (analogRead(A1)-yzero)*(512.0/(ymax-yzero))+512;
  } else{
    yaxis = 512-(yzero-analogRead(A1))*(512.0/(yzero-ymin));
  }
  Joystick.Y(yaxis);
  throttle=(analogRead(A2)-462)*12;
  brake = (556-analogRead(A4))*10;
  Joystick.Z(constrain(throttle+brake,0,1024));
  Joystick.Zrotate(constrain((analogRead(A3)-rotateMin)*1.7839,0,1024));
  

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
  //Joystick.button(13, !digitalRead(6));
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

