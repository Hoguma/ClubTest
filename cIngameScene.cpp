#include "DXUT.h"
#include "cIngameScene.h"

#include "cScroolMap.h"
#include "cBulletAdmin.h"
#include "cDororo.h"
#include "cMobAdmin.h"

cIngameScene::cIngameScene()
{
}


cIngameScene::~cIngameScene()
{
}

void cIngameScene::Init()
{
	srand((unsigned)time(NULL));
	m_map = new cScroolMap();
	m_bullet = new cBulletAdmin();
	
	m_player = new cDororo(Vec2(200, 300), m_bullet->GetPlayerBullet());
	m_mob = new cMobAdmin(m_bullet, m_player);
}

void cIngameScene::Release()
{
	SAFE_DELETE(m_map);
	SAFE_DELETE(m_player);
	SAFE_DELETE(m_bullet);
	SAFE_DELETE(m_mob);
}

void cIngameScene::Update()
{
	m_map->Update(50);
	m_player->Update();
	m_bullet->Update();
	m_mob->Update();
}

void cIngameScene::Render()
{
	m_map->Render();
	m_player->Render();
	m_bullet->Render();
	m_mob->Render();
}
