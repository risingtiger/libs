


#ifndef LoRaWan_APP_h
#define LoRaWan_APP_h


#include <cstdint>

#define LoRaWan_APP___DEFPLACEHOLDER 0
#define MODEM_LORA 1


typedef struct {
    void (*TxDone)(void);
    void (*TxTimeout)(void);
	void (*RxDone)(uint8_t* payload, uint16_t size, int16_t rssi, int8_t snr);
} RadioEvents_t;



class Radio_t {
  public:
    Radio_t();
    void Init(RadioEvents_t*);
    void SetChannel(int);
	void SetTxConfig(int modem, int power, int fdev, int bandwidth, int datarate, int coderate, int preambleLen, bool fixLen, bool crcOn, bool freqHopOn, int hopPeriod, bool iqInverted, int y);
	void SetRxConfig(int, int, int, int, int, int, int, int, bool, int, int, int, int, bool);
	void Send(uint8_t* payload, uint16_t size);
	void Rx(int);
	void IrqProcess(void);
	void Sleep(void);
};
Radio_t Radio;

#endif 






