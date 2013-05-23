#define NO_OF_LEDS 10
int state = HIGH;
void setup(){
  for(int i = 0; i < NO_OF_LEDS ; i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  for(int i = 0; i < NO_OF_LEDS ; i++){
    digitalWrite(i, state);
    delay(500);
  }
  
  state = !state;
}


