


#ifndef SSD130Wire_h
#define SSD130Wire_h

#include "SyntaxBase.h"


#define ArialMT_Plain_10 0
#define TEXT_ALIGN_LEFT 0
#define TEXT_ALIGN_RIGHT 1


class SSD1306Wire {
  public:
    SSD1306Wire(int, int, int, int);
    void init();
    void clear();
    void setContrast(int);
    void setFont(int);
    void setTextAlignment(int);
    void drawString(int, int, String);
    void display();
    void flipScreenVertically();
    void displayOff();
};




#endif 






