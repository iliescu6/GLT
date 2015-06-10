
#include "Engine.h"
#include "RenderObject.h"
#include "Camera.h"
#include "MeshLibrary.h"
#include "TextureLibrary.h"
#include "ShaderLibrary.h"
#include "MeshObject.h"
#include "Skybox.h"
#include "InputManager.h"
#include "TileMap.h"
#include "Barbarian.h"
cEngine ::cEngine()
{	
	Init();
}

cEngine::~cEngine()
{
	for(list<cRenderObject*>::iterator i=m_objects.begin();i!=m_objects.end();i++)
		delete (*i);

	m_objects.clear();
	delete	m_activeCamera;
}
void cEngine::Init()
{	
	esInitContext ( &esContext );
	esCreateWindow ( &esContext, "Creation Programming", screen_width, screen_heigth, ES_WINDOW_DEPTH );

	glClearColor ( 1.0f, 0.0f, 0.0f, 0.0f );
	glEnable(GL_DEPTH_TEST);
	esRegisterDrawFunc ( &esContext, Render );
	esRegisterUpdateFunc ( &esContext, Update );
	esRegisterKeyFunc (&esContext, cInputManager::Update );
	
	m_activeCamera=new cCamera();   
	m_Alina= new cBarbarian();

}
void cEngine::LoadTileMap(const char *filename)
{

	cSkyboxObject *sky=new cSkyboxObject();
	sky->LoadModel("link/skybox.radu");
	AddRenderObject((cRenderObject*)sky);
	m_Map=new cTileMap;
	m_Map->LoadMap(filename);
	m_Map->CreateSceneObjects();
}
void cEngine::AddRenderObject(cRenderObject *r)
{
	m_objects.push_back(r);
}
void cEngine::Run()
{

	esMainLoop ( &esContext );
}
cEngine * cEngine::getSingleton()
{
	static cEngine *m_Engine=0;
	if(!m_Engine)
		m_Engine=new cEngine();
	return m_Engine;
}
void cEngine::Render(ESContext *esContext)
{
		glClearColor(0.0f, 0.0f, 0.5f, 0.5);			
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
		
		glViewport ( 0, 0, ENGINE->esContext.width, ENGINE->esContext.height );
		glClear ( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
		  // Generate a perspective matrix with a 60 degree FOV
		float aspect=screen_width/screen_heigth;
		esMatrixLoadIdentity( &ENGINE->m_PerspectiveMatrix );
		esPerspective( &ENGINE->m_PerspectiveMatrix, 60.0f, aspect, 1.0f, 1000.0f );
		for(list<cRenderObject*>::iterator i=ENGINE->m_objects.begin();i!=ENGINE->m_objects.end();i++)
			if((*i)->isVisible())
				(*i)->Render();
		
		eglSwapBuffers ( ENGINE->esContext.eglDisplay,ENGINE->esContext.eglSurface );
}

void cEngine::Update(ESContext *esContext, float deltaTime)
{
	ENGINE->m_activeCamera->Update(deltaTime);
	for(list<cRenderObject*>::iterator i=ENGINE->m_objects.begin();i!=ENGINE->m_objects.end();i++)
		(*i)->Update(deltaTime);
}
void cEngine::Release()
{
	delete	m_Map;
	TEXLIB->Release();
	SHADERLIB->Release();
	MESHLIB->Release();
	INPUT->Release();
	delete getSingleton();

}