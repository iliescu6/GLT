
#include "MeshObject.h"
#include "includes.h"
#include "MeshLibrary.h"
#include "Engine.h"
#include "Camera.h"
#include "TextureLibrary.h"

void cMeshObject::Render()
{
	cRenderObject::Render();
  
   glVertexAttribPointer ( m_PositionLoc, 3, GL_FLOAT, 
                           GL_FALSE, 8 * sizeof(GLfloat),m_meshPointer->m_Vertices );

   glVertexAttribPointer ( m_TexCoordLoc, 2, GL_FLOAT,
                           GL_FALSE, 8 * sizeof(GLfloat), &m_meshPointer->m_Vertices[3] );
	glVertexAttribPointer( m_NormalCoordLoc,3,GL_FLOAT,GL_FALSE,8 * sizeof(GLfloat), &m_meshPointer->m_Vertices[5]);
   glEnableVertexAttribArray ( m_PositionLoc );
   glEnableVertexAttribArray ( m_TexCoordLoc );
   glEnableVertexAttribArray (m_NormalCoordLoc);



   glActiveTexture ( GL_TEXTURE0 );
   glBindTexture ( GL_TEXTURE_2D, m_TextureId );

   glUniform1i ( m_SamplerLoc, 0 );


 

   glUniformMatrix4fv( m_MvpLoc, 1, GL_FALSE, (GLfloat*) &m_MVPMatrix.m[0][0] );
   glUniformMatrix4fv( m_MLoc, 1, GL_FALSE, (GLfloat*) &m_MMatrix.m[0][0] );
   glUniformMatrix4fv( m_VLoc, 1, GL_FALSE, (GLfloat*) &ENGINE->m_activeCamera->View.m[0][0] );
   

   glUniform1f (m_lifeLoc, m_LifeTime);  
   glUniform3f(m_CamPosLoc,ENGINE->m_activeCamera->getPosition()[0],ENGINE->m_activeCamera->getPosition()[1],ENGINE->m_activeCamera->getPosition()[2]); 

   glUniformMatrix4fv(m_CamPosLoc,1,GL_FALSE,(GLfloat*)&ENGINE->m_activeCamera->View.m[0][0]);
   glDrawElements ( GL_TRIANGLES,m_meshPointer->m_nrIndices, GL_UNSIGNED_INT,m_meshPointer-> m_Indices );


    
}
void cMeshObject::RenderToTex()
{
	cRenderObject::Render();

  


   glVertexAttribPointer ( m_PositionLoc, 3, GL_FLOAT, 
                           GL_FALSE, 8 * sizeof(GLfloat),m_meshPointer->m_Vertices );
  
   glVertexAttribPointer ( m_TexCoordLoc, 2, GL_FLOAT,
                           GL_FALSE, 8 * sizeof(GLfloat), &m_meshPointer->m_Vertices[3] );
	glVertexAttribPointer( m_NormalCoordLoc,3,GL_FLOAT,GL_FALSE,8 * sizeof(GLfloat), &m_meshPointer->m_Vertices[5]);
   glEnableVertexAttribArray ( m_PositionLoc );
   glEnableVertexAttribArray ( m_TexCoordLoc );
   glEnableVertexAttribArray (m_NormalCoordLoc);



   glActiveTexture ( GL_TEXTURE0 );
   glBindTexture ( GL_TEXTURE_2D, m_TextureId );

   glUniform1i ( m_SamplerLoc, 0 );

	unsigned int i=0;
  if(m_extraTextures.size())
   {
	   for( i=0;i<m_extraTextures.size();i++)
	   {
		   glActiveTexture ( GL_TEXTURE0+i+1 );
		   glBindTexture ( GL_TEXTURE_2D,m_extraTextures[i].texId );
		   glUniform1i (m_extraTextures[i].samplerLoc, i+1);
	   }
	}
	glActiveTexture ( GL_TEXTURE0+i+1 );
	glBindTexture ( GL_TEXTURE_2D,m_ScreenTextureId);
	glUniform1i (m_ScreenTextureLoc, i+1);

 

   glUniformMatrix4fv( m_MvpLoc, 1, GL_FALSE, (GLfloat*) &m_MVPMatrix.m[0][0] );
   glUniformMatrix4fv( m_MLoc, 1, GL_FALSE, (GLfloat*) &m_MMatrix.m[0][0] );
   glUniformMatrix4fv( m_VLoc, 1, GL_FALSE, (GLfloat*) &ENGINE->m_activeCamera->View.m[0][0] );
   glUniformMatrix4fv( m_MVITLoc, 1, GL_FALSE, (GLfloat*) &m_MVITMatrix.m[0][0] );
   glUniformMatrix4fv( m_MITLoc, 1, GL_FALSE, (GLfloat*) &m_MITMatrix.m[0][0] );
   float m[3][3];
   for(int i=0;i<3;i++)
	   for(int j=0;j<3;j++)
	      m[j][i]=ENGINE->m_activeCamera->View.m[i][j];
   

   glUniformMatrix3fv( m_NormalMatrixLoc, 1, GL_FALSE, (GLfloat*) &m[0][0] );
   glUniform1f (m_lifeLoc, m_LifeTime);  
   glUniform3f(m_CamPosLoc,ENGINE->m_activeCamera->getPosition()[0],ENGINE->m_activeCamera->getPosition()[1],ENGINE->m_activeCamera->getPosition()[2]); 
  
 

}
cMeshObject::cMeshObject():cRenderObject()
{
  
}
GLuint cMeshObject::LoadTexture2D(const char *filename)
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


   return textureId1;
}

cMeshObject::~cMeshObject()
{
}
int cMeshObject::LoadRaduFile(fstream &f)
{
	char objfile[512];
	char shaderfile[512];
	char texfile[512];
	f>>objfile;
	f>>shaderfile;
	f>>texfile;
	if(!strcmp(texfile,"<CUBE3D>"))
	{
		std::streamoff len=f.tellg();
		m_TextureId= TEXLIB->LoadModel(texfile,f)->tex;
		if(len== f.tellg())
		{
			f>>texfile;
			f>>texfile;
			f>>texfile;
			f>>texfile;
			f>>texfile;
			f>>texfile;
		}
	}
	else
	{
		m_TextureId = TEXLIB->LoadModel(texfile)->tex;
	}
	setVSFSShader(shaderfile);
	m_meshPointer= MESHLIB->LoadModel(objfile);
 	
   m_PositionLoc = glGetAttribLocation ( m_ProgramObject, "a_position" );
   m_MvpLoc = glGetUniformLocation( m_ProgramObject, "u_mvpMatrix" );
   m_TexCoordLoc = glGetAttribLocation ( m_ProgramObject, "a_texCoord" );
   m_NormalCoordLoc = glGetAttribLocation ( m_ProgramObject, "a_normals" ); 
   m_lifeLoc = glGetUniformLocation ( m_ProgramObject, "u_life" );
   m_SamplerLoc = glGetUniformLocation (m_ProgramObject, "s_texture" );
   m_NormalMatrixLoc=glGetUniformLocation(m_ProgramObject, "u_NormalMatrix" );
   m_CamPosLoc= glGetUniformLocation(m_ProgramObject,"u_CameraPos");
   m_ScreenTextureLoc= glGetUniformLocation(m_ProgramObject,"u_screenTex");

  while(!f.eof())
   {
	char extraTex[512];
	f>>extraTex;
 	cTexture newTex;
	newTex.texId= TEXLIB->LoadModel(extraTex)->tex;
	
	unsigned int id=m_extraTextures.size();
	std::stringstream s_texs,a_texs;
	s_texs<<"s_texture"<<id;
	std::string s_tex(s_texs.str());
	const char *cc=s_tex.c_str();
		
	newTex.samplerLoc = glGetUniformLocation ( m_ProgramObject,cc);
	
	m_extraTextures.push_back(newTex);
	

   }
	return 1;
}
int cMeshObject::LoadModel(const char *filename)
{
	std::fstream f(filename,std::ios::in);
	int error=0;
	if(f.is_open())
	{
		char *ext=strchr((char*)filename,'.');
		unsigned int dim=strlen(ext);
		if(!strcmp(ext,".obj"))
		{
			m_meshPointer=MESHLIB->LoadModel(filename);
			assert(m_meshPointer);
		}
		if(!strcmp(ext,".radu"))
		{
			error=LoadRaduFile(f);
		}
		f.close();
	}
	else
	{
		std::cout<<"Nu gasesc fisierul "<<filename<<"\n";
	}
return error;
}

void cMeshObject::Update(float deltaTime)
{
		cRenderObject::Update(deltaTime);
}	