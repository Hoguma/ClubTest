#include "DXUT.h"
#include "cXFBullet.h"
#include "cBulletMob.h"
#include "cKiruru.h"

cXFBullet::cXFBullet(const Vec2& pos, float speed, cKiruru* mob)
	: cMobBullet(pos, 20, speed), m_mob(mob)
{
	m_image = IMAGEMANAGER->AddImage("mobxfbullet", "./image/Mob/Kiruru/xBullet.png");
	name = "heal";
}


cXFBullet::~cXFBullet()
{
}

void cXFBullet::Update()
{
	Vec2 mobPos = m_mob->GetPos();
	Vec2 direction = mobPos - m_pos;
	D3DXVec2Normalize(&direction, &direction);
	m_pos += direction * m_speed;
}
