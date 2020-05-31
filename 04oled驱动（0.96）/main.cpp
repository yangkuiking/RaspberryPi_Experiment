#include<stdio.h>
#include<wiringPi.h>
#include<iostream>
#include<wiringPiI2C.h>
#include"Oled.h"
using namespace std;

int main()
{
    wiringPiSetup();
    OLed led;
    led.cls();
    //led.setWordSize(true);

    led.printf("abcdefghijklmnopqrstuvwxyz##abcdefghijklmnopqrstuvwxyz##abcdefghijklmnopqrstuvwxyz##abcdefghijklmnopqrstuvwxyz");

    

    //led.setPos(0,0);
    //led.printf("test ");
    return 0;
}
