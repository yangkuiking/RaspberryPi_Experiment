#include<stdio.h>
#include<wiringPi.h>
#include<wiringShift.h>
#include <wiringPiSPI.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include "DigitLedDisplay.h"

using namespace std;

int CLK = 14;
int CS = 26;
int DIN = 13; //这里定义了那三个脚

int main()
{
    wiringPiSetup();
    DigitLedDisplay dl(DIN,CS,CLK);

    dl.setBright(10);
    dl.setDigitLimit(8);

    for(int i=0;i<1000000;i++)
    {
        dl.printDigit(i);
        delay(500); 
    }

    return 0;
}