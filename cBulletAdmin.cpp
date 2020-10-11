#include "DXUT.h"
#include "cBulletAdmin.h"

#include "cBullet.h"
#include "cMobBullet.h"
#include "cNormalBullet.h"

cBulletAdmin::cBulletAdmin()
{
}


cBulletAdmin::~cBulletAdmin()
{
	Reset();
}

void cBulletAdmin::Reset()
{
	for (auto iter : m_playerBullet)
		SAFE_DELETE(iter);
	m_playerBullet.clear();
	for (auto iter : m_mobBullet)
		SAFE_DELETE(iter);
	m_mobBullet.clear();
}

void cBulletAdmin::Update()
{
	for (auto iter : m_playerBullet)
		iter->Update();
	CheckCollision();
	for (auto iter : m_mobBullet)
		iter->Update();
	CheckMonsterCollision();


	for (auto mbiter = m_mobBullet.begin(); mbiter != m_mobBullet.end();)
	{

		if ((*mbiter)->isDestroy == true)
		{
			if ((*mbiter)->GetName() == "split")
			{
				float angle = 0;

				Vec2 bulletPos = (*mbiter)->GetPos();

				float rad = 3.14 * 2 / 5;
				// 16Àº ÃÑ¾Ë °³¼ö

				for (float i = 0; i < 5; i++, angle += rad)
				{
					Vec2 Direction = Vec2(bulletPos.x + (cosf(angle) * 5), bulletPos.y + (sinf(angle) * 5));

					Direction = Direction - bulletPos;

					D3DXVec2Normalize(&Direction, &Direction);

					m_mobBullet.push_back(new cNormalBullet(bulletPos, Direction, 5));

				}
			}
			SAFE_DELETE((*mbiter));
			mbiter = m_mobBullet.erase(mbiter);
		}
		else
			++mbiter;
	}

	
}

void cBulletAdmin::Render()
{
	for (auto iter : m_playerBullet)
		iter->Render();
	for (auto iter : m_mobBullet)
		iter->Render();
}

void cBulletAdmin::CheckCollision()
{
	size_t size = m_playerBullet.size();
	for (size_t i = 0; i < size; i++)
	{
		auto& iter = m_playerBullet[i];
		if (iter->IsOutMap())
		{
			SAFE_DELETE(iter);
			m_playerBullet.erase(m_playerBullet.begin() + i);
			i--, size--;
		}
	}

}

void cBulletAdmin::CheckMonsterCollision()
{
	size_t size = m_mobBullet.size();
	for (size_t i = 0; i < size; i++)
	{
		auto& iter = m_mobBullet[i];
		if (iter->IsOutMap())
		{
			SAFE_DELETE(iter);
			m_mobBullet.erase(m_mobBullet.begin() + i);
			i--, size--;
		}
	}

}