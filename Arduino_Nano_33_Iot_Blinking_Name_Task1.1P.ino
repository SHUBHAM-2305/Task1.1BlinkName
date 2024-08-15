int ledPin = 13;          // LED connected to digital pin 13
int dotLength = 150;      // Duration of a dot in milliseconds
int dashDuration = 450;   // Duration of a dash in milliseconds

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sendNameInMorse();
  delay(5000);  // Wait 5 seconds before repeating the Morse code sequence
}

void sendNameInMorse() {
  sendMorse("...");    // S
  sendMorse("....");   // H
  sendMorse("..-");    // U
  sendMorse("-...");   // B
  sendMorse("....");   // H
  sendMorse(".-");     // A
  sendMorse("--");     // M
}

void sendMorse(String code) {
  for (int i = 0; i < code.length(); i++) {
    if (code[i] == '.') {
      sendDot();
    } else if (code[i] == '-') {
      sendDash();
    }
  }
  delay(dashDuration);  // Pause between letters
}

void sendDot() {
  turnOnLED(dotLength);
  delay(dotLength);  // Gap between elements
}

void sendDash() {
  turnOnLED(dashDuration);
  delay(dotLength);  // Gap between elements
}

void turnOnLED(int duration) {
  digitalWrite(ledPin, HIGH);
  delay(duration);
  digitalWrite(ledPin, LOW);
}
