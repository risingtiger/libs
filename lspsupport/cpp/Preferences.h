


#ifndef Preferences_h
#define Preferences_h

#include "Arduino.h"

class Preferences {
public:
	Preferences();
	void begin(const char*, bool);
	void putString(const char*, const char*);
	bool isKey(const char*);
	void putUInt(const char*, uint32_t);
	void putBool(const char*, bool);
	void putBytes(const char*, bool, uint32_t);
	String getString(const char*);
	uint32_t getUInt(const char*);
	bool getBool(const char*);
	bool getBool(const char*, bool);
	void end();
	void clear();
};

#endif 






