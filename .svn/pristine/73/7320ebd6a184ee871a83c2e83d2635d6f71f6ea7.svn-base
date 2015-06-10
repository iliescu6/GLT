
#include "MeshLibrary.h"
#include "includes.h"

cMesh * cMeshLoadFunct::LoadLibraryObject(std::fstream &f,std::string fname,int &m_currentId,std::map<std::string,int> &m_MapFilename,std::map<int, cMesh *> &m_Map,unsigned int mod)
{
	std::vector<cVector3df> vertex;
	std::vector<cVector2df>TCoord;
	std::vector<cVector3df>Normals;
	std::vector<Face>Faces;
	while(!f.eof())
	{
		char line[512];
		f.getline(line,512);
		if(line[0]=='v' && line[1]==' ')
		{
			cVector3df p;
			sscanf_s(line,"v %f%f%f",&p.x,&p.y,&p.z);
			vertex.push_back(p);
		}
		if(line[0]=='v' && line[1]=='n')
		{
			cVector3df p;
			sscanf_s(line,"vn %f%f%f",&p.x,&p.y,&p.z);
			Normals.push_back(p);
			
		}
		if(line[0]=='v' && line[1]=='t')
		{
			cVector2df p;
			sscanf_s(line,"vt %f%f",&p.x,&p.y);
			TCoord.push_back(p);
		}
		if(line[0]=='f' && line[1]==' ')
		{
			Face p;
			sscanf_s(line,"f %d/%d/%d %d/%d/%d %d/%d/%d",
                      &p.Vertex[0],&p.TexCoord[0],&p.Normal[0],
				  &p.Vertex[1],&p.TexCoord[1],&p.Normal[1],
				  &p.Vertex[2],&p.TexCoord[2],&p.Normal[2]);
			p.Normal[0]--;p.Normal[1]--;p.Normal[2]--;
			p.TexCoord[0]--;p.TexCoord[1]--;p.TexCoord[2]--;
			p.Vertex[0]--;p.Vertex[1]--;p.Vertex[2]--;
			
			Faces.push_back(p);
		}
	
	}
	unsigned int last=Faces.size();
	for(unsigned int i=0;i<last;i++)
	{
		int aparitiidist=0;
		for(unsigned int j=i+1;j<last;j++)
		{
			int t=NeedsDuplication(Faces[i],Faces[j]);
			if(t!=-1)
			{
				aparitiidist++;
				cVector3df vnew;
				vnew=vertex[Faces[j].Vertex[t]];
				Faces[j].Vertex[t]=vertex.size();
				vertex.push_back(vnew);
			}
		}
		//cout<<aparitiidist;
	}
	//liniarizare;
	
	cout<<"Object has "<<Faces.size()<<" faces,"<<vertex.size() <<"vertex"<<"\n";
	cMesh *newMesh= new cMesh();
	newMesh->nrVertices= vertex.size()*8;
	newMesh->m_Vertices= new float[newMesh->nrVertices];
	newMesh->m_nrIndices=Faces.size()*3;
	newMesh->m_Indices= new unsigned int[Faces.size()*3+2];
	int k=0;
	for(unsigned int i=0;i<vertex.size();i++)
	{	
		newMesh->m_Vertices[k++]=vertex[i].x;
		newMesh->m_Vertices[k++]=vertex[i].y;
		newMesh->m_Vertices[k++]=vertex[i].z;
		if(newMesh->m_maxX<vertex[i].x)
			newMesh->m_maxX=vertex[i].x;
		if(newMesh->m_maxY<vertex[i].y)
			newMesh->m_maxY=vertex[i].y;
		if(newMesh->m_maxZ<vertex[i].z)
			newMesh->m_maxZ=vertex[i].z;
		if(newMesh->m_minX>vertex[i].x)
			newMesh->m_minX=vertex[i].x;
		if(newMesh->m_minY>vertex[i].y)
			newMesh->m_minY=vertex[i].y;
		if(newMesh->m_minZ>vertex[i].z)
			newMesh->m_minZ=vertex[i].z;
		int l=-1;
		unsigned int j;
		for( j=0;j<Faces.size();j++)
		{	
			if(Faces[j].Vertex[0]==i)
				l=0;
			if(Faces[j].Vertex[1]==i)
				l=1;
			if(Faces[j].Vertex[2]==i)
				l=2;
			if(l!=-1)
				break;
		}
		if(l!=-1)
		{
		newMesh->m_Vertices[k++]=TCoord[Faces[j].TexCoord[l]].x;
		newMesh->m_Vertices[k++]=TCoord[Faces[j].TexCoord[l]].y;	
		newMesh->m_Vertices[k++]=Normals[Faces[j].Normal[l]].x;	
		newMesh->m_Vertices[k++]=Normals[Faces[j].Normal[l]].y;
		newMesh->m_Vertices[k++]=Normals[Faces[j].Normal[l]].z;
		}
	}
	newMesh->nrVertices=k;
	k=0;
	for(unsigned int i=0;i<Faces.size();i++)
	{
		newMesh->m_Indices[k++]=Faces[i].Vertex[0];
		newMesh->m_Indices[k++]=Faces[i].Vertex[1];
		newMesh->m_Indices[k++]=Faces[i].Vertex[2];
	}
	newMesh->m_nrIndices=k;
	pair<std::string,int> t(fname,m_currentId);
	m_MapFilename.insert(t);
	pair <int,cMesh *> e(m_currentId,newMesh);
	m_Map.insert(e);
	m_currentId++;
	
	vertex.clear();
	return newMesh;
}
