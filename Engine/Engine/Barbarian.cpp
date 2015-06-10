#include "Barbarian.h"
#include "Engine.h"
#include "TileMap.h"
#include <math.h>
// Barbarian initalisation (all init code goes here)
void cBarbarian::Init()
{
	m_mapData = ENGINE->GetTileMap()->getRawMap();// The map matrix 
	sizeMapX = ENGINE->GetTileMap()->getSizeX();// the map size x
	sizeMapY = ENGINE->GetTileMap()->getSizeY();// the map size y

	m_currentPosition = 0;
	// push some positions into the destination vector
	// this vector should hold your solution 
	//TO DO -> make algorithm that populates this vector with correct values
	
	    m_positionList.push_back(ENGINE->GetTileMap()->getSchnappyPos());
		//m_positionList.push_back(cVector3df(4*TILE_OFFSET, 0, 0*TILE_OFFSET));
		//ifstream f(filename);
		ifstream f("maps/map02.txt");
		if (f.is_open())
		{
			f >> m_sizeX;
			f >> m_sizeY;
			for (int i = 0; i<m_sizeX; i++)
				for (int j = 0; j<m_sizeY; j++)
				{
					int val;
					f >> val;
					if (val== 1 || val==2 || val==3 || val==4){
						m_positionList.push_back(cVector3df(i*TILE_OFFSET, 0, j*TILE_OFFSET));
					}
				}
		}

	
		/*m_positionList.push_back(cVector3df(6 * TILE_OFFSET, 0, 9 * TILE_OFFSET));
		m_positionList.push_back(cVector3df(4 * TILE_OFFSET, 0, 0));
		m_positionList.push_back(cVector3df(11 * TILE_OFFSET, 0, 0));
		m_positionList.push_back(cVector3df(11 * TILE_OFFSET, 0, 1 * TILE_OFFSET));
		m_positionList.push_back(cVector3df(10 * TILE_OFFSET, 0, 1 * TILE_OFFSET));
		E.T.C. Lvl70
		*/
}

void cBarbarian::Update(float deltaTime)
{
	cBarbarianAditional::Update(deltaTime*5);
	//move barbarian between the positions of the  solution vector
	if( m_bInterpolate ==false)
	{
		m_currentPosition++;
		m_currentPosition=m_currentPosition%m_positionList.size();
		MoveTo(m_positionList[m_currentPosition]);
	}
}

cBarbarian::cBarbarian()
{
	m_bInterpolate=false;
	m_Type=BARBARIAN;
	m_Health=3.0f;
	m_Armor=1.0f;
	m_Damage=1.0f;
	m_Mana=1.0f;
}
cBarbarian::~cBarbarian()
{
}
