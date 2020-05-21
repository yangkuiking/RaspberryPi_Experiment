#include<stdio.h>
#include<wiringPi.h>
#include"servo.h"
#include<iostream>
#include<softPwm.h>
using namespace std;

#define PWM_PIN 13

int main()
{   
    wiringPiSetupGpio();

    Servo servo(PWM_PIN);

    while(1)
    {
        int pos=0;
        for(pos=0;pos<=180;pos++){
              servo.write(pos);
              delay(100);
        }
        for(pos=180;pos>=0;pos--){
              servo.write(pos);
              delay(100);
        }
    }


    while(1)
    {
        int angle=0;
        cin>>angle;
        if(angle==0)
        {
            servo.writeToMin();
            cout<<"finish"<<endl;
        }else if(angle==180)
        {
            servo.writeToMax();
            cout<<"finish"<<endl;
        }else if(angle>0&&angle<180)
        {
            servo.write(angle);
            cout<<"finish"<<endl;
        }
        else
        {
            cout<<"error"<<endl;
        }
        
    }

    return 0;
}