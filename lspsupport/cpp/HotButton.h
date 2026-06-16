


#ifndef HotButton_y
#define HotButton_y

#include "SyntaxBase.h"


class HotButton {
  public:
    HotButton(int);
    void update();
    bool isSingleClick();
    bool pressedFor(int);
};

#endif 






