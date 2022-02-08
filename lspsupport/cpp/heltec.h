

#ifndef HeltecS_h
#define HeltecS_h

#include "SyntaxBase.h"




#define SDA_OLED 1
#define SCL_OLED 1



class Display {
    public:
        Display();
        void init();
        void flipScreenVertically();
        void setFont(uint8_t);
        void clear();
        void drawString(int, int, String);
        void display();
        void setColor(uint8_t);
        void fillRect(uint16_t, uint16_t, uint16_t, uint16_t);
        void setTextAlignment(uint8_t);
};
Display displayInst;




class HeltecClass { 
  public: 
    HeltecClass(); 
    void begin(bool, bool, bool, int, int); 
    Display* display 
}; 
HeltecClass Heltec; 




class LoRaClass {
  public: 
    LoRaClass();
    uint8_t parsePacket();
    void receive();
    uint8_t read();
    void beginPacket();
    void setTxPower(uint8_t, int8_t);
    void print(String);
    void write(uint8_t);
    void endPacket();
    bool available();
};
LoRaClass LoRa;




class EEPROMClass {
  public: 
    EEPROMClass();
    void begin(int);
    int read(int);
    void write(int, int);
    void commit();
};
EEPROMClass EEPROM;




#define SERIAL_8N1 1
#define ArialMT_Plain_10 3
#define TEXT_ALIGN_LEFT 3
#define BLACK 3
#define WHITE 3
/*
*/
//uint8_t* HeltecCommsLoopIt(uint32_t cmillis) {
//uint8_t A1;
//uint8_t A2;
//uint8_t A3;
//uint8_t D2;
//uint8_t D3;
//uint8_t D4;

/* uint8_t ArialMT_Plain_10 = 0; */
/* uint8_t BLACK = 0; */
/* uint8_t WHITE = 0; */
/* uint8_t BAND = 0; */
/* uint32_t RF_PACONFIG_PASELECT_PABOOST = 0; */
/* uint8_t TEXT_ALIGN_LEFT = 0; */
/* uint8_t SERIAL_8N1 = 0; */
/* uint8_t SDA_OLED = 0; */
/* uint8_t SCL_OLED = 0; */




void esp_register_shutdown_handler(void (*shutdown_handler_t)(void)); 
void esp_restart(); 
/* void ledcAttachPin(int, int); */
/* void ledcSetup(int, int, int); */
/* void ledcWrite(int, int); */









  //LoRa.beginPacket();
  //LoRa.setTxPower(14, RF_PACONFIG_PASELECT_PABOOST);
  //LoRa.print(toSend);
  //LoRa.endPacket();





#endif 






