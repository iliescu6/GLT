#ifndef CVECTOR3D
#define CVECTOR3D
#include <assert.h>
template <class T>
class cVector3d
{
public:
	union 
	{
		T v[3];
		struct 
		{
			T x,y,z;
		};
	};
	cVector3d():x(0),y(0),z(0){}
	cVector3d(T v[3]):x(v[0]),y(v[1]),z(v[3]){}
	
	cVector3d(cVector3d& f,cVector3d& a)
	{
		x=f.x+a.x;y=f.y+a.y;z=f.z+a.z;
	}
	cVector3d(T x1,T y1 ,T z1):x(x1),y(y1),z(z1){}
	friend bool operator==(const cVector3d& other, const cVector3d& other1)
	{
		return other.x == other1.x && other.y==other1.y && other.z==other1.z;
	}
	friend cVector3d operator+(const cVector3d& other, const cVector3d& other1)
	{
		cVector3d t;
		t.x=other1.x+other.x;t.y=other1.y+other.y;t.z=other1.z+other.z;
		return t;
	}
	friend cVector3d operator+(const cVector3d& other, T mul)
	{
		cVector3d t;
		t.x=other.x*mul;t.y=other.y*mul;t.z=other.z*mul;
		return t;
	}
	friend cVector3d operator-(const cVector3d& other, const cVector3d& other1)
	{
		cVector3d t;
		t.x=other.x-other1.x;t.y=other.y-other1.y;t.z=other.z-other1.z;
		return t;
	}

	friend bool operator!=(const cVector3d& other, const cVector3d& other1)
	{
		return !(other.x == other1.x && other.y==other1.y && other.z==other1.z);
	}
	T operator [](unsigned int i)
	{
		assert(i==0||i==1||i==2);
		return v[i];
	}
	void Display()
	{
		std::cout<<x<<" "<<y<<" "<<z<<" \n";
	}
	~cVector3d(){}
};
typedef   cVector3d<int> cVector3di;
typedef   cVector3d<float> cVector3df ;
typedef   cVector3d<double> cVector3dd ;
#endif