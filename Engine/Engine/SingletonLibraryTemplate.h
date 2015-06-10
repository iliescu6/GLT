#ifndef SINGLETONLIBRARY
#define SINGLETONLIBRARY
#include <map>
#include "includes.h"


template <class T,class F>
class cLibrary
{
protected:

	std::map<std::string,int> m_MapFilename;
	std::map<int, T *> m_Map;
	int m_currentId;
	F *m_LoadFunction;
	cLibrary():m_currentId(0)
	{
		m_LoadFunction= new F();
	}

public:
	// Load generalModel (texture,or obj,etc)
	T* LoadModel(const char* filename)
	{
		std::fstream f(filename,std::ios::in);
		std::string vsh(filename);
		std::string fsh(filename);
		vsh.append(".vs");
		fsh.append(".fs");
		std::fstream f1(vsh.c_str(),std::ios::in);
		std::fstream f2(vsh.c_str(),std::ios::in);

		if(f.is_open()||(f1.is_open()&&f2.is_open()))
		{
			if(f1.is_open())
			{
				f1.close();
				f2.close();
			}
			map<std::string,int>::iterator iter;
			iter=m_MapFilename.find(std::string(filename));
			if(iter != m_MapFilename.end())
				{
					return m_Map.find(iter->second)->second;
				}
			else
				{
					return m_LoadFunction->LoadLibraryObject(f,std::string(filename), m_currentId,m_MapFilename,m_Map);
				}
			
		
			f.close();
		}
		else
		{
			std::cout<<"Nu gasesc fisierul "<<filename<<"\n";
			assert(1);
		}
		return 0;
	}
	T* LoadModel(const char *filename,std::fstream &f)
	{
		if(f.is_open())
		{
			map<std::string,int>::iterator iter;
			iter=m_MapFilename.find(std::string(filename));
			if(iter != m_MapFilename.end())
				{
					return m_Map.find(iter->second)->second;
				}
			else
				{
					return m_LoadFunction->LoadLibraryObject(f,std::string(filename), m_currentId,m_MapFilename,m_Map,1);
				}			
		}
		else
		{
			std::cout<<"Nu gasesc fisierul "<<filename<<".\n";
			assert(1);
		}
		return 0;
	}
	static cLibrary *getSingleton()
	{
		static cLibrary *t=0;
		if(!t)
			t=new cLibrary<T,F>();
		return t;
	}
	void Release()
	{
		delete cLibrary::getSingleton();
	}
		~cLibrary()
	{

		for(map<int, T *>::iterator i=m_Map.begin();i!=m_Map.end();i++)
		{
			//glDeleteProgram (*i->second  );
			delete (i->second);
		}
		m_Map.clear();
		delete m_LoadFunction;
	}
};
#endif