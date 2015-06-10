#ifndef MESHOBJECT
#define MESHOBJECT
#include "RenderObject.h"
class cMesh;
class cMeshObject:public cRenderObject
{
protected:
	std::vector<cTexture> m_extraTextures;
	cMesh *m_meshPointer;
	GLint m_TexCoordLoc;
	GLint m_NormalCoordLoc;
	GLint m_TextureId;
	GLint m_SamplerLoc;
	GLint m_NormalMatrixLoc;
	GLint m_lifeLoc;
	GLint m_CamPosLoc;
	GLint m_ScreenTextureId;
	GLint m_ScreenTextureLoc;
	float m_LifeTime;

public:
	cMeshObject();
	~cMeshObject();
	virtual void Render();
	virtual void RenderToTex();
	void setScreenTex(GLint stex){m_ScreenTextureId=stex;}
	virtual void Update(float deltaTime);
	int	LoadModel(const char*);
	int LoadRaduFile(fstream &file);
	GLuint LoadTexture2D(const char *filename);
	GLuint LoadTextureCube(std::fstream &f);
};
#endif