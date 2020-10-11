#include "DXUT.h"
#include "cDororoBullet.h"

cDororoBullet::cDororoBullet(const D3DXVECTOR2& pos)
	:cBullet(pos, 10)
{
	m_image = IMAGEMANAGER->AddImage("playerDBullet", "./image/player/Dororo/playerBullet.png");
	m_offense = 10;
}

cDororoBullet::~cDororoBullet()
{
}

void cDororoBullet::Update()
{
	m_pos.x += 1000 * DXUTGetElapsedTime();
}