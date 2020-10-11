#include "DXUT.h"
#include "cSplitBullet.h"
#include "cNormalBullet.h"


cSplitBullet::cSplitBullet(const Vec2& pos, const Vec2& direction, float speed)
	: cMobBullet(pos, 20, speed), vDirection(direction)
{
	m_image = IMAGEMANAGER->AddImage("mobbullet1", "./image/Mob/kiruru/MonsterBullet1.png");
	name = "split";
	isDestroy = false;
	StartTime = GetTickCount();
}


cSplitBullet::~cSplitBullet()
{
}

void cSplitBullet::Update()
{
	NowTime = GetTickCount();
	if (NowTime - StartTime >= 3000)
	{
		isDestroy = true;
	}
	else
		m_pos += vDirection * m_speed;
}
