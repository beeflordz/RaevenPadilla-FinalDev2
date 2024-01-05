#define BLYNK_TEMPLATE_ID "TMPL6DKHHDAXK"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "gLYVCl2kjYjbAGerJPeYLM13q8IhnVzX"

#include <BlynkSimpleEsp32.h>  // Include the Blynk library for ESP32

const int trigPin = 23;
const int echoPin = 22;
const char* auth = "gLYVCl2kjYjbAGerJPeYLM13q8IhnVzX";  // Replace with your Blynk authentication token

// Define distance thresholds in centimeters
const int emptyThreshold = 30;    // Adjust as needed
const int partiallyFullThreshold = 15;  // Adjust as needed

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, "BeefLord", "cowjuice");  // Replace with your Wi-Fi credentials
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  Blynk.run();  // Run Blynk tasks

  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Determine trash can status based on distance thresholds
  if (distance >= emptyThreshold) {
    // Trash can is empty
    Blynk.virtualWrite(V1, "Empty");
  } else if (distance >= partiallyFullThreshold) {
    // Trash can is partially full
    Blynk.virtualWrite(V1, "Partially Full");
  } else {
    // Trash can is full
    Blynk.virtualWrite(V1, "Full");
  }

  delay(1000);
}
