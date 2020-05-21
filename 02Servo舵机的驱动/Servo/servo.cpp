#include"servo.h"

Servo::Servo()
{

}
Servo::Servo(int signal)
{
    m_isignal=signal;

    pinMode(m_isignal,PWM_OUTPUT);

    pwmSetMode(PWM_MODE_MS);

    pwmSetRange(2000);

    pwmSetClock(192);
}
Servo::~Servo()
{

}

void Servo::attach(int signal)
{
    m_isignal=signal;
    pinMode(m_isignal,PWM_OUTPUT);

    pwmSetMode(PWM_MODE_MS);

    pwmSetRange(2000);

    pwmSetClock(192);
}

void Servo::writeToMin()
{
    pwmWrite(m_isignal,50);
}
void Servo::writeToMax()
{
     pwmWrite(m_isignal,250);
}
void Servo::write(int angle)
{
    int iAngle=0;

    iAngle=ONE_DEGREE*angle;
    pwmWrite(m_isignal,50+iAngle);
}