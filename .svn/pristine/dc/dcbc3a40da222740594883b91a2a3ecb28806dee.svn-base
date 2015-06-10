#ifndef ENGINE_MAIN
#define ENGINE_MAIN
#define ENGINE cEngine::getSingleton()
#include "Includes.h"
class cRenderObject;
class cCamera;
class cBarbarian;
class cTileMap;
class cEngine
{
public:
	ESContext esContext;
	cCamera *m_activeCamera;
	cTileMap	*m_Map;
	cBarbarian	*m_Alina;
	ESMatrix m_PerspectiveMatrix;
private:
	cEngine();

public:
	list<cRenderObject *> m_objects;

public:
	void Init();
	static cEngine*	getSingleton();
	void Release();
	void AddRenderObject(cRenderObject *r);
	void LoadTileMap(const char *filename);
	cTileMap * GetTileMap(){return m_Map;}
	static void Render(ESContext *esContext);
	static void Update(ESContext *esContext, float deltaTime);
	void Run();
	~cEngine();
};

#endif