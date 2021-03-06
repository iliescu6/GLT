#ifndef CBARBARIAN
#define CBARBARIAN

#include "MeshObject.h"
#include "BarbarianAditional.h"

class cBarbarian:public cBarbarianAditional
{

public:
	cBarbarian();
	~cBarbarian();
	void Init();

	void MoveTo(cVector3df Position){m_bInterpolate=true;m_destination=Position;}
	void Update(float deltTime);

	void setBarbarianHealth(float health){ m_Health = health; };
	void setBarbarianArmor(float armor){ m_Armor = armor; };
	void setBarbarianDamage(float damage){ m_Damage = damage; };
	void setBarbarianMana(float mana){ m_Mana = mana; };

	float getBarbarianHealth(){ return m_Health; };
	float getBarbarianArmor(){ return m_Armor; };
	float getBarbarianDamage(){ return m_Damage; };
	float getBarbarianMana(){ return m_Mana; };

	const char *filename;
	const char *mapname;
	int m_sizeX;
	int m_sizeY;
	int *m_mapMatrix;

	bool getInterpolateVal(){return m_bInterpolate;};
	void setInterpolateVal(bool bVal){m_bInterpolate = bVal;};

	cVector3df  getDestination(){ return m_destination;};
};
#endif