

#ifndef ParticleFill_h
#define ParticleFill_h

#include "SyntaxBase.h"




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

uint8_t  PRIVATE;
uint8_t  WITH_ACK;
uint8_t  PLATFORM_ID;
uint32_t CLOCK_SPEED_400KHZ;
uint8_t  FALLING;
uint8_t  RISING;
uint8_t  CHANGE;
uint8_t  time_changed;
uint8_t  LOG_LEVEL_INFO;

void SYSTEM_THREAD(int);
void PRODUCT_ID(int);                                                                     
void PRODUCT_VERSION(int);

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



void SYSTEM_THREAD(uint8_t);
void PRODUCT_ID(uint32_t);                                                                                                                                                   
void PRODUCT_VERSION(uint32_t);
void attachInterrupt(int, void (*)(), int);




class ParticleClass {                                                                                                                                               
  public:                                                                                                                                                        
    ParticleClass();                                                         
    void variable(const char*, int);                                                                                                                                                
    void variable(const char*, String);                                                                                                                                                
    void function(const char*, int(*)(String));
    void disconnect();
    void connect();
    bool connected();
};
ParticleClass Particle;




class PMIC {
  public:
    PMICClass();
    bool isPowerGood();
};




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
    WiFiSignal RSSI();
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
BLEClass BLE;




class SystemSleepConfiguration {
  public:
    SystemSleepConfiguration();
    SystemSleepConfiguration& mode(uint32_t);
    SystemSleepConfiguration& duration(uint32_t);
};

class SystemSleepResult {
  public:
    SystemSleepResult();
    SystemSleepConfiguration& mode(uint32_t);
    SystemSleepConfiguration& duration(uint32_t);
};

class SystemSleepMode {
  public:
    SystemSleepMode();
    static uint8_t ULTRA_LOW_POWER;
};




class SystemClass {                                                                                                                                               
  public:                                                                                                                                                        
    SystemClass();                                                         
    void on(uint8_t, void[](){});                                                         
    void reset();                                                         
    bool deviceID();                                                                                                                                                
    int batteryState();
    SystemSleepResult sleep(SystemSleepConfiguration);
};
SystemClass System;




class RGBClass {                                                                                                                                               
  public:                                                                                                                                                        
    RGB();                                                         
    void control(bool);                                                         
    void color(int, int, int);                                                                                                                                                
    void brightness(int);
};
RGBClass RGB;




class SerialLogHandler {                                                                                                                                               
  public:                                                                                                                                                        
    SerialLogHandler(uint8_t);                                                         
    info(char*, ...);                                                         
};
SerialLogHandler Log;



#endif 






