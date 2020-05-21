#ifndef DigitLedDisplay_h
#define DigitLedDisplay_h
#include<stdio.h>
#include<wiringPi.h>
#include<wiringShift.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef unsigned char byte;

const static byte charTable [] = {
    0B01111110,0B00110000,0B01101101,0B01111001,0B00110011,0B01011011,0B01011111,0B01110000,0B01111111,0B01111011
};

class DigitLedDisplay
{
	private:
		int DIN_PIN;
		int CS_PIN;
		int CLK_PIN;
		int _digitLimit;
		void table(byte address, int val);	
	public:
		DigitLedDisplay(int dinPin, int csPin, int clkPin);
		void setBright(int brightness);
		void setDigitLimit(int limit);
		void printDigit(long number, byte startDigit = 0);
		void write(byte address, byte data);
		void clear();
		void on();
		void off();		
};

#endif	//DigitLedDisplay.h
