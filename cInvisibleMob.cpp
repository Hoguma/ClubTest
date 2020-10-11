#include "DXUT.h"
#include "cInvisibleMob.h"
#include "cDororo.h"

cInvisibleMob::cInvisibleMob(const D3DXVECTOR2& pos, cDororo* player)
	:cMob(pos), m_player(player)
{
	m_MonsterImage = IMAGEMANAGER->AddImage("invisiblemob", "./image/Mob/Invisible/Mob.png");
	m_MonstersImage = IMAGEMANAGER->AddImage("invisiblemob_ON", "./image/Mob/Invisible/Mob_ON.png");

	m_speed = 100;
	score = 3000;
	m_HP = 20;
	m_size = 7.0f;
	m_gold = 30;

	m_name = "none";

	HitScore = 10;
}


cInvisibleMob::~cInvisibleMob()
{
}

void cInvisibleMob::Update()
{
	Vec2 playerPos = m_player->GetPos();
	float MPBx = m_pos.x - playerPos.x;
	float MPBy = m_pos.y - playerPos.y;
	MPBl = sqrt((MPBx * MPBx) + (MPBy * MPBy));
	playerSize = m_player->GetSize();
	Vec2 direction = playerPos - m_pos;
	D3DXVec2Normalize(&direction, &direction);
	m_pos += direction * 2.5;
}

void cInvisibleMob::Render()
{
	if (100 + playerSize > MPBl) m_MonstersImage->CenterRender(m_pos.x, m_pos.y);
	else m_MonsterImage->CenterRender(m_pos.x, m_pos.y);
}
