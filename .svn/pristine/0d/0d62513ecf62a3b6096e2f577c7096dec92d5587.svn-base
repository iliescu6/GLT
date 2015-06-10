#ifndef CTEXTURELIBRARY
#define CTEXTURELIBRARY
#include "SingletonLibraryTemplate.h"

#define TEXLIB cTextureLibrary::getSingleton()
class cTextureDummy
{
public:
	GLuint tex;
	cTextureDummy(){}
	~cTextureDummy()
	{
		glDeleteTextures(1,&tex);
	}
};
class cTextureLoadFunct
{
public:
	GLuint LoadTexture2D(const char *filename);
	GLuint LoadTextureCube(std::fstream &f);
	cTextureLoadFunct(){}
	~cTextureLoadFunct(){}
	cTextureDummy* LoadLibraryObject(std::fstream &f,std::string fname,int &m_currentId,std::map<std::string,int> &m_MapFilename,std::map<int, cTextureDummy *> &m_Map,unsigned int mod=0);
};

class cTextureLibrary:public cLibrary<cTextureDummy,cTextureLoadFunct>
{
private:
	cTextureLibrary():cLibrary(){}
	~cTextureLibrary();
};
#endif
