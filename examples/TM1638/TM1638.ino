#include "TM1638.h"
TM1638 module(8, 9, 7);

int counter = 0;
int delay_time = 100;
int color = TM1638_COLOR_RED;
int bgcolor = TM1638_COLOR_NONE;
void setup(){
  module.setDisplayToString("  1337  ");
}

void loop(){
  int pos = counter%8;
  byte keys = module.getButtons();
  
  //speed
  if(keys == 0b00000001)
    delay_time += 10;
  if(keys == 0b00000010 && delay_time > 10)
    delay_time -= 10;
  
  //colors
  if(keys == 0b00000100)
    color = TM1638_COLOR_NONE;
  if(keys == 0b00001000)
    color = TM1638_COLOR_RED;
  if(keys == 0b00010000)
    color = TM1638_COLOR_GREEN;
  if(keys == 0b00100000)
    bgcolor = TM1638_COLOR_NONE;
  if(keys == 0b01000000)
    bgcolor = TM1638_COLOR_RED;
  if(keys == 0b10000000)
    bgcolor = TM1638_COLOR_GREEN;
    
  module.setLED(bgcolor, (counter-1)%8);
  module.setLED(color, pos);
  
  counter = counter+1;
  delay(delay_time);
}
