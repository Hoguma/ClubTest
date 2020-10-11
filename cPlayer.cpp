#include "DXUT.h"
#include "cPlayer.h"
#include "cBullet.h"


cPlayer::cPlayer(const D3DXVECTOR2& pos, vector<cBullet*>& bullet)
	: m_pos(pos), m_fireBullet(bullet)
{

}


cPlayer::~cPlayer()
{
}

bool cPlayer::IsOutMap()
{
	return (m_pos.x < 0
		|| m_pos.x > WINSIZEX + 20
		|| m_pos.y < 0
		|| m_pos.y > WINSIZEY);
}

int cPlayer::inputHp(int inputHp)
{
	m_Hp = inputHp;
	return 0;
}