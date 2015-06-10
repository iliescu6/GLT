#include "Skybox.h"
#include "Engine.h"
#include "Camera.h"
cSkyboxObject::cSkyboxObject():cMeshObject()
{
		
}
cSkyboxObject::~cSkyboxObject()
{
}
void cSkyboxObject::Render()
{
	glDisable ( GL_DEPTH_TEST);
	cMeshObject::Render();

	glEnable ( GL_DEPTH_TEST);
}

void cSkyboxObject::Update(float deltaTime)
{
	setPosition(ENGINE->m_activeCamera->getPosition());
	cMeshObject::Update(deltaTime);
}