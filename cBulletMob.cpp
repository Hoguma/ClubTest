#include "DXUT.h"
#include "cBulletMob.h"
#include "cMobBullet.h"
#include "cNormalBullet.h"
#include "cDororo.h"
#include "cXFBullet.h"
#include "cXBullet.h"

cBulletMob::cBulletMob(const Vec2& pos, vector<cMobBullet*>& bullet, cDororo* player)
	: cMob(pos), m_firebullet(bullet), m_player(player)
{
	m_MonsterImage = IMAGEMANAGER->AddImage("bulletmob", "./image/Mob/Bullet/Mob.png");
	m_MonsterImage1 = IMAGEMANAGER->AddImage("bulletmob1", "./image/Mob/Bullet/Mob(1).png");
	m_MonsterImage2 = IMAGEMANAGER->AddImage("bulletmob2", "./image/Mob/Bullet/Mob(2).png");
	m_MonsterImage3 = IMAGEMANAGER->AddImage("bulletmob3", "./image/Mob/Bullet/Mob(3).png");
	m_speed = 200;
	score = 5000;
	m_HP = 50;
	m_size = 16.0f;
	m_gold = 30;

	m_name = "none";

	HitScore = 15;
	b_stop = false;
	srand((unsigned)time(NULL));
}


cBulletMob::~cBulletMob()
{
}

void cBulletMob::Update()
{
	
	if (m_pos.x < 980)
	{
		b_stop = true;
		NowTime = GetTickCount();
		imageNowtime = GetTickCount();
		
		if (NowTime - StartTime >= 3300)
		{
			D3DXVECTOR2 tempTarget1 = m_player->GetPos();
			D3DXVECTOR2 direction1 = tempTarget1 - m_pos;
			D3DXVec2Normalize(&direction1, &direction1); 
			m_firebullet.push_back(new cNormalBullet(D3DXVECTOR2(m_pos.x - 40, m_pos.y), direction1, 10));
			Vec2 tempTarget2 = Vec2(m_player->GetPos().x, m_player->GetPos().y + rand() % 50);
			D3DXVECTOR2 direction2 = tempTarget2 - m_pos;
			D3DXVec2Normalize(&direction2, &direction2);
			m_firebullet.push_back(new cNormalBullet(D3DXVECTOR2(m_pos.x - 40, m_pos.y), direction2, 10));
			Vec2 tempTarget3 = Vec2(m_player->GetPos().x, m_player->GetPos().y + (rand() % 100)+50);
			D3DXVECTOR2 direction3 = tempTarget3 - m_pos;
			D3DXVec2Normalize(&direction3, &direction3);
			m_firebullet.push_back(new cNormalBullet(D3DXVECTOR2(m_pos.x - 40, m_pos.y), direction3, 10));
			Vec2 tempTarget4 = Vec2(m_player->GetPos().x, m_player->GetPos().y + (rand() % 150) + 100);
			D3DXVECTOR2 direction4 = tempTarget4 - m_pos;
			D3DXVec2Normalize(&direction4, &direction4);
			m_firebullet.push_back(new cNormalBullet(D3DXVECTOR2(m_pos.x - 40, m_pos.y), direction4, 10));
			Vec2 tempTarget5 = Vec2(m_player->GetPos().x, m_player->GetPos().y + (rand() % 200) + 150);
			D3DXVECTOR2 direction5 = tempTarget5 - m_pos;
			D3DXVec2Normalize(&direction5, &direction5);
			m_firebullet.push_back(new cNormalBullet(D3DXVECTOR2(m_pos.x - 40, m_pos.y), direction5, 10));
			Vec2 tempTarget6 = Vec2(m_player->GetPos().x, m_player->GetPos().y + (rand() % 250) + 200);
			D3DXVECTOR2 direction6 = tempTarget6 - m_pos;
			D3DXVec2Normalize(&direction6, &direction6);
			m_firebullet.push_back(new cNormalBullet(D3DXVECTOR2(m_pos.x - 40, m_pos.y), direction6, 10));


			StartTime = NowTime;

		}
	}
	else
		m_pos.x -= 100 * DXUTGetElapsedTime();

}

void cBulletMob::Render()
{
	if (b_stop)
	{
		if (imageNowtime - imageStarttime <= 1000)
			m_MonsterImage->CenterRender(m_pos.x, m_pos.y);
		else if (imageNowtime - imageStarttime <= 2000 && imageNowtime - imageStarttime > 1000)
			m_MonsterImage1->CenterRender(m_pos.x, m_pos.y);
		else if (imageNowtime - imageStarttime <= 3000 && imageNowtime - imageStarttime > 2000)
			m_MonsterImage2->CenterRender(m_pos.x, m_pos.y);
		else if (imageNowtime - imageStarttime <= 3100 && imageNowtime - imageStarttime > 3000)
			m_MonsterImage1->CenterRender(m_pos.x, m_pos.y);
		else if (imageNowtime - imageStarttime <= 3200 && imageNowtime - imageStarttime > 3100)
			m_MonsterImage->CenterRender(m_pos.x, m_pos.y);
		else if (imageNowtime - imageStarttime <= 3300 && imageNowtime - imageStarttime > 3200)
			m_MonsterImage3->CenterRender(m_pos.x, m_pos.y);
		else {
			m_MonsterImage->CenterRender(m_pos.x, m_pos.y);
			imageStarttime = imageNowtime;
		}
	}
	else
		m_MonsterImage->CenterRender(m_pos.x, m_pos.y);
}
