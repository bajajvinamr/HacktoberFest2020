#include <NewPing.h>
#include <Servo.h>

//ultra masuk
#define TRIGGER_PIN  12
#define ECHO_PIN     11
//ultra keluar
#define TRIGGER_PIN2  10
#define ECHO_PIN2     9

Servo Servo1;
NewPing sonar(TRIGGER_PIN, ECHO_PIN);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2);

void setup() {
  Serial.begin(9600);
  Servo1.attach(6);
  Servo1.write(0);
}

void loop() {
  delay(500);
  int SNS = sonar.ping_cm();
  int SNS1 = sonar2.ping_cm();
  Serial.print(SNS);
  Serial.print(" , ");
  Serial.print(SNS1);
  Serial.println("cm");
   if (SNS < 50) {
      Servo1.write(90);
      delay(500);
    }
    if (SNS1 < 50) {
      Servo1.write(0);
      delay(500);
    }
}
//5v tengah, gnd coklat, pin orange
