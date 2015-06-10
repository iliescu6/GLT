#include "BarbarianAditional.h"

#include "Engine.h"
#include <math.h>
#include "TileMap.h"


cBarbarianAditional::cBarbarianAditional()
{
	m_bInterpolate=false;
	m_Type=BARBARIAN;
	m_Health=3.0f;
	m_Armor=1.0f;
	m_Damage=1.0f;
	m_Mana=1.0f;
}
cBarbarianAditional::~cBarbarianAditional()
{
}

void cBarbarianAditional::Update(float deltaTime)
{
	if(m_bInterpolate)
	{
		cVector3df pos= getPosition();
		cVector3df dir=pos-m_destination;
		float len= sqrt(dir.x*dir.x+dir.z*dir.z);
		if(len>0.1f)
		{
			if(pos.x< m_destination.x)
				pos.x+=deltaTime;
			if(pos.z< m_destination.z)
				pos.z+=deltaTime;
			if(pos.x> m_destination.x)
				pos.x-=deltaTime;
			if(pos.z> m_destination.z)
				pos.z-=deltaTime;
			setPosition(pos);
		}
		else
		{
			m_bInterpolate=false;
			setPosition(m_destination);
			if(getPosition()==ENGINE->GetTileMap()->getSchnappyPos())
			{
				SchnappiFight();
			}
		}
	}
	cMeshObject::Update( deltaTime);
}
void cBarbarianAditional::SchnappiFight()
{
	while(ENGINE->GetTileMap()-> m_schnappiHealth>0&&m_Health>0)
	{
		m_Health-=(ENGINE->GetTileMap()->m_schnappiDamage+ENGINE->GetTileMap()->m_schnappiMana)/m_Armor;
		ENGINE->GetTileMap()-> m_schnappiHealth-=(m_Damage+m_Mana)/ENGINE->GetTileMap()->m_schnappiArmor;
	}
	if(m_Health>0)
	{
		std::cout<<"ALINA WINS!!";
		//ALINA WINS;
		//_CrtDbgBreak();
		cMeshObject *a=new cMeshObject;
		a->LoadModel("link/screen_Alina.radu");
		ENGINE->AddRenderObject(a);
	}
	else
	{
		//SCHNAPPi WINS
		std::cout<<"SCHNAPPi WINS!!";
		//_CrtDbgBreak();
		cMeshObject *a = new cMeshObject;
		a->LoadModel("link/screen_Shnappi.radu");
		ENGINE->AddRenderObject(a) ;
	}
}