

#ifndef ParticleFill_h
#define ParticleFill_h

#include "SyntaxBase.h"
#include "SPI.h"
 
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef int int32_t;




#define A0 (uint8_t)1
#define A1 (uint8_t)2
#define A2 (uint8_t)3
#define A3 (uint8_t)4
#define A4 (uint8_t)5
#define A5 (uint8_t)6
#define A6 (uint8_t)7
#define A7 (uint8_t)8
#define D0 (uint8_t)9
#define D1 (uint8_t)9
#define D2 (uint8_t)9
#define D3 (uint8_t)10
#define D4 (uint8_t)11
#define D5 (uint8_t)11
#define D6 (uint8_t)11
#define D7 (uint8_t)11
#define D8 (uint8_t)11


#define PRIVATE 0
#define WITH_ACK 0
#define PLATFORM_ID 0
#define CLOCK_SPEED_400KHZ 0
#define FALLING 0
#define RISING 0
#define CHANGE 0
#define time_changed 0
#define LOG_LEVEL_INFO 0
#define SEMI_AUTOMATIC 0
#define ENABLED 0
#define SETTING_FIRMWARE_VERSION 0

#define SYSTEM_MODE(a)
#define SYSTEM_THREAD(a)
#define PRODUCT_VERSION(a)

void attachInterrupt(int, void (*)(), int);



typedef enum {
  BATTERY_STATE_UNKNOWN = 0,
  BATTERY_STATE_NOT_CHARGING = 1,
  BATTERY_STATE_CHARGING = 2,
  BATTERY_STATE_CHARGED = 3,
  BATTERY_STATE_DISCHARGING = 4,
  BATTERY_STATE_FAULT = 5,
  BATTERY_STATE_DISCONNECTED = 6
} battery_state_t;
typedef enum {
  POWER_SOURCE_UNKNOWN = 0,
  POWER_SOURCE_VIN = 1,
  POWER_SOURCE_USB_HOST = 2,
  POWER_SOURCE_USB_ADAPTER = 3,
  POWER_SOURCE_USB_OTG = 4,
  POWER_SOURCE_BATTERY = 5
} power_source_t;




SPIClass SPI;




class ParticleClass {                                                                                                                                               
  public:                                                                                                                                                        
    ParticleClass();                                                         
    void variable(const char*, int);                                                                                                                                                
    bool function(const char*, int(*)(String));
    void disconnect();
    void connect();
    bool connected();
    bool publish(const char*, const char*, int);
};
ParticleClass Particle;




class PMIC {
  public:
    PMIC(bool);
	int getVbusStat();
	int getChargingStat();
	bool    getDPMStat();
	bool    isPowerGood();
	bool    getVsysStat();


	~PMIC();
};
//PMICClass PMIC;




class CellularSignal {
  public:
    CellularSignal();
    float getStrength();
    float getQuality();
};
CellularSignal CellularSignal_I;




class WiFiClass {
  public:
    WiFiClass();
    WiFiClass RSSI();
    void off();
    void on();
};
WiFiClass WiFi;




class CellularClass {
  public:
    CellularClass();
    CellularSignal RSSI();
    void off();
    void on();
};
CellularClass Cellular;




class EEPROMClass {
  public:
    EEPROMClass();
    void get(int, int);
    void put(int, int);
};
EEPROMClass EEPROM;




class BLEClass {                                                                                                                                               
  public:                                                                                                                                                        
    BLEClass();                                                         
    void on();                                                         
    bool off();                                                                                                                                                
};
BLEClass BLE();




class SystemSleepConfiguration {
  public:
    SystemSleepConfiguration();
    SystemSleepConfiguration& mode(int);
    SystemSleepConfiguration& duration(int);
};

class SystemSleepResult {
  public:
    SystemSleepResult();
    SystemSleepConfiguration& mode(int);
    SystemSleepConfiguration& duration(int);
};

class SystemSleepMode {
  public:
    SystemSleepMode();
    static int ULTRA_LOW_POWER;
};




class RGBClass {                                                                                                                                               
  public:                                                                                                                                                        
    RGBClass();                                                         
    void control(bool);                                                         
    void color(int, int, int);                                                                                                                                                
    void brightness(int);
};
RGBClass RGB;




class SerialLogHandler {                                                                                                                                               
  public:                                                                                                                                                        
    SerialLogHandler();                                                         
    void error(const char *x);                                                         
    void info(const char *x, ...);                                                         
};
SerialLogHandler Log;




struct PublishFlags {                                                                                                                                               
  int propa;
};




class SystemClass {
  public:
    static void reset();
    void deviceID(void);
    int batteryState();
    int powerSource();
    void on(int, void (*)());
    SystemSleepResult sleep(SystemSleepConfiguration);
};

extern SystemClass System;




#endif 






