#include <Servo.h>

Servo myservo;
int pos = 0;

int pinArray[] = {8, 9, 10, 11, 12, 13};
int count = 0;


void setup()
{
  Serial.begin(9600);

  myservo.attach(9);

  for (count = 0; count < 6; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}
void loop()
{
  char in;
  if (Serial.available()) {
    in = Serial.read();
    if (in == '2') {
      digitalWrite(13, HIGH);
    } else if (in == '3') {
      digitalWrite(12, HIGH);
    } else if (in == '4') {
      for (pos = 0; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
      for (pos = 180; pos >= 0; pos -= 1) {
        myservo.write(pos);
        delay(15);
      }
    } else {
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    }
  }
}

