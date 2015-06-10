
#ifndef INCLUDES_MY
#define INCLUDES_MY
#include "esUtil.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include "Vector3d.h"
#include "Vector2d.h"
#include <assert.h>
#include "ObjectTypes.h"
using namespace std;
const int screen_width=1024;
const int screen_heigth=1024;
#pragma comment(lib, "libEGL.lib")
#pragma comment(lib,"libGLESv2.lib")
#ifdef _DEBUG
#pragma comment(lib,"esUtil_d.lib")
#endif
#ifndef _DEBUG
#pragma comment(lib,"esUtil.lib")
#endif
class cMesh
{
public:
	float *m_Vertices;
	int nrVertices;
	unsigned int *m_Indices;
	float *m_tangents;
	float *m_bitangents;
	int m_nrIndices;
	float m_maxX;
	float m_maxY;
	float m_maxZ;
	float m_minZ;
	float m_minY;
	float m_minX;
	cMesh()
	{
		m_Vertices=0;
		nrVertices=0;
		m_tangents=0;
		m_bitangents=0;
		m_Indices=0;
		m_nrIndices=0;
		m_maxX=0;
		m_maxY=0;
		m_maxZ=0;
		m_minX=m_minY=m_minZ=32000;
	}
	~cMesh()
	{
		if(m_Vertices)
			delete [] m_Vertices;
		if(m_Indices)
			delete [] m_Indices;
		if(m_bitangents)
			delete [] m_bitangents;
		if(m_tangents)
			delete [] m_tangents;
		nrVertices=0;
		m_nrIndices=0;
		m_Vertices=0;
		m_Indices=0;
	}
};

struct cTexture
{
	unsigned int texId;
	int samplerLoc;
	cTexture():texId(0),samplerLoc(0){}
};

struct Face
{
	int Vertex[3];
	int TexCoord[3];
	int Normal[3];
};
struct cVertex
{
	cVector3df Pos;
	cVector3df	Tex;
	cVector3df	Norm;
};
int NeedsDuplication(Face one,Face two);


void MatrixInvRotate(ESMatrix mtxin, ESMatrix & mtxout);

void VectorRotate(cVector3df &vin,ESMatrix mtx,cVector3df& vout);
void InverseMatrix(ESMatrix &in, ESMatrix &out);
float Dot(cVector3df x,cVector3df y);
void Cross(cVector3df &in1,cVector3df &in2,cVector3df &out);
void Normalize(cVector3df &in,cVector3df &out);
#endif