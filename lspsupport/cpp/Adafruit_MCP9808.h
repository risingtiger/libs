


#ifndef Adafruit_MCP9808_h
#define Adafruit_MCP9808_h

#include "SyntaxBase.h"


typedef struct {
	union {
		float temperature; 
	};                
} sensors_event_t;




class Adafruit_MCP9808 {
  public:
    Adafruit_MCP9808();
	void getEvent(sensors_event_t*);
	bool begin();
	bool begin(WireClass*);
};


#endif 






