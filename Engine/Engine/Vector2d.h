#ifndef CVECTOR2D
#define CVECTOR2D
#include <assert.h>
template <class T>
class cVector2d
{
public:
	union 
	{
		T v[2];
		
		struct 
		{
			T x,y;
		};
	
	};
	cVector2d():x(0),y(0){}
	cVector2d(T v[2]):x(v[0]),y(v[1]){}
	cVector2d(cVector2d& f,cVector2d& a)
	{
		x=f.x+a.x;y=f.y+a.y;
	}
	cVector2d(T x1,T y1):x(x1),y(y1){}
	friend bool operator==(const cVector2d& other, const cVector2d& other1)
	{
		return other.x == other1.x && other.y==other1.y;
	}
	friend cVector2d operator+(const cVector2d& other, const cVector2d& other1)
	{
		cVector2d t;
		t.x=other1.x+other.x;t.y=other1.y+other.y;
		return t;
	}

	friend bool operator!=(const cVector2d& other, const cVector2d& other1)
	{
		return !(other.x == other1.x && other.y==other1.y );
	}
	T operator [](unsigned int i)
	{
		assert(i==0||i==1);
		return v[i];
	}
	void Display()
	{
		std::cout<<x<<" "<<y<<" \n";
	}
	~cVector2d(){}
};
typedef   cVector2d<int> cVector2di;
typedef   cVector2d<float> cVector2df ;
typedef   cVector2d<double> cVector2dd ;
#endif