#include<stdio.h>
#include<wiringPi.h>
#include"stepmotor.h"
#include<iostream>
using namespace std;


int main()
{   
    wiringPiSetup();

    stepmotor servo(27,28,29);

    servo.write();

    return 0;
}