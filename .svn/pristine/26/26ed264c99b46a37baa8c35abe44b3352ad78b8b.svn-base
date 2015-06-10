#ifndef CLIGHT
#define CLIGHT
#include "includes.h"
class cLight
{
private:
	cVector3df m_currentPosition;

public:
	cLight();
	void setPosition(cVector3df pos){m_currentPosition=pos;}
	cVector3df getPosition(){return m_currentPosition;}
	void  Update(float deltaTime);
};
#endif