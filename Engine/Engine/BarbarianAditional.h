#ifndef CBARBARIAN_ADITIONAL
#define CBARBARIAN_ADITIONAL


#include "MeshObject.h"

class cBarbarianAditional: public cMeshObject
{
//private: 
public:
	cVector3df m_destination;
	bool m_bInterpolate;
	int *m_mapData;
	int sizeMapX,sizeMapY;
	std::vector<cVector3df> m_positionList;
	unsigned int m_currentPosition;
	
	//
	float m_Health;
	float m_Armor;
	float m_Damage;
	float m_Mana;
public:
	cBarbarianAditional();
	virtual ~cBarbarianAditional();
	
	//void UpdateBarbarianAditional(float deltTime);
	void SchnappiFight();
	
	virtual void Init() =0;
	virtual void MoveTo(cVector3df Position)=0;
	virtual void Update(float deltTime);
	virtual void setBarbarianHealth(float health)=0;
	virtual void setBarbarianArmor(float armor)=0;
	virtual void setBarbarianDamage(float damage)=0;
	virtual void setBarbarianMana(float mana)=0;

	virtual float getBarbarianHealth()=0;
	virtual float getBarbarianArmor()=0;
	virtual float getBarbarianDamage()=0;
	virtual float getBarbarianMana()=0;

	virtual bool getInterpolateVal()=0;
	virtual void setInterpolateVal(bool bVal)=0;

	virtual cVector3df  getDestination()=0;
};
#endif