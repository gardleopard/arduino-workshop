#define SONAR_TRIG 13
#define SONAR_ECHO 12

void setup() {
  Serial.begin (9600);
  pinMode(SONAR_TRIG, OUTPUT);
  pinMode(SONAR_ECHO, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(SONAR_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(SONAR_TRIG, LOW);

  duration = pulseIn(SONAR_ECHO, HIGH);
  distance = duration/59;
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
}
