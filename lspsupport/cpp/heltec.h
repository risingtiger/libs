

#ifndef HeltecS_h
#define HeltecS_h

#include "SyntaxBase.h"




#define RADIOLIB_ERR_NONE 1
#define SCL_OLED 1
#define SERIAL_8N1 0







void heltec_setup();
void heltec_loop();
void heltec_led(int);







class Display {
  public: 
    Display();
    void println(String);
    void print(String);
    void printf(String, int);
    void printf(String, int, int);
    void printf(String, int, int, int, int, int, int, int, int, int, int, int);
};
Display display;

class Radio {
  public: 
    Radio();
    int begin();
};
Radio radio;






void esp_register_shutdown_handler(void (*shutdown_handler_t)(void)); 
void esp_restart(); 


#endif 






