#ifndef CMESHLIBRARY
#define CMESHLIBRARY
#include "SingletonLibraryTemplate.h"
class cMesh;
#define MESHLIB cMeshLibrary::getSingleton()
class cMeshLoadFunct
{
public:
	cMeshLoadFunct(){}
	~cMeshLoadFunct(){}
	cMesh* LoadLibraryObject(std::fstream &f,std::string fname,int &m_currentId,std::map<std::string,int> &m_MapFilename,std::map<int, cMesh *> &m_Map,unsigned int mod=0);
};

class cMeshLibrary:public cLibrary<cMesh,cMeshLoadFunct>
{
private:
	cMeshLibrary():cLibrary(){}
	~cMeshLibrary();
};
#endif
