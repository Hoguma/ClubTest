#include "DXUT.h"
#include "cMobAdmin.h"
#include "cMob.h"
#include "cNormalMob.h"
#include "cInvisibleMob.h"
#include "cBulletMob.h"
#include "cMobBullet.h"
#include "cBullet.h"
#include "cDororo.h"
#include "cKiruru.h"


cMobAdmin::cMobAdmin(cBulletAdmin* bullet, cDororo* player)
	:m_bulletAdmin(bullet), m_player(player)
{
	m_gameover = IMAGEMANAGER->AddImage("gameover", "./image/GameOver.png");
	m_Clear = IMAGEMANAGER->AddImage("Clear", "./image/Clear.png");
	m_Hit = IMAGEMANAGER->AddImage("Hit", "./image/Hit.png");
	m_UI = IMAGEMANAGER->AddImage("UI", "./image/UI.png");
	mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);
	mciOpen.lpstrDeviceType = L"mpegvideo";
	mciOpen.lpstrElementName = L"./sound/Ingame.mp3";
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);


	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
		(DWORD)(LPVOID)&m_mciPlayParms);
	score = 0;
	b_boss = false;
	once = true;
	pMHp = m_player->GetHP();
	PlayOnce = true;
	b_Phase2 = false;
	b_bossdead = false;
	play_once - true;
	b_hit = false;
	isBossDead = false;
	play_Once = true;
}


cMobAdmin::~cMobAdmin()
{
	Reset();
}




void cMobAdmin::Reset()
{
	for (auto iter : m_mobList)
		SAFE_DELETE(iter);
	m_mobList.clear();
}


void cMobAdmin::Init()
{
	InvisibleStartTime = GetTickCount();
	NormalStartTime = GetTickCount();
	BulletStartTime = GetTickCount();
	
}

void cMobAdmin::Update()
{
	if (b_boss & PlayOnce) {
		mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);

		mciOpen.lpstrDeviceType = L"mpegvideo";
		mciOpen.lpstrElementName = L"./sound/Boss.mp3";
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);


		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);
		PlayOnce = false;
	}
	else if (isBossDead)
	{
		if (play_Once)
		{
			mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);

			mciOpen.lpstrDeviceType = L"mpegvideo";
			mciOpen.lpstrElementName = L"./sound/Clear.mp3";
			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);


			dwID = mciOpen.wDeviceID;

			mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);
			play_Once = false;
		}
		else
		{
			if (GetAsyncKeyState(VK_SPACE))
			{
				SCENEMANAGER->ChangeScene("Main");
			}
		}
	}
	pHp = m_player->GetHP();
	for (auto iter : m_mobList)
		iter->Update();
	if (pHp > 0)
	{
		CreatMonster();
		CheckMonsterCollider();
	}
	else if (play_once)
	{
		mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);

		mciOpen.lpstrDeviceType = L"mpegvideo";
		mciOpen.lpstrElementName = L"./sound/Die.mp3";
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);


		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);
		play_once = false;
		Reset();
	}
	
	else
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			SCENEMANAGER->ChangeScene("Main");
		}
	}
	
	NormalNowTime = GetTickCount();
	InvisibleNowTime = GetTickCount();
	BulletNowTime = GetTickCount();
	slowNowTime = GetTickCount();
	HitNowTime = GetTickCount();

	if (GetAsyncKeyState(VK_SHIFT))
	{
		m_player->inputHp(1000);
	}
}

void cMobAdmin::Render()
{
	for (auto iter : m_mobList)
		iter->Render();

	m_UI->CenterRender(WINSIZEX / 2, 50); 
	IMAGEMANAGER->PrintText(to_string(score), Vec2(226, 70), 30, D3DCOLOR_XRGB(255, 255, 255), true);
	IMAGEMANAGER->PrintText(to_string(pMHp)+ " / " + to_string(pHp), Vec2(80, 70), 30, D3DCOLOR_XRGB(255, 255, 255), true);
	if (pHp <= 0)
	{
		TCHAR scoreStr[11];
		wsprintf(scoreStr, L"%09d", score);

		IMAGEMANAGER->drawText(scoreStr, D3DXVECTOR2(WINSIZEX/2 - 100, WINSIZEY/2 -85), 3, D3DCOLOR_XRGB(0, 0, 0), true);
		m_gameover->CenterRender(WINSIZEX / 2, WINSIZEY / 2);
	}
	if (b_hit)
	{
		m_Hit->CenterRender(1280 / 2, 410);
		if (HitStartTime + 150 < HitNowTime)
		{
			b_hit = false;
		}
	}
	if (isBossDead)
	{
		m_Clear->CenterRender(WINSIZEX/2, WINSIZEY/2);
		TCHAR scoreStr[11];
		wsprintf(scoreStr, L"%09d", score);

		IMAGEMANAGER->drawText(scoreStr, D3DXVECTOR2(WINSIZEX / 2 - 100, WINSIZEY / 2 - 85), 3, D3DCOLOR_XRGB(0, 0, 0), true);
	}
}

void cMobAdmin::CreatMonster()
{

	if (score < 100000) 
	{
		if (NormalNowTime - NormalStartTime > 500) {
			m_mobList.push_back(new cNormalMob(Vec2(1290, ((rand() % 700) + 110)), m_player));
			NormalStartTime = NormalNowTime;
		}
		if (InvisibleNowTime - InvisibleStartTime > 5000) {
			m_mobList.push_back(new cInvisibleMob(D3DXVECTOR2(1290, ((rand() % 700) + 110)), m_player));
			InvisibleStartTime = InvisibleNowTime;
		}
		if (BulletNowTime - BulletStartTime > 2000) {
			m_mobList.push_back(new cBulletMob(D3DXVECTOR2(1290, ((rand() % 700) + 110)), m_bulletAdmin->GetMobBullet(), m_player));
			BulletStartTime = BulletNowTime;
		}
	}
	else
	{
		if (!b_boss)
		{
			m_mobList.push_back(new cKiruru(Vec2(1290, 420), m_bulletAdmin->GetMobBullet(), m_player));
			b_boss = true;
		}
		
	}

	if(b_Phase2)
	{
		if (NormalNowTime - NormalStartTime > 1000) {
			m_mobList.push_back(new cNormalMob(Vec2(1290, ((rand() % 700) + 110)), m_player));
			NormalStartTime = NormalNowTime;
		}
		if (InvisibleNowTime - InvisibleStartTime > 5000) {
			m_mobList.push_back(new cInvisibleMob(D3DXVECTOR2(1290, ((rand() % 700) + 110)), m_player));
			InvisibleStartTime = InvisibleNowTime;
		}
		if (BulletNowTime - BulletStartTime > 4000) {
			m_mobList.push_back(new cBulletMob(D3DXVECTOR2(1290, ((rand() % 700) + 110)), m_bulletAdmin->GetMobBullet(), m_player));
			BulletStartTime = BulletNowTime;
		}
	}
}

void cMobAdmin::CreateBoss()
{
	m_mobList.push_back(new cKiruru(Vec2(1290, WINSIZEY / 2), m_bulletAdmin->GetMobBullet(), m_player));
}
void cMobAdmin::Release()
{
}

void cMobAdmin::CheckMonsterCollider()
{
	size_t size = m_mobList.size();
	for (size_t i = 0; i < size; i++)
	{
		auto& iter = m_mobList[i];
		if (iter->IsOutMap())
		{
			SAFE_DELETE(iter);
			m_mobList.erase(m_mobList.begin() + i);
			i--, size--;
		}
	}

	vector<cBullet*> & playerBulletVector = m_bulletAdmin->GetPlayerBullet();
	vector<cMobBullet*> & mobBulletVector = m_bulletAdmin->GetMobBullet();

	for (auto miter = m_mobList.begin(); miter != m_mobList.end();)
	{
		b_coll = false;
		int Hp = (*miter)->GetHp();

		Vec2 mobPos;
		for (auto pbiter = playerBulletVector.begin(); pbiter != playerBulletVector.end();)
		{
			mobPos = (*miter)->GetPos();
			Vec2 playerBulletPos = (*pbiter)->GetPos();

			float mobSize = (*miter)->GetSize();
			float playerBulletSize = (*pbiter)->GetSize();

			float MPBx = mobPos.x - playerBulletPos.x;
			float MPBy = mobPos.y - playerBulletPos.y;

			float MPBl = sqrt((MPBx * MPBx) + (MPBy * MPBy));

			if (mobSize + playerBulletSize > MPBl)
			{
				sndPlaySound(L"./sound/Hit.wav", SND_ASYNC);
				damage = (*pbiter)->GetOffense();
				Hp -= damage;
				inputscore = (*miter)->GetHitScore();
				score += inputscore;
				(*miter)->inputHp(Hp);
				b_coll = true;
				SAFE_DELETE((*pbiter));
				pbiter = playerBulletVector.erase(pbiter);
			}
			else
				++pbiter;
		}

		if (b_coll)
		{
			if (Hp <= 0)
			{
				if ((*miter)->GetMonsterName() == "none")
				{

				}
				if ((*miter)->GetMonsterName() == "kiruru")
				{
					isBossDead = true;
					
				}
				inputscore = (*miter)->GetScore();
				score += inputscore;
				SAFE_DELETE((*miter));
				miter = m_mobList.erase(miter);
			}

		}
		else
			++miter;

	}

	for (auto miter = m_mobList.begin(); miter != m_mobList.end();)
	{
		Vec2 mobPos = (*miter)->GetPos();
		Vec2 playerPos = m_player->GetPos();

		

		float mobSize = (*miter)->GetSize();
		float playerSize = m_player->GetSize();

		float PMx = playerPos.x - mobPos.x;
		float PMy = playerPos.y - mobPos.y;

		float PMl = sqrt((PMx * PMx) + (PMy * PMy));
		if (playerSize + mobSize > PMl)
		{
			b_hit = true;
			HitStartTime = HitNowTime;
			if ((*miter)->GetMonsterName() == "none")
			{
				pHp -= 5;
				m_player->inputHp(pHp);
				SAFE_DELETE((*miter));
				miter = m_mobList.erase(miter);

				
			}
			else if ((*miter)->GetMonsterName() == "kiruru")
			{
				pHp -= 100;
				m_player->inputHp(pHp);
				++miter;
			}
		}
		else
			++miter;
	}

	for (auto mbiter = mobBulletVector.begin(); mbiter != mobBulletVector.end();)
	{
		Vec2 mobBulletPos = (*mbiter)->GetPos();
		Vec2 playerPos = m_player->GetPos();

		float mobBulletSize = (*mbiter)->GetSize();
		float playerSize = m_player->GetSize();

		float PMBx = playerPos.x - mobBulletPos.x;
		float PMBy = playerPos.y - mobBulletPos.y;

		float PMBl = sqrt((PMBx * PMBx) + (PMBy * PMBy));
		if (playerSize + mobBulletSize > PMBl && (*mbiter)->GetName() == "none")
		{
			b_hit = true;
			pHp -= 5;
			m_player->inputHp(pHp);
			SAFE_DELETE((*mbiter));
			mbiter = mobBulletVector.erase(mbiter);
		}

		else if (playerSize + mobBulletSize > PMBl && (*mbiter)->GetName() == "slow")
		{
			b_hit = true;
			pHp -= 2;
			m_player->inputHp(pHp);
			SAFE_DELETE((*mbiter));
			mbiter = mobBulletVector.erase(mbiter);
		}

		else if (playerSize + mobBulletSize > PMBl && (*mbiter)->GetName() == "heal")
		{
			b_hit = true;
			pHp -= 1;
			m_player->inputHp(pHp);
			SAFE_DELETE((*mbiter));
			mbiter = mobBulletVector.erase(mbiter);
		}

		else if (playerSize + mobBulletSize > PMBl && (*mbiter)->GetName() == "kiruru")
		{
			b_hit = true;
			pHp -= 10;
			m_player->inputHp(pHp);
			SAFE_DELETE((*mbiter));
			mbiter = mobBulletVector.erase(mbiter);
		}
		else
			++mbiter;
	}

	for (auto miter = m_mobList.begin(); miter != m_mobList.end();)
	{
		int Hp = (*miter)->GetHp();
		for (auto mbiter = mobBulletVector.begin(); mbiter != mobBulletVector.end();)
		{
			Vec2 kiPos = (*miter)->GetPos();
			float size = (*miter)->GetSize();
			Vec2 hPos = (*mbiter)->GetPos();
			float bsize = (*mbiter)->GetSize();

			float KMBx = kiPos.x - hPos.x;
			float KMBy = kiPos.y - hPos.y;

			float KMBl = sqrt((KMBx * KMBx) + (KMBy * KMBy));
			if (size + bsize > KMBl && (*miter)->GetMonsterName() == "kiruru" && (*mbiter)->GetName() == "heal")
			{
				Hp += 2;
				(*miter)->inputHp(Hp);
				SAFE_DELETE((*mbiter));
				mbiter = mobBulletVector.erase(mbiter);
			}
			else
				++mbiter;
		}
		++miter;
		
	}
	
}
