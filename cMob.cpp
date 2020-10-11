#include "DXUT.h"
#include "cMob.h"


cMob::cMob(const D3DXVECTOR2& pos)
	: m_pos(pos)//, m_fireBullet(MonsterBullet)
{
	//RandNum = rand() % 5;
	//MonsterType = "None";
}


cMob::~cMob()
{
}

bool cMob::IsOutMap()
{
	return (m_pos.x < 0
		|| m_pos.x > WINSIZEX + 20
		|| m_pos.y < 0
		|| m_pos.y > WINSIZEY);
}

int cMob::inputHp(int inputHp)
{
	m_HP = inputHp;
	return 0;
}
