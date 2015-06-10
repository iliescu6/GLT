#include "ShaderLibrary.h"

cShaderDummy* cShaderLoadFunct::LoadLibraryObject(std::fstream &f,std::string fname,int &m_currentId,std::map<std::string,int> &m_MapFilename,std::map<int, cShaderDummy *> &m_Map,unsigned int mod)
{
	cShaderDummy *idobj=new cShaderDummy();
	idobj->shader=	setVSFSShader(fname.c_str());
	pair<std::string,int> t(fname,m_currentId);
	m_MapFilename.insert(t);
	pair <int,cShaderDummy *> e(m_currentId,idobj);
	m_Map.insert(e);
	m_currentId++;
	return idobj;
}
int cShaderLoadFunct::setShader(GLenum type,const char *file)
{
	std::ifstream f(file);
	if(f.is_open())
	{
		std::stringstream buffer;

        buffer << f.rdbuf();
	
     
		GLuint shader;
		GLint compiled;
   
		// Create the shader object
		shader = glCreateShader ( type );

		if ( shader == 0 )
   			return 0;
		string next(buffer.str());
		int sizeinBytes=next.size()+1;
		
		const char *ssource=next.c_str();
		glShaderSource ( shader, 1, &ssource, NULL );
   
		// Compile the shader
		glCompileShader ( shader );

		// Check the compile status
		glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );
		if ( !compiled ) 
		{
			GLint infoLen = 0;

			glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );
      
			if ( infoLen > 1 )
			{
				char* infoLog = new char[ infoLen ];

				glGetShaderInfoLog ( shader, infoLen, NULL, infoLog );
				esLogMessage ( "Error compiling shader:\n%s\n", infoLog );            
         
				delete []infoLog;
			}

			glDeleteShader ( shader );
			return 0;
		}
		   f.close();
		   return shader;
	}
	else
	{
		cout<<"BAD FILENAME:\n";
		return 0;
	}
}
GLuint cShaderLoadFunct::setVSFSShader(const char *te)
{
	std::string vshader(te),fshader(te); 
	vshader.append(".vs");fshader.append(".fs");
	GLuint m_fragmentSH,m_vertexSH;
	m_vertexSH=setShader(GL_VERTEX_SHADER,vshader.c_str());
	m_fragmentSH=setShader(GL_FRAGMENT_SHADER,fshader.c_str());
		 // Create the program object
   GLuint m_ProgramObject = glCreateProgram ( );
   
   if ( m_ProgramObject == 0 )
      return-1;

   glAttachShader ( m_ProgramObject, m_vertexSH );
   glAttachShader ( m_ProgramObject, m_fragmentSH );

   glLinkProgram ( m_ProgramObject );
	int linked;
   // Check the link status
   glGetProgramiv ( m_ProgramObject, GL_LINK_STATUS, &linked );

   if ( !linked ) 
   {
      GLint infoLen = 0;

      glGetProgramiv ( m_ProgramObject, GL_INFO_LOG_LENGTH, &infoLen );
      
      if ( infoLen > 1 )
      {
         char* infoLog = new char[ infoLen ];

         glGetProgramInfoLog ( m_ProgramObject, infoLen, NULL, infoLog );
         esLogMessage ( "Error linking program:\n%s\n", infoLog );            
         
         delete ( infoLog );
      }

      glDeleteProgram ( m_ProgramObject );
      return -1;
   }
	return m_ProgramObject;
}