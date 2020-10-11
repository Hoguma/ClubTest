#include "DXUT.h"
#include "cBullet.h"


cBullet::cBullet(const D3DXVECTOR2& pos, double size)
	:m_pos(pos), m_size(size)
{
}


cBullet::~cBullet()
{
}

void cBullet::Render()
{
	m_image->CenterRender(m_pos.x, m_pos.y);
}

bool cBullet::IsOutMap()
{
	return (m_pos.x - m_size < 0
		|| m_pos.x + m_size > WINSIZEX
		|| m_pos.y - m_size < 0
		|| m_pos.y + m_size > WINSIZEY);
}
