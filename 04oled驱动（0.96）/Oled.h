#ifndef __OLED__
#define __OLED__
#include<string>
#include<wiringPi.h>
#include<iostream>
#include<wiringPiI2C.h>
using std::string;
typedef unsigned char byte;

class OLed
{
public:
    OLed();
    OLed(int iwidth,int iheight);
    ~OLed();
    void setPos(int x, int y);
    void cls();
    void printf(string str);
    void putchar(int x,int y,byte ch);
    void setWordSize(bool big);
private:
    void WriteCmd(byte I2C_Command);
    void WriteData(byte I2C_Data);
    void OLED_Init();
    void OLED_CLS();
    void OLED_SetPos(int x, int y);
    
private:
    int m_fd;
    int m_iWidth;
    int m_iHeight;
    int m_ix;
    int m_iy;
    bool m_bIsBig;

};
#endif