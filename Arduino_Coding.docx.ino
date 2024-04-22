// Define pins
const int trigPin = 9; // Trigger pin of the ultrasonic sensor
const int echoPin = 10; // Echo pin of the ultrasonic sensor

// Variables to hold the duration and distance
long duration;
int distance;

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
  
  // Set trigPin as an OUTPUT
  pinMode(trigPin, OUTPUT);
  // Set echoPin as an INPUT
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set trigPin high for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the duration of the pulse on the echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance (in cm)
  distance = duration * 0.034 / 2;  // Speed of sound in air is 340 m/s or 0.034 cm/us
  
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Wait for a short time before taking the next measurement
  delay(1000);
}
