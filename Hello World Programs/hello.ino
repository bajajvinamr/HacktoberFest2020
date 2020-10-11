void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  Serial.begin(9600);
  Serial.println("Hello, world?");
}

void loop() {
/**/
}
