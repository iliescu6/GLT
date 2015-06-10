
#include "includes.h"
#include <math.h>

void MatrixInvRotate(ESMatrix mtxin, ESMatrix & mtxout)
{
  for(int i=0 ; i<3; i++) {
    for(int j=0; j<3; j++) {
      mtxout.m[j][i] = mtxin.m[i][j];
    }
  }
}

void VectorRotate(cVector3df& vin,ESMatrix mtx,cVector3df& vout)
{
	vout.x = vin.x*mtx.m[0][0] + vin.y*mtx.m[1][0] + vin.z*mtx.m[2][0];
	vout.y = vin.x*mtx.m[0][1] + vin.y*mtx.m[1][1] + vin.z*mtx.m[2][1];
	vout.z = vin.x*mtx.m[0][2] + vin.y*mtx.m[1][2] + vin.z*mtx.m[2][2];
}
void InverseMatrix(ESMatrix &in, ESMatrix &out)
{
	MatrixInvRotate(in,out);
	cVector3df vTmp, vTmp2;

  vTmp.x = -in.m[3][0];
  vTmp.y = -in.m[3][1];
  vTmp.z = -in.m[3][2];

  VectorRotate(vTmp, out, vTmp2);
  out.m[3][0] = vTmp2.x;
  out.m[3][1] = vTmp2.y;
  out.m[3][2] = vTmp2.z;
  out.m[0][3] = out.m[1][3] = out.m[2][3] = 0.0f;
  out.m[3][3] = 1.0f;
}
int NeedsDuplication(Face one,Face two)
{	
	for (int i=0;i<3;i++)
		for(int j=0;j<3;j++)

	if(one.Vertex[i] ==two.Vertex[j])
	{
		if(one.TexCoord[i]!=two.TexCoord[j] || one.Normal[i]!=two.Normal[j])
			return j;
	}
	return -1;
}
float Dot(cVector3df xV,cVector3df yV)
{
	return xV.x*yV.x+xV.y*yV.y+xV.z*yV.z;
}
void Normalize(cVector3df& in,cVector3df& out)
{
	float len=sqrt(Dot(in,in));
	if(len!=0)
	{
		out.x=in.x/len;
		out.y=in.y/len;
		out.z=in.z/len;
	}

}
void Cross(cVector3df &in1,cVector3df &in2,cVector3df &out)
{
	out.x=in1.y*in2.z-in2.y*in1.z;
	out.y=in1.z*in2.x-in2.z*in1.x;
	out.z=in1.x*in2.y-in1.x*in2.y;
}