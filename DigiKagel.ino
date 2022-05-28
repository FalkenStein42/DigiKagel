#include "LED_map.h"

byte LED_positions_1 = 0; //byte holding LED positios 1 - 7
byte LED_positions_2 = 0; //byte holding LED positios 8 - 14 

void setup() {
  //LED pin initialization
  pinMode(position_1_PIN, OUTPUT); //Position 1 pin
  pinMode(position_2_PIN, OUTPUT); //Position 2 pin
  pinMode(position_3_PIN, OUTPUT); //Position 3 pin
  pinMode(position_4_PIN, OUTPUT); //Position 4 pin
  pinMode(position_5_PIN, OUTPUT); //Position 5 pin
  pinMode(position_6_PIN, OUTPUT); //Position 6 pin
  pinMode(position_7_PIN, OUTPUT); //Position 7 pin
  pinMode(position_8_PIN, OUTPUT); //Position 8 pin
  pinMode(position_9_PIN, OUTPUT); //Position 9 pin
  pinMode(position_10_PIN, OUTPUT); //Position 10 pin
  pinMode(position_11_PIN, OUTPUT); //Position 11 pin
  pinMode(position_12_PIN, OUTPUT); //Position 12 pin
  pinMode(position_13_PIN, OUTPUT); //Position 13 pin

  
}


void loop() {
  //Check if changes have been made
  
}

void write_position(short pos, boolean state) {
  
  //TODO: Assert pos
  
  if (state) {
    digitalWrite(pos_to_pin[ pos - 1 ], HIGH);
    }
  else {
    digitalWrite(pos_to_pin[ pos - 1 ], LOW);
    }

  write_memory(pos,state);
    
  }

void write_memory(short pos, boolean state){
  
  //TODO: Assert pos
  
  if (state) { //Write a high
    if (pos<=7){ //Write a high on positions 1-7
      LED_positions_1 = ( (1 << ( pos - 1) ) | LED_positions_1 );
      }
    else { //Write a high on positions 8-13
      LED_positions_2 = ( (1 << ( pos - 1) ) | LED_positions_2 );
      }
    }
  else { //Write a low
    if (pos<=7){ //Write a low on positions 1-7
      LED_positions_1 = ( ( ~(1 << ( pos - 1) ) ) & LED_positions_1 );
      }
    else { //Write a low on positions 8-13
      LED_positions_2 = ( ( ~(1 << ( pos - 1) ) ) & LED_positions_2 );
      }
    }
  
  }


bool read_memory(short pos) {
  
  //TODO: Assert pos

  int res;
  
  if (pos<7){   //Return state of positions 1-7
      res = ( LED_positions_1 & (1 << ( pos - 1) ) );
    }
  else {        //Return state of positions 8-13
      res = ( LED_positions_2 & (1 << ( pos - 1) ) );
    }

  return res;
  }


byte check_flag(byte LED_positions) {
  return ( LED_positions & 1 );
  }
