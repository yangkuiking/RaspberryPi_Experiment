#ifndef StepMotor_h
#define StepMotor_h
#include<wiringPi.h>

class stepmotor
{
private:
    int m_iEnable;//使能引脚 enable
    int m_iStep;//控制转 step
    int m_iDir;//控制方向 dir

    //Microstepping Resolution Truth Table
    int m_iMs1;
    int m_iMs2;
    int m_iMs3;

    int m_iSpeedTime;
    bool m_bStop;
public:
    stepmotor(int iEnable,int iStep,int iDir);
    ~stepmotor();
    void attachStep(int iMs1,int iMs2,int iMs3);
    void setStepMode(bool bMs1,bool bMs2,bool bMs3);
    void setDirection(bool bdir);
    void setSpeed(int iTime);
    void write(int iStep);
    void write();
    void stop(bool bstop);
};


#endif	//stepmotor.h