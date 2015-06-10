#ifndef C_SHADERLIBRARY
#define C_SHADERLIBRARY
#include "includes.h"
#include "SingletonLibraryTemplate.h"
#define SHADERLIB cShaderLibrary::getSingleton()
class cShaderDummy
{
public:
	GLuint shader;
	 cShaderDummy(){}
	 ~cShaderDummy()
	{
		glDeleteProgram (shader );
	}
};
class cShaderLoadFunct
{
public:
	cShaderLoadFunct(){}
	~cShaderLoadFunct(){}
	GLuint setVSFSShader(const char *te);
	int setShader(GLenum type,const char *file);
	cShaderDummy* LoadLibraryObject(std::fstream &f,std::string fname,int &m_currentId,std::map<std::string,int> &m_MapFilename,std::map<int, cShaderDummy *> &m_Map,unsigned int mod=0);
};

class cShaderLibrary:public cLibrary<cShaderDummy,cShaderLoadFunct>
{

private:
	cShaderLibrary():cLibrary(){}
	~cShaderLibrary();
};
#endif