#include "TextureLibrary.h"

GLuint cTextureLoadFunct::LoadTexture2D(const char *filename)
{
   GLuint textureId1;
   int width,height;
   char *data=esLoadTGA ((char*) filename,&width,&height  );
   assert(data);
   glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );
   glGenTextures ( 1, &textureId1 );
   glBindTexture ( GL_TEXTURE_2D, textureId1 );
   glTexImage2D ( GL_TEXTURE_2D, 0, GL_RGB, height, width, 0, GL_RGB, GL_UNSIGNED_BYTE, data );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
   delete []data;
   return textureId1;
}
GLuint cTextureLoadFunct::LoadTextureCube(std::fstream &f)
{
	GLuint textureId;
	char name[512];

	f>>name;
	int width,height;

	// Generate a texture object
	glGenTextures ( 1, &textureId );

	// Bind the texture object
	glBindTexture ( GL_TEXTURE_CUBE_MAP, textureId );
	char *data=esLoadTGA ((char*) name,&width,&height  );
	// Load the cube face - Positive X
	glTexImage2D ( GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, width,height, 0, 
		GL_RGB, GL_UNSIGNED_BYTE, data );
	delete []data;
	f>>name;
	data=esLoadTGA ((char*) name,&width,&height  );
	// Load the cube face - Negative X
	glTexImage2D ( GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, width,height, 0, 
		GL_RGB, GL_UNSIGNED_BYTE,  data);
	delete []data;
	f>>name;
	data=esLoadTGA ((char*) name,&width,&height  );
	// Load the cube face - Positive Y
	glTexImage2D ( GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, width,height, 0, 
		GL_RGB, GL_UNSIGNED_BYTE,  data );
	delete []data;
	f>>name;
	data=esLoadTGA ((char*) name,&width,&height  );
	// Load the cube face - Negative Y
	glTexImage2D ( GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, width,height, 0, 
		GL_RGB, GL_UNSIGNED_BYTE,  data );
	delete []data;
	f>>name;
	data=esLoadTGA ((char*) name,&width,&height  );
	// Load the cube face - Positive Z
	glTexImage2D ( GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, width,height, 0, 
		GL_RGB, GL_UNSIGNED_BYTE,  data);
	delete []data;
	f>>name;
	data=esLoadTGA ((char*) name,&width,&height  );
	// Load the cube face - Negative Z
	glTexImage2D ( GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, width,height, 0, 
		GL_RGB, GL_UNSIGNED_BYTE,  data );
	delete []data;
	// Set the filtering mode
	glTexParameteri ( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameteri ( GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

	return textureId;
}
cTextureDummy* cTextureLoadFunct::LoadLibraryObject(std::fstream &f,std::string fname,int &m_currentId,std::map<std::string,int> &m_MapFilename,std::map<int, cTextureDummy *> &m_Map,unsigned int mod)
{
	cTextureDummy *dumy= new cTextureDummy();
	if(mod==0)
	{
		dumy->tex=LoadTexture2D(fname.c_str());
	}
	else
	{
		dumy->tex=LoadTextureCube(f);
	}
	pair<std::string,int> t(fname,m_currentId);
	m_MapFilename.insert(t);
	pair <int,cTextureDummy*> e(m_currentId,dumy);
	m_Map.insert(e);
	m_currentId++;

	return dumy;
}