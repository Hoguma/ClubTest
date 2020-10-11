#include "DXUT.h"
#include "cKiruruBullet.h"


cKiruruBullet::cKiruruBullet(const Vec2& pos, const Vec2& direction, float speed)
	: cMobBullet(pos, 20, speed), vDirection(direction)
{
	m_image = IMAGEMANAGER->AddImage("KiruruBullet", "./image/Mob/Kiruru/Mob.png");
	name = "kiruru";
}


cKiruruBullet::~cKiruruBullet()
{
}

void cKiruruBullet::Update()
{
	m_pos += vDirection * m_speed;
}
