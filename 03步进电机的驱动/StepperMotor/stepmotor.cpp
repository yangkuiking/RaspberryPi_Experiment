#include"stepmotor.h"

stepmotor::stepmotor(int iEnable,int iStep,int iDir)
{
   m_iEnable = iEnable;
   m_iStep=iStep;
   m_iDir=iDir;

   pinMode(m_iEnable,OUTPUT); // Enable
   pinMode(m_iStep,OUTPUT); // Step
   pinMode(m_iDir,OUTPUT); // Dir

   digitalWrite(m_iEnable,LOW); // Set Enable low，低电平使能

   m_iSpeedTime=800;

   m_bStop=false;
}

stepmotor::~stepmotor()
{
}

void stepmotor::attachStep(int iMs1,int iMs2,int iMs3)
{
   m_iMs1=iMs1;
   m_iMs2=iMs2;
   m_iMs3=iMs3;

   pinMode(m_iMs1,OUTPUT);
   pinMode(m_iMs2,OUTPUT);
   pinMode(m_iMs3,OUTPUT);

   //默认是低电平，也就是全步进
   digitalWrite(m_iMs1,LOW);
   digitalWrite(m_iMs2,LOW);
   digitalWrite(m_iMs3,LOW);
}

void stepmotor::setDirection(bool bdir)
{
   digitalWrite(m_iDir,bdir); // Set Enable low，低电平使能
}
void stepmotor::setStepMode(bool bMs1,bool bMs2,bool bMs3)
{
   digitalWrite(m_iMs1,bMs1);
   digitalWrite(m_iMs2,bMs2);
   digitalWrite(m_iMs3,bMs3);
}
void stepmotor::setSpeed(int iTime)
{
   m_iSpeedTime=iTime;
}
void stepmotor::write(int iStep)
{
     
  for(int x = 0; x < iStep; x++) // Loop 200 times
  {
      if (m_bStop)
        break;
      digitalWrite(m_iStep,HIGH); // Output high
      delayMicroseconds(m_iSpeedTime); // Wait 1/2 a ms
      digitalWrite(m_iStep,LOW); // Output low
      delayMicroseconds(m_iSpeedTime); // Wait 1/2 a ms
   }
  
}
void stepmotor::write()
{
   for(;;)
  {
     if (m_bStop)
        break;
     
      digitalWrite(m_iStep,HIGH); // Output high
      delayMicroseconds(m_iSpeedTime); // Wait 1/2 a ms
      digitalWrite(m_iStep,LOW); // Output low
      delayMicroseconds(m_iSpeedTime); // Wait 1/2 a ms
   }
}
void stepmotor::stop(bool bstop)
{
   m_bStop=bstop;
}