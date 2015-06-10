#ifndef CCAMERA
#define CCAMERA
#include "Includes.h"

class cCamera
{
private:	
	cVector3df m_currentPos;
	cVector3df m_actualPos;
	cVector3df m_prevPos;
	cVector3df m_currentRot;
	float m_speed;
	bool m_enabled;
	int m_prevMouseX;
	int m_prevMouseY;
public:
	ESMatrix View;
	ESMatrix Camera;


public:
	cCamera();
	~cCamera();
	void setEnabledMouse();
	void setDisabledMouse();
	void UpdateInput(float deltaTime);
	void setPosition(cVector3df pos){m_currentPos=pos;}
	void setRotation(cVector3df rot){m_currentRot=rot;}
	void move(cVector3df tr);
	void rotate(cVector3df rot);
	cVector3df getPosition(){return m_currentPos;}
	cVector3df getRotation(){return m_currentRot;}
	void Move(cVector3df ammount);
	void Rotate(cVector3df rotation);
	void Update(float deltaTime);
};
#endif