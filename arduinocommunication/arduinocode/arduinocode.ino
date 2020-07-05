// Arduino Serial Tester
// rld, cycling'74, 3.2008

int button01StateNew = -1;
int button01StateOld = -1;


int slider01StateNew = -1;
int slider01StateOld = -1;


void setup()
{
  Serial.begin(9600); // open the arduino serial port
  pinMode( 0, INPUT );
  pinMode( 1, INPUT );
  pinMode( 5, OUTPUT);
}

void loop()
{
  detectInputChange();
  delay(10);

  while (Serial.available() > 0) {
    int ledState = Serial.read();
    if ( ledState == 1 ) {
      digitalWrite(5, HIGH);
    } else {
      digitalWrite(5, LOW);
    }
  }

}

void detectInputChange() {

  button01StateNew = digitalRead(0);
  if ( button01StateNew !=  button01StateOld ) {
    button01StateChanged( button01StateNew );
  }
  button01StateOld = button01StateNew;

  slider01StateNew = analogRead(1);
  if ( slider01StateNew !=  slider01StateOld ) {
    slider01StateChanged( slider01StateNew );
  }
  slider01StateOld = slider01StateNew;
}

void button01StateChanged( int value ) {
  Serial.write( 99 );
  Serial.write( 10 );
  Serial.write( value );
  Serial.write( 255 );

}

void slider01StateChanged( int value ) {
  Serial.write( 99 );
  Serial.write( 11 );
  Serial.write( value / 256 );
  Serial.write( value % 256 );
}
