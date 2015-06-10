
#include <math.h>
#include "Camera.h"
#include "Engine.h"
#include "InputManager.h"

cCamera::cCamera()
{
	cVector2di mouse=INPUT->getMousePos();
	 m_prevMouseX=mouse.x;
	 m_prevMouseY=mouse.y;
	 m_enabled=false;
	 m_currentPos.x = 19;
	 m_currentPos.y = 35;
	 m_currentPos.z = 19;
	 m_currentRot.x = 0;
	 m_currentRot.y = 0;
	 m_currentRot.z= 90;
	 m_speed=10.0;

}
cCamera::~cCamera()
{

}
void cCamera::move(cVector3df pos)
{
	m_currentPos.x+=pos.x;
	m_currentPos.y+=pos.y;
	m_currentPos.z+=pos.z;
	
}
void cCamera::rotate(cVector3df rot)
{
	m_currentRot.x+=rot.x;
	m_currentRot.y+=rot.y;
	m_currentRot.z+=rot.z;
}
void cCamera::Update(float deltaTime)
{
	UpdateInput(deltaTime);
	esMatrixLoadIdentity( & Camera );
	if(m_enabled)
	{
		cVector2di mousePos=INPUT->getMousePos();
		float rotatex=(float)(mousePos.x-m_prevMouseX);
		float rotatey=(float)(mousePos.y-m_prevMouseY);
		m_currentRot.x+=rotatex;
		m_currentRot.z+=rotatey;
		m_prevMouseX=mousePos.x;
		m_prevMouseY=mousePos.y;
	}


	esTranslate(&Camera,m_currentPos.x,m_currentPos.y,m_currentPos.z);
	esRotate(&Camera,m_currentRot.x,0,1,0);
	esRotate(&Camera,m_currentRot.z,1,0,0);
	
	InverseMatrix(Camera,View);
}
void cCamera::UpdateInput(float deltaTime)
{
	cVector3df ter(0.0f,0.0f,-m_speed *deltaTime), ter2(-m_speed *deltaTime,0.0f,0.0f),ter3(m_speed *deltaTime,0.0f,0.0f),ter4(0.0f,0.0f,m_speed *deltaTime);
	cVector3df Front,Left,Right,Back;
	VectorRotate(ter,ENGINE->m_activeCamera->Camera,Front);
	VectorRotate(ter2,ENGINE->m_activeCamera->Camera,Left);
	VectorRotate(ter3,ENGINE->m_activeCamera->Camera,Right);
	VectorRotate(ter4,ENGINE->m_activeCamera->Camera,Back);
	if(INPUT->getMouseButtonState(LEFT_MOUSE_BUTTON))
		setEnabledMouse();
	if(!INPUT->getMouseButtonState(LEFT_MOUSE_BUTTON))
		setDisabledMouse();
	if(INPUT->getKey('W')||INPUT->getKey('w'))
		move(Front);
	if(INPUT->getKey('S')||INPUT->getKey('s'))
		move(Back);
	if(INPUT->getKey('A')||INPUT->getKey('a'))
		move(Left);
	if(INPUT->getKey('D')||INPUT->getKey('d'))
		move(Right);
	if(INPUT->getKey('R')||INPUT->getKey('r'))
		move(cVector3df(0,0.1f,0));
	if(INPUT->getKey('F')||INPUT->getKey('f'))
		move(cVector3df(0,-0.1f,0));
	

}
void cCamera::setEnabledMouse()
{
	m_enabled=true;
}
void cCamera::setDisabledMouse()
{
	m_enabled=false;
}
void cCamera::Move(cVector3df ammount)
{
}
void cCamera::Rotate(cVector3df rotation)
{
}