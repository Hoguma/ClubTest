#include "DXUT.h"
#include "cNormalMob.h"
#include "cDororo.h"
#include "cBulletAdmin.h"



cNormalMob::cNormalMob(const D3DXVECTOR2& pos, cDororo* player)
	:cMob(pos) , m_player(player)
{
	m_MonsterImage = IMAGEMANAGER->AddImage("normalmob", "./image/Mob/Normal/Mob.png");
	isplayercheck = false;
	b_once = true;

	score = 1500;
	m_HP = 10;
	m_size = 5.0f;
	m_gold = 30;
	
	m_name = "none";

	HitScore = 100;
}

cNormalMob::~cNormalMob()
{

}

void cNormalMob::Update()
{
	Vec2 playerPos = m_player->GetPos();
	float MPBx = m_pos.x - playerPos.x;
	float MPBy = m_pos.y - playerPos.y;
	float MPBl = sqrt((MPBx * MPBx) + (MPBy * MPBy));
	float playerSize = m_player->GetSize();
		
	if (500 + playerSize > MPBl && b_once)
	{
		isplayercheck = true;
		b_once = false;
		tempTarget = m_player->GetPos();
		direction = tempTarget - m_pos;
	}
		
	if (isplayercheck)
	{
		
		D3DXVec2Normalize(&direction, &direction);
		m_speed = 1000;
		m_pos += direction * (m_speed * DXUTGetElapsedTime());
	}
	else
	{
		m_speed = 300;
		m_pos.x -= m_speed * DXUTGetElapsedTime();
	}

}

void cNormalMob::Render()
{
	m_MonsterImage->CenterRender(m_pos.x, m_pos.y);
}

void cNormalMob::Release()
{
	SAFE_DELETE(m_player);
}
