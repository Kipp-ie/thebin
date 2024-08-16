#import "Servo.h"

const float BETA = 3950; // should match the Beta Coefficient of the thermistor
Servo myservo;
void setup() {
  Serial1.begin(9600);
  myservo.attach(27);
}

void loop() {
  myservo.write(70);
  int analogValue = analogRead(26);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  Serial1.print("Temperature: ");
  Serial1.print(celsius);
  Serial1.println(" ℃");
  delay(1000);
  
}
