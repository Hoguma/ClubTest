#include "DXUT.h"
#include "cNormalBullet.h"


cNormalBullet::cNormalBullet(const Vec2& pos, const Vec2& direction, float speed)
	: cMobBullet(pos, 10, speed), vDirection(direction)
{
	m_image = IMAGEMANAGER->AddImage("mobbullet", "./image/Mob/Bullet/MonsterBullet.png");
	name = "none";
}


cNormalBullet::~cNormalBullet()
{
}

void cNormalBullet::Update()
{
	m_pos += vDirection * m_speed;
}
