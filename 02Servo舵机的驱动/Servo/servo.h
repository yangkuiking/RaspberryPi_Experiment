#ifndef Servo_h
#define Servo_h
#include<stdio.h>
#include<wiringPi.h>
#include<softPwm.h>

#define T_CIRCLE 20000//一个周期
#define ONE_DEGREE 1.111111111//一度
class Servo
{
    public:
        Servo(int signal);
        Servo();
        ~Servo();
        void attach(int signal);
        void writeToMin();
        void writeToMax();
        void write(int angle);
        void detach(int signal);
    private:
        int m_isignal;

};

#endif	//servo.h