#include "DXUT.h"
#include "cMobBullet.h"


cMobBullet::cMobBullet(const Vec2& pos, double size, float speed)
	:m_pos(pos), m_size(size), m_speed(speed)
{

}


cMobBullet::~cMobBullet()
{

}

void cMobBullet::Render()
{
	m_image->CenterRender(m_pos.x, m_pos.y);
}

bool cMobBullet::IsOutMap()
{
	return (m_pos.x - m_size < 0
		|| m_pos.x + m_size > WINSIZEX
		|| m_pos.y - m_size < 0
		|| m_pos.y + m_size > WINSIZEY);
}