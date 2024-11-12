


#ifndef RadioLib_h
#define RadioLib_h

#include "SyntaxBase.h"
#include "SPI.h"
#include <cstdint>

 

#define RADIOLIB_ERR_NONE 0
#define RADIOLIB_ERR_CRC_MISMATCH 0




class Module {
public:
	Module(int, int, int, int, SPIClass);
	int      begin(
					float,
					float,
					int,
					int,
					int,
					int,
					int,
					float,
					bool
			 );
	void     setPacketReceivedAction(void (*func)(void));
	void     setPacketSentAction(void (*func)(void));
	void     setFrequency(double);
	void     setBandwidth(double);
	void     setSpreadingFactor(int);
	void     setOutputPower(int);
	int      startReceive();
	int      getPacketLength();
	int      readData(unsigned char[], int);
	int      getRSSI();
	int      getSNR();
	int      getFrequencyError();
	int      finishTransmit();
	int      startTransmit(uint8_t x[], int);
};

class SX1262 : public Module {
public:
	SX1262(Module* module) : Module(*module) {};
};

#endif 






