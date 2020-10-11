#include "DXUT.h"
#include "stdafx.h"
#include "cDororo.h"
#include "cTimer.h"
#include "cDororoBullet.h"

cDororo::cDororo(Vec2 pos, vector<cBullet*>& playerBullet)
	: cPlayer(pos, playerBullet)
{
	m_playerImage = IMAGEMANAGER->AddImage("dororo", "./image/Player/Dororo/player.png");
	m_playerSImage = IMAGEMANAGER->AddImage("dororoS", "./image/Player/Dororo/player_ON.png");
	m_playerCS = IMAGEMANAGER->AddImage("CSdororo", "./image/Player/Dororo/CS.png");
	b_fire = true;
	b_playerskill = false;
	m_cspos.x = -768;
	m_cspos.y = 420;
	b_cson = false;
	m_playerName = "Dororo";

	m_speed = 300;
	m_Hp = 50;
	
}


cDororo::~cDororo()
{
	if (m_timer)	SAFE_DELETE(m_timer);
}

void cDororo::Update()
{
	if (m_Hp > 0)
	{
		nowtime = GetTickCount();
		if (m_timer) m_timer->Update();
		if (!b_playerskill)
		{
			m_size = 5.f;
			m_speed = 300;
			for (auto iter : m_fireBullet)
			{
				iter->InputOffense(10);
			}
		}
		else
		{
			m_size = 3.f;
			m_speed = 500;
			for (auto iter : m_fireBullet)
			{
				iter->InputOffense(50);
			}
		}
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
			/*mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);

			mciOpen.lpstrDeviceType = L"mpegvideo";
			mciOpen.lpstrElementName = L"./sound/Attack.mp3";
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);


			dwID = mciOpen.wDeviceID;

			mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);*/
		}
		if (GetAsyncKeyState(VK_SPACE) && nowtime - starttime > 20000)
		{
			starttime = nowtime;
			b_playerskill = true;
			b_cson = true;
			startStime = nowtime;
			m_Hp += 10;
		}
	}
}

void cDororo::Render()
{

	if (b_playerskill)
	{
		if (b_cson)
		{
			IMAGEMANAGER->CenterRender(m_playerCS, m_cspos.x, m_cspos.y);
			if (m_cspos.x >= 500 && m_cspos.x <= 700)
			{
				m_csspeed = 300;
				m_cspos.x += m_csspeed * DXUTGetElapsedTime();
			}
			else
			{
				m_csspeed = 1500;
				m_cspos.x += m_csspeed * DXUTGetElapsedTime();
				if (m_cspos.x > WINSIZEX + (WINSIZEX / 2))
				{
					m_cspos.x = -768;
					m_cspos.y = 420;
					b_cson = false;
				}
			}
		}

		if (startStime + 10000 < nowtime)
			b_playerskill = false;
		IMAGEMANAGER->CenterRender(m_playerSImage, m_pos.x, m_pos.y);
	}
	else
		m_playerImage->CenterRender(m_pos.x, m_pos.y);

	TCHAR HpStr[11];
	wsprintf(HpStr, L"%09d", m_Hp);

	//IMAGEMANAGER->PrintText("50 / " + to_string(m_Hp), Vec2(100, 50), 30, D3DCOLOR_XRGB(255, 255, 255), true);
}