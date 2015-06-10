#ifndef TILEMAP
#define TILEMAP
#include "includes.h"
class cTileMap
{
private:
	int m_sizeX;
	int m_sizeY;
	int *m_mapMatrix;
	cVector3df m_schnappyPos;
public:
	//
	float m_schnappiHealth;
	float m_schnappiArmor;
	float m_schnappiDamage;
	float m_schnappiMana;

public:
	cTileMap();
	int * getRawMap(){return m_mapMatrix;}
	void LoadMap(const char *filename);
	int getSizeX(){return m_sizeX;}
	int getSizeY(){return m_sizeY;}
	cVector3df getSchnappyPos(){return m_schnappyPos;}
	void GetTileWorldPosition(unsigned int i,unsigned int j,cVector3df &out);
	void CreateSceneObjects();
	void LoadAttributesFromFile(const char*filename);
	~cTileMap();
};
#endif