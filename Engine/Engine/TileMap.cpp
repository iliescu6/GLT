#include "TileMap.h"
#include "includes.h"
#include "engine.h"
#include "MeshObject.h"
#include "Barbarian.h"
void cTileMap::GetTileWorldPosition(unsigned int i,unsigned int j,cVector3df &out)
{
	out=cVector3df(i*TILE_OFFSET,0,j*TILE_OFFSET);
}

void cTileMap::LoadAttributesFromFile(const char*filename)
{

//	char *flname=
	std::string newfile(filename);
	newfile.append("_properties.txt");
	std::ifstream f(newfile.c_str());
	
	char str[512];
	float prop;
	std::string readStr;
	if(f.is_open())
	{
		f.getline(str, 512);
		
		f.getline(str, 512);
		sscanf_s(str,"Health %f",&prop);
		ENGINE->m_Alina->setBarbarianHealth(prop);

		f.getline(str, 512);
		sscanf_s(str,"Mana %f",&prop);
		ENGINE->m_Alina->setBarbarianMana(prop);

		f.getline(str, 512);
		sscanf_s(str,"Armor %f",&prop);
		ENGINE->m_Alina->setBarbarianArmor(prop);

		f.getline(str, 512);
		sscanf_s(str,"Damage %f",&prop);
		ENGINE->m_Alina->setBarbarianDamage(prop);

		f.getline(str, 512);

		f.getline(str, 512);
		sscanf_s(str,"Health %f",&m_schnappiHealth);

		f.getline(str, 512);
		sscanf_s(str,"Mana %f",&m_schnappiMana);

		f.getline(str, 512);
		sscanf_s(str,"Armor %f",&m_schnappiArmor);

		f.getline(str, 512);
		sscanf_s(str,"Damage %f",&m_schnappiDamage);
	}
	else
	{
		std::cout<<"Nu gasesc fisierul "<<filename<<"\n";
	}
	f.close();
}

cTileMap::cTileMap()
{
	m_schnappiHealth=100.0f;
	m_schnappiArmor=2.0f;
	m_schnappiDamage=2.0f;
	m_schnappiMana=2.0f;
}
cTileMap::~cTileMap()
{
	delete m_mapMatrix;
}
void cTileMap::LoadMap(const char*filename)
{
	ifstream f(filename);
	if(f.is_open())
	{
	f>>m_sizeX;
	f>>m_sizeY;
	m_mapMatrix= new int[m_sizeX*m_sizeY];
	for(int i=0;i<m_sizeX;i++)
		for(int j=0;j<m_sizeY;j++)
		{
			int val;
			f>>val;
			m_mapMatrix[m_sizeX*i+j]=val;
		}
	}
}

cRenderObject* LoadTile(int i,int j)
{
	cRenderObject *v= new cMeshObject();
	((cMeshObject*)v)->LoadModel("link/Tile.radu");
	v->setPosition(cVector3df(i*TILE_OFFSET,0,j*TILE_OFFSET));
	ENGINE->AddRenderObject(v);
	return v;
}
cRenderObject* LoadItem(const char* filename,int i,int j)
{
	cRenderObject *v=new cMeshObject();
	v->setPosition(cVector3df(i*TILE_OFFSET,0.4f,j*TILE_OFFSET));
	v->setScale(cVector3df(SCALE_SIZE_ITEM,SCALE_SIZE_ITEM,SCALE_SIZE_ITEM));
	((cMeshObject*)v)->LoadModel(filename);
	ENGINE->AddRenderObject(v);
	return v;
}
cRenderObject* LoadMonster(int i,int j)
{
	cRenderObject *v= new cMeshObject();
	v->setPosition(cVector3df(i*TILE_OFFSET ,MONSTER_HEIGHT_POS,j*TILE_OFFSET ));
	v->setScale(cVector3df(SCALE_SIZE_MONSTER,SCALE_SIZE_MONSTER,SCALE_SIZE_MONSTER));
	((cMeshObject*)v)->LoadModel("link/Croco.radu");
	ENGINE->AddRenderObject(v);
	
	return v;
}
void cTileMap::CreateSceneObjects()
{
	for(int i=0;i<m_sizeX;i++)
		for(int j=0;j<m_sizeY;j++)
		{
			cRenderObject *v=0;
			if(m_mapMatrix[m_sizeX *i+j]!=-1)
				v=LoadTile(i,j);
			
			switch(m_mapMatrix[m_sizeX *i+j])
			{
			case ITEM_RED:
				v= LoadItem("link/item1.radu",i,j);
				break;

			case ITEM_GREEN:
				v= LoadItem("link/item2.radu",i,j);
				break;

			case ITEM_YELLOW:
				v= LoadItem("link/item3.radu",i,j);
				break;

			case ITEM_BLUE:
				v= LoadItem("link/item4.radu",i,j);
				break;

			case MONSTER:
				v= LoadMonster(i,j);
				m_schnappyPos=cVector3df(i*TILE_OFFSET,0,j*TILE_OFFSET);
				break;

			case BARBARIAN:
				ENGINE->m_Alina->LoadModel("link/barbar.radu");
				ENGINE->AddRenderObject((cRenderObject*)ENGINE->m_Alina);
				ENGINE->m_Alina->setPosition(cVector3df(i*TILE_OFFSET,0,j*TILE_OFFSET));
				ENGINE->m_Alina->Init();
				LoadAttributesFromFile("maps/map02");
				break;
			}
		}
}
