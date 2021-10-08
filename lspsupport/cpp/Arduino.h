


#ifndef Arduino_h
#define Arduino_h

#include "SyntaxBase.h"



uint8_t A0;
uint8_t A1;
uint8_t A2;
uint8_t A3;


void ledcSetup(uint8_t, uint16_t, uint8_t);
void ledcAttachPin(uint8_t, uint8_t);
void ledcWrite(uint8_t, uint8_t);





#endif 






