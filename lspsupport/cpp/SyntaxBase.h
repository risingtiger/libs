

#ifndef SyntaxBase_h
#define SyntaxBase_h

//#include "jibbersmat.h"

#define NULL nullptr

//typedef char byte;
//typedef signed char int8_t;
//typedef short int16_t;
//typedef long int int32_t;
//typedef unsigned char uint8_t;
//typedef unsigned short int;
//typedef long unsigned int int;




#define LOW  0
#define HIGH  1
#define INPUT  0
#define OUTPUT  1
#define INPUT_PULLDOWN  2
#define INPUT_PULLUP  3
#define SPI_CLOCK_DIV8  3
#define MSBFIRST  3
#define SPI_MODE0  3
#define GPIO_NUM_0  0
#define  GPIO_NUM_8  3
#define GPIO_NUM_9  0
#define GPIO_NUM_10  0
#define GPIO_NUM_11  0
#define  GPIO_NUM_12  3
#define  GPIO_NUM_13  3
#define  GPIO_NUM_14  3
#define GPIO_NUM_17 0
#define GPIO_NUM_18 0
#define GPIO_NUM_21 0
#define GPIO_NUM_35 0
#define GEOMETRY_128_64 0




void strncpy(char*, char*, int);
char* strtok(char*, const char*);
int atoi(char*);
void memset(char*, char, int);
void memcpy(int[], int[], int);
int map(int, int, int, int, int);


void digitalWrite(int, int);
void digitalWriteFast(int, int);
int digitalRead(int);
int analogRead(int);
void pinResetFast(int);
void pinSetFast(int);
int pinReadFast(int);
void analogWrite(int, int, int);
void pinMode(int, int);
int analogWriteResolution(int, int);
int millis();
int micros();
//int delay(in);
//int atoi(char*);
//void free(const char *);
//char* strtok(char*, const char *);



template <typename ...ArgsT>
void sprintf(char*, const char*, ArgsT...);

void strcat(char*, const char*);
void strcat(char*, char*);







class WireClass {
  public:
    WireClass();
    void setSpeed(int);
    void setClock(int);
    void beginTransmission(int);
    void write(int);
    char endTransmission();
    void requestFrom(int, int, bool);
    int available();
    int read();
    void begin();


  private:
    void sometin();
};
WireClass Wire;




class String {
  public:
    String();
    String(int);
    String(int* x);
    String(const int* x);
    String(char*);
    String(const char*);
    String(const char*, int);
    String(const char*, unsigned char);
    char* c_str();
    bool equals(String);
    int toInt();

  private:
    void sometin();
};




class SerialClass {
  public:
    SerialClass();
    void begin(int);
    void begin(int, int, int, int);
    void print(String);
    void println(int);
    void println(const char[]);
    int available();
    int read();

  private:
    void sometin();
};
SerialClass Serial;
SerialClass Serial1;




class TimeClass {
  public:
    TimeClass();
    int now();
    int hour();
    int minute();
    int second();
    int month();
    bool     isValid();

  private:
    void sometin();
};
TimeClass Time;




class Timer { 
  public:
    Timer(int, void(*)(), bool);
    Timer(int, void(*)());
    void start();
    void changePeriod(int);     
};


int RF_PACONFIG_PASELECT_PABOOST = 0;



template <typename ...ArgsT>
void memcpy(ArgsT ...args);





#endif 






