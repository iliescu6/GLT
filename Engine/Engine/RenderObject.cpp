#include "RenderObject.h"
#include "Includes.h"
#include "Engine.h"
#include "Camera.h"
#include "ShaderLibrary.h"
#include <math.h>

cRenderObject::cRenderObject()
{
	m_currentPosition.x=m_currentPosition.y=m_currentPosition.z=0;
	m_currentRotation.x=m_currentRotation.y=m_currentRotation.z=0;
	m_currentScale.x=m_currentScale.y=m_currentScale.z=1;
	m_hasShader=false;
	m_bVisible=true;
	esMatrixLoadIdentity( &m_MVPMatrix );
	m_Type=UNKNOWN;
}

void cRenderObject::Update(float deltaTime)
{
	
  ESMatrix modelview;
 
   // Generate a model view matrix to rotate/translate the cube
   esMatrixLoadIdentity( &m_MMatrix );
   esTranslate(&m_MMatrix,m_currentPosition.x,m_currentPosition.y,m_currentPosition.z);
   esScale(&m_MMatrix,m_currentScale.x,m_currentScale.y,m_currentScale.z);
   
   esMatrixMultiply(&modelview,&m_MMatrix,&ENGINE->m_activeCamera->View);
   
   esMatrixMultiply( &m_MVPMatrix, &modelview, &ENGINE->m_PerspectiveMatrix );
}
void cRenderObject::Render()
{   

	if(hasShader())
	{
			glUseProgram ( m_ProgramObject );
	}
}
void cRenderObject::setVSFSShader(const char *te)
{
	m_hasShader=true;
	m_ProgramObject=SHADERLIB->LoadModel(te)->shader;
   m_PositionLoc = glGetAttribLocation ( m_ProgramObject, "a_position" );
   m_MvpLoc = glGetUniformLocation( m_ProgramObject, "u_mvpMatrix" );
    m_MLoc = glGetUniformLocation( m_ProgramObject, "u_mMatrix" );
	m_VLoc = glGetUniformLocation( m_ProgramObject, "u_vMatrix" );
	m_MVITLoc=glGetUniformLocation( m_ProgramObject, "u_mvitMatrix" );
	m_MITLoc=glGetUniformLocation( m_ProgramObject, "u_mitMatrix" );
}