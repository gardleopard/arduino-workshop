#define NO_OF_LEDS 10
#define MAX_SPEED 100
int mySpeed = MAX_SPEED;
int state = HIGH;
void setup(){
  for(int i = 0; i < NO_OF_LEDS ; i++){
    pinMode(i, OUTPUT);
  }
}

void knightRider() {
  for(int i = 1; i < NO_OF_LEDS ; i++) {
    digitalWrite(i, state);
    digitalWrite(i-1,!state);
    delay(mySpeed);
  }
  for(int j = NO_OF_LEDS-2; j >= 0 ; j--) {
    digitalWrite(j, state);
    digitalWrite(j+1, !state);
    delay(mySpeed);
  }
}
void nukeAll(){
  for(int i = 0 ; i < NO_OF_LEDS ; i++) {
    digitalWrite(i, !state);
  }
}

void somePattern(){
  int half = NO_OF_LEDS/2;
  for(int i = 0 ; i < half ; i++) {
    nukeAll();
    digitalWrite(half+i, state);
    digitalWrite(half-i-1,state);
    delay(mySpeed);
  }
  for(int i = half-2 ; i > 0 ; i--) {
    nukeAll();
    digitalWrite(half+i, state);
    digitalWrite(half-i-1,state);
    delay(mySpeed);
  }
  
}

void loop(){
  mySpeed = random(20,MAX_SPEED);
  if(random(0,1) == 0) {
    state = !state;
  }
  int iterations = random(0,25);
  for(int i = 0 ; i < iterations ; i++) {
    mySpeed = random(20,MAX_SPEED);
    knightRider();
  }
  for(int i = 0 ; i < iterations ; i++) {
    mySpeed = random(20,MAX_SPEED);
    somePattern();
  }
  
  
}


