


#ifndef SSD130Wire_h
#define SSD130Wire_h

#include "SyntaxBase.h"


#define ArialMT_Plain_10 0
#define TEXT_ALIGN_LEFT 0
#define TEXT_ALIGN_RIGHT 1


#define SDA_OLED 4
#define SCL_OLED 5
#define RST_OLED 16

#define ANGLE_180_DEGREE 0


class SSD1306Wire {
  public:
    SSD1306Wire(int, int, int, int, int, int);
    void init();
    void clear();
    void setContrast(int);
    void setFont(int);
    void setTextAlignment(int);
    void drawString(int, int, String);
    void drawString(int, int, String*);
    void display();
    void flipScreenVertically();
	void screenRotate(int);
    void displayOff();
};




#endif 






