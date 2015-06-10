#include "InputManager.h"
#include <string.h>
cInputManager::cInputManager()
{
	memset(m_currentKey,0,sizeof(int)*256);
	memset(m_prevKey,0,sizeof(int)*256);
	memset(m_mouseButtons,0,sizeof(int)*3);
}
void cInputManager::Update( unsigned char key,int lParam, int MousePosX, int MousePosY)
{
	if(lParam<3)
	{
	if(INPUT->m_currentKey[key]!=0&&lParam==1)
		INPUT->m_currentKey[key]=2;
	else
		INPUT->m_currentKey[key]=lParam;
	}
	else
	{
		switch (lParam)
		{
		case 3:
			INPUT->m_mouseButtons[LEFT_MOUSE_BUTTON]=1;
			break;
		case 4:
			INPUT->m_mouseButtons[LEFT_MOUSE_BUTTON]=0;
			break;
		case 5:
			INPUT->m_mouseButtons[RIGHT_MOUSE_BUTTON]=1;
			break;
		case 6:
			INPUT->m_mouseButtons[RIGHT_MOUSE_BUTTON]=0;
			break;
		}

		//INPUT->m_mouseButtons[(lParam-3)/2]=(lParam-3)%2;
	}
}
cInputManager::~cInputManager()
{
}
