


#ifndef Arduino_h
#define Arduino_h

#include "SyntaxBase.h"

#define SERIAL_8N1 0

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef int int32_t;

#define A0 (uint8_t)0;
#define A1 (uint8_t)1;
#define A2 (uint8_t)2;
#define A3 (uint8_t)3;


void ledcSetup(uint8_t, uint16_t, uint8_t);
void ledcAttachPin(uint8_t, uint8_t);
void ledcWrite(uint8_t, uint8_t);
void ledcDetachPin(uint8_t);
void delay(uint32_t);

void esp_restart();


#define	RAND_MAX	0x7fffffff


#endif 






