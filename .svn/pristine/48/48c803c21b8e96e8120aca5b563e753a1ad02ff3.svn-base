#ifndef CINPUT_MANAGER
#define CINPUT_MANAGER
#include  "includes.h"
enum eMouseButtons
{
	LEFT_MOUSE_BUTTON=0,MIDDLE_MOUSE_BUTTON,RIGHT_MOUSE_BUTTON
};

#define INPUT cInputManager::getSingleton()
class cInputManager
{
private:
	int m_currentKey[256];
	int m_prevKey[256];

	cVector2di m_mousePos;
	unsigned int m_mouseButtons[3];
private:
	
	cInputManager();
public:
	~cInputManager();
	static cInputManager* getSingleton()
	{
		static cInputManager* t=0;
		if(!t)
			t= new cInputManager();
		return t;
	}
	static void Update(unsigned char wParam,int lParam, int MousePosX, int MousePosY);
	bool getKeyPressed( char key)
	{
	return m_currentKey[key]==1;
	}
	bool getKey(char key)
	{
		return (m_currentKey[key]!=0);
	}
	bool getMouseButtonState(eMouseButtons but)
	{
			return m_mouseButtons[but]!=0;
	}
	bool getKeyReleased(char key)
	{
		return (m_currentKey[key]==0)!=m_prevKey[key];
	}
	cVector2di getMousePos()
	{
		POINT mouse;
		GetCursorPos(&mouse);
		m_mousePos.x=mouse.x;
		m_mousePos.y=mouse.y;
		return m_mousePos;
	}
	void Release()
	{
		delete getSingleton();		
	}
};
#endif 