#include "DXUT.h"
#include "cTimer.h"
#include "cGiroro.h"
#include "cDororoBullet.h"


cGiroro::cGiroro(Vec2 pos, vector<cBullet*>& playerBullet)
	: cPlayer(pos, playerBullet)
{
	m_playerImage = IMAGEMANAGER->AddImage("giroro", "./image/Player/Giroro/player.png");
	m_playerCS = IMAGEMANAGER->AddImage("CSdororo", "./image/Player/Giroro/CS.png");

	b_fire = true;
	b_playerskill = false;
	m_cspos.x = -768;
	m_cspos.y = 420;
	b_cson = false;
	m_playerName = "Giroro";

	m_speed = 100;
	m_Hp = 100;
}


cGiroro::~cGiroro()
{
}

void cGiroro::Update()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_pos.x -= m_speed * DXUTGetElapsedTime();
		if (m_pos.x < 20)
			m_pos.x += m_speed * DXUTGetElapsedTime();
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_pos.x += m_speed * DXUTGetElapsedTime();
		if (m_pos.x > 1260)
			m_pos.x -= m_speed * DXUTGetElapsedTime();
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_pos.y -= m_speed * DXUTGetElapsedTime();
		if (m_pos.y < 120)
			m_pos.y += m_speed * DXUTGetElapsedTime();
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_pos.y += m_speed * DXUTGetElapsedTime();
		if (m_pos.y > 700)
			m_pos.y -= m_speed * DXUTGetElapsedTime();
	}

	if (GetAsyncKeyState(90) & 0x8000 && b_fire == true)
	{
		m_timer = new cTimer(0.4, [&]()->void {
			b_fire = true;
			m_timer = nullptr;
		});
		b_fire = false;
		m_fireBullet.push_back(new cDororoBullet(D3DXVECTOR2(m_pos.x + 20, m_pos.y)));
	}
}

void cGiroro::Render()
{
	m_playerImage->CenterRender(m_pos.x, m_pos.y);
}
