


#ifndef SPI_h
#define SPI_h

#include "SyntaxBase.h"

class SPIClass {
  public:
    SPIClass();
    SPIClass(int _);
    void setClockDivider(int);
    void setBitOrder(int);
    void setDataMode(int);
    int transfer(int);
    void begin(int);
    void begin(int, int, int, int);
  private:
    void sometin();
};
#define HSPI 0

#endif 






