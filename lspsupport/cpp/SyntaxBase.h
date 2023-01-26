

#ifndef SyntaxBase_h
#define SyntaxBase_h

#include "jibbersmat.h"

#define NULL nullptr

typedef signed char int8_t;
typedef short int16_t;
typedef long int int32_t;
typedef long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;
typedef long unsigned int size_t;




uint8_t  LOW;
uint8_t  HIGH;
uint8_t  INPUT;
uint8_t  OUTPUT;
uint8_t  INPUT_PULLDOWN;
uint8_t  INPUT_PULLUP;
uint16_t SPI_CLOCK_DIV8;
uint16_t MSBFIRST;
uint16_t SPI_MODE0;




void strncpy(char*, char*, uint32_t);
char* strtok(char*, const char*);
char* strtok(char*, char*);
uint16_t atoi(char*);
void memset(char*, char, int);
void memset(uint16_t*, int, int);
void memset(uint8_t[], unsigned char, uint32_t);
void memcpy(uint8_t[], uint8_t[], int);
void memcpy(int16_t[], int16_t[], int);
uint32_t map(int, int, int, int, int);


void digitalWrite(uint8_t, uint8_t);
void digitalWriteFast(uint8_t, uint8_t);
uint8_t digitalRead(uint8_t);
uint8_t analogRead(uint8_t);
void pinResetFast(uint8_t);
void pinSetFast(uint8_t);
uint8_t pinReadFast(uint8_t);
void analogWrite(int, int, int);
void analogWrite(uint8_t);
void analogWrite(uint8_t, uint8_t);
void pinMode(uint8_t, uint8_t);
uint32_t analogWriteResolution(uint8_t, uint8_t);
uint32_t analogWriteResolution(uint8_t);
uint32_t millis();
uint32_t micros();
uint32_t delay(in);
//uint32_t atoi(char*);
//void free(const char *);
//char* strtok(char*, const char *);




void sprintf(char*, const char*, int);
void sprintf(char*, const char*, char*, char*, int, int);
void sprintf(char*, const char*, char*, char*, int);
void sprintf(char*, const char*, int, int, int, int);
void sprintf(char*, const char*, int, int, int, int, int);
void sprintf(char*, const char*, int, int, int, int, int, int, int, int);
void sprintf(char*, const char*, char*, char*, int, int, int);
void sprintf(char*, const char*, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int );
void sprintf(char*, const char*, int, int );
void sprintf(char*, const char*, int, int, int, int, int, int, int, int, int, int, int );
void sprintf(char*, const char*, int, int, int );

void strcat(char*, const char*);
void strcat(char*, char*);



class SPIClass {
  public:
    SPIClass();
    void setClockDivider(uint8_t);
    void setBitOrder(uint8_t);
    void setDataMode(uint8_t);
    uint16_t transfer(uint16_t);
    void begin(uint32_t);
  private:
    void sometin();
};
SPIClass SPI;




class WireClass {
  public:
    WireClass();
    void setSpeed(uint32_t);
    void setClock(uint32_t);
    void beginTransmission(uint32_t);
    void write(uint32_t);
    byte endTransmission();
    byte endTransmission(bool);
    void requestFrom(uint16_t, uint16_t);
    void requestFrom(uint16_t, uint16_t, bool);
    uint16_t available();
    uint16_t read();
    void begin();
    void begin(int, int, int);


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
    void begin(uint32_t, uint32_t, uint32_t, uint32_t);
    void print(char*);
    void print(int);
    void print(String);
    void println(char*);
    void println(int);
    void println(String);
    uint8_t available();
    uint8_t read();

  private:
    void sometin();
};
SerialClass Serial;
SerialClass Serial1;
SerialClass Serial2;




class TimeClass {
  public:
    TimeClass();
    uint32_t now();
    uint32_t hour();
    uint32_t minute();
    uint32_t month();

  private:
    void sometin();
};
TimeClass Time;




class Timer { 
  public:
    Timer(uint32_t, void(*)(), bool);
    Timer(uint32_t, void(*)());
    void start();
    void changePeriod(uint32_t);     
};


int RF_PACONFIG_PASELECT_PABOOST = 0;









#endif 






