#include "DXUT.h"
#include "cXBullet.h"
#include "cDororo.h"

cXBullet::cXBullet(const Vec2& pos, const Vec2& direction, float speed)
	: cMobBullet(pos, 20, speed), vDirection(direction)
{
	m_image = IMAGEMANAGER->AddImage("mobxbullet", "./image/Mob/Kiruru/xBullet.png");
	name = "slow";
}


cXBullet::~cXBullet()
{
}

void cXBullet::Update()
{
	m_pos += vDirection * m_speed;
}
