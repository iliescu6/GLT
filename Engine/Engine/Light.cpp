
#include "Light.h"
#include <math.h>
cLight::cLight()
{
	m_currentPosition.x=m_currentPosition.y=m_currentPosition.z=0;
}
void cLight::Update(float deltaTime)
{
	static float timetotal=0;
	timetotal+=deltaTime;
	if(timetotal>360)
		timetotal=0;
	m_currentPosition.x=10*sin(timetotal);
	m_currentPosition.y=4.0f;
	m_currentPosition.z=10*cos(timetotal);
}