#ifndef RENDER_OBJECT
#define RENDER_OBJECT
#include "includes.h"
class cRenderObject
{
private:
	bool m_hasShader;
	cVector3df m_currentPosition;
	cVector3df m_currentRotation;
	cVector3df m_currentScale;
	bool m_bVisible;
public:
	ESMatrix	m_MVPMatrix;
	ESMatrix	m_MVMatrix;
	ESMatrix	m_VMatrix;
	ESMatrix	m_MMatrix;
	ESMatrix	m_MVITMatrix;
	ESMatrix	m_MITMatrix;
	
	GLint	m_PositionLoc;
	GLint	m_MLoc;
	GLint	m_VLoc;
	GLint	m_MVITLoc;
	GLint	m_MITLoc;
	GLint	m_MvpLoc;

   eObjectTypes m_Type;

public:
	GLuint m_ProgramObject;
	cRenderObject();
	virtual ~cRenderObject(){};
	virtual void Render();
	virtual void Update(float deltaTime);
	cVector3df getScale(){return m_currentScale;}
	void setScale(cVector3df scale){m_currentScale=scale;}
	cVector3df getPosition(){return m_currentPosition;};
	void setPosition(cVector3df pos){m_currentPosition=pos;}
	bool hasShader(){return m_hasShader;}
	void setVisibility(bool visible){m_bVisible=visible;}
	bool isVisible(){return m_bVisible;}
	void setVSFSShader(const char*);
};
#endif