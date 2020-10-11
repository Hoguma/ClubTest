#include "DXUT.h"
#include "cKiruru.h"
#include "cDororo.h"
#include "cMobBullet.h"
#include "cNormalBullet.h"
#include "cXBullet.h"
#include "cXFBullet.h"
#include "cKiruruBullet.h"
#include "cSplitBullet.h"

cKiruru::cKiruru(const D3DXVECTOR2& pos, vector<cMobBullet*>& bullet, cDororo* player)
	:cMob(pos), m_player(player), m_firebullet(bullet)
{
	m_MonsterImage = IMAGEMANAGER->AddImage("Kiruru", "./image/Mob/Kiruru/Mob.png");
	m_MonsterImage2 = IMAGEMANAGER->AddImage("Kiruru2", "./image/Mob/Kiruru/Mob21.png");

	//m_speed = 100;
	score = 9000000;
	m_HP = 20;
	m_size = 7.0f;
	//m_gold = 30;
	m_name = "kiruru";
	b_phase = false;
	b_move = true;
	phaseStack = 0;
	m_speed = 100;

	HitScore = 100;
}


cKiruru::~cKiruru()
{
}

void cKiruru::Update()
{
	p1p1NowTime = GetTickCount();
	p1p2NowTime = GetTickCount();
	p1p3NowTime = GetTickCount();
	p2p1NowTime = GetTickCount();
	p2p2NowTime = GetTickCount();
	p2p3NowTime = GetTickCount();
	if (m_pos.x > 1000)
	{
		m_pos.x -= 100 * DXUTGetElapsedTime();
	}
	else
	{
		if (!b_phase)
		{
			if (m_pos.y <= 130)
			{
				b_move = false;
			}
			if (m_pos.y >= 610)
			{
				b_move = true;
			}
			if (b_move)
				m_pos.y -= 100 * DXUTGetElapsedTime();
			else
				m_pos.y += 100 * DXUTGetElapsedTime();
				

			if (p1p1NowTime - p1p1StartTime > 500)
			{
				Phase1Pattern1();
				p1p1StartTime = p1p1NowTime;
			}

			if (p1p2NowTime - p1p2StartTime > 2000)
			{
				Phase1Pattern2();
				p1p2StartTime = p1p2NowTime;
			}

			if (p1p3NowTime - p1p3StartTime > (rand() % 30000) + 10000)
			{
				Phase1Pattern3();
				p1p3StartTime = p1p3NowTime;
				++phaseStack;
			}
			if (phaseStack == 3)
			{
				b_phase = true;
			}
		}
		else
		{
			m_pos.x = 1000;
			m_pos.y = 420;
			m_size = 50.f;

			
			if (m_HP > 1000)
			{
				if (p1p3NowTime - p1p3StartTime > (rand() % 30000) + 10000)
				{
					Phase1Pattern3();
					p1p3StartTime = p1p3NowTime;
				}

				if (p2p2NowTime - p2p2StartTime > 1500)
				{
					Phase2Pattern2();
					p2p2StartTime = p2p2NowTime;
				}

				if (p1p2NowTime - p1p2StartTime > 2000)
				{
					Phase1Pattern2();
					p1p2StartTime = p1p2NowTime;
				}
			}
			else
			{

				if (p2p2NowTime - p2p2StartTime > 2000)
				{
					Phase2Pattern2();
					p2p2StartTime = p2p2NowTime;
				}

				if (p1p2NowTime - p1p2StartTime > 1200)
				{
					Phase1Pattern2();
					p1p2StartTime = p1p2NowTime;
				}

				if (p2p3NowTime - p2p3StartTime > 2500)
				{
					Phase2Pattern3();
					p2p3StartTime = p2p3NowTime;
				}

			}
		}
	}
	if (m_HP > 2000)
	{
		m_HP = 2000;
	}
}

void cKiruru::Render()
{
	if (!b_phase)
		m_MonsterImage->CenterRender(m_pos.x, m_pos.y);
	else
		m_MonsterImage2->CenterRender(m_pos.x, m_pos.y);
}

void cKiruru::Phase1Pattern1()
{
	D3DXVECTOR2 tempTarget1 = m_player->GetPos();
	D3DXVECTOR2 direction1 = tempTarget1 - m_pos;
	D3DXVec2Normalize(&direction1, &direction1);
	m_firebullet.push_back(new cXBullet(m_pos, direction1, 7));
}

void cKiruru::Phase1Pattern2()
{
	float angle = 0;
	float rad = D3DX_PI * 2 / 60;
	// 16Àº ÃÑ¾Ë °³¼ö

	for (float i = 0; i < 60; i++, angle += rad)
	{
		Vec2 Direction = Vec2(m_pos.x + (cosf(angle) * 5), m_pos.y + (sinf(angle) * 5));

		Direction = Direction - m_pos;

		D3DXVec2Normalize(&Direction, &Direction);

		m_firebullet.push_back(new cNormalBullet(m_pos, Direction, 7));

	}
}

void cKiruru::Phase1Pattern3()
{
	for (int i = 0; i < 20; i++)
	{
		m_firebullet.push_back(new cXFBullet(Vec2(rand() % 1280, rand() % 720), 2, this));
	}
}

/*void cKiruru::Phase2Pattern1()
{
		float angle = 0;

		float rad = 3.14 * 2 / 80;
		// 16Àº ÃÑ¾Ë °³¼ö

		for (float i = 0; i < 80; i++, angle += rad)
		{
			Vec2 Direction = Vec2(m_pos.x + (cosf(angle) * 5), m_pos.y + (sinf(angle) * 5));

			Direction = Direction - m_pos;

			D3DXVec2Normalize(&Direction, &Direction);

			m_firebullet.push_back(new cNormalBullet(m_pos, Direction, 10));
		}
}*/

void cKiruru::Phase2Pattern2()
{
	D3DXVECTOR2 tempTarget1 = m_player->GetPos();
	D3DXVECTOR2 direction1 = tempTarget1 - m_pos;
	D3DXVec2Normalize(&direction1, &direction1);
	m_firebullet.push_back(new cKiruruBullet(m_pos, direction1, 10));
}

void cKiruru::Phase2Pattern3()
{
	D3DXVECTOR2 tempTarget1 = m_player->GetPos();
	D3DXVECTOR2 direction1 = tempTarget1 - m_pos;
	D3DXVec2Normalize(&direction1, &direction1);
	m_firebullet.push_back(new cSplitBullet(m_pos, direction1, 5));
}

