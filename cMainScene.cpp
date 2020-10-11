#include "DXUT.h"
#include "stdafx.h"
#include "cMainScene.h"
#include "cButton.h"


cMainScene::cMainScene()
{
	//스타트 버튼
	m_simage = IMAGEMANAGER->AddImage("Play_Normal", "./image/Button/Play/Play_Normal.png");
	m_simage = IMAGEMANAGER->AddImage("Play_OnCursor", "./image/Button/Play/Play_OnCursor.png");
	m_simage = IMAGEMANAGER->AddImage("Play_Click", "./image/Button/Play/Play_Click.png");
	//조작키 설명 버튼
	m_himage = IMAGEMANAGER->AddImage("HowTo_Normal", "./image/Button/How/How_Normal.png");
	m_himage = IMAGEMANAGER->AddImage("HowTo_OnCursor", "./image/Button/How/How_OnCursor.png");
	m_himage = IMAGEMANAGER->AddImage("HowTo_Click", "./image/Button/How/How_Click.png");
	//조작키 설명 이미지
	m_hbimage = IMAGEMANAGER->AddImage("HowTo_win", "./image/Button/How/HowTo.png");
	//게임 설명 버튼
	m_eximage = IMAGEMANAGER->AddImage("What_OnCursor", "./image/Button/Explain/What_OnCursor.png");
	m_eximage = IMAGEMANAGER->AddImage("What_Click", "./image/Button/Explain/What_Click.png");
	m_eximage = IMAGEMANAGER->AddImage("What_Normal", "./image/Button/Explain/What_Normal.png");
	//넥스트 버튼
	m_nimage = IMAGEMANAGER->AddImage("Next_Normal", "./image/Button/Explain/Next/Next_Normal.png");
	m_nimage = IMAGEMANAGER->AddImage("Next_Click", "./image/Button/Explain/Next/Next_Click.png");
	m_nimage = IMAGEMANAGER->AddImage("Next_OnCursor", "./image/Button/Explain/Next/Next_OnCursor.png");
	//크레딧 버튼
	m_cimage = IMAGEMANAGER->AddImage("Credit_Normal", "./image/Button/Credit/Credit_Normal.png");
	m_cimage = IMAGEMANAGER->AddImage("Credit_Click", "./image/Button/Credit/Credit_Click.png");
	m_cimage = IMAGEMANAGER->AddImage("Credit_OnCursor", "./image/Button/Credit/Credit_OnCursor.png");
	//크레딧 이미지
	m_creimage = IMAGEMANAGER->AddImage("Credit", "./image/Button/Credit/Credit.png");
	//게임설명 이미지
	m_eximageArr[0] = IMAGEMANAGER->AddImage("Explain1", "./image/Button/Explain/MobExplain/(0).png");
	m_eximageArr[1] = IMAGEMANAGER->AddImage("Explain2", "./image/Button/Explain/MobExplain/(1).png");
	m_eximageArr[2] = IMAGEMANAGER->AddImage("Explain3", "./image/Button/Explain/MobExplain/(2).png");
	m_eximageArr[3] = IMAGEMANAGER->AddImage("Explain4", "./image/Button/Explain/MobExplain/(3).png");
	m_eximageArr[4] = IMAGEMANAGER->AddImage("Explain5", "./image/Button/Explain/MobExplain/(4).png");

	m_background = IMAGEMANAGER->AddImage("MBackGround", "./image/MainBackGround.png");

	

	m_bpos.x = WINSIZEX / 2;
	m_bpos.y = WINSIZEY / 2;
	
	page = 0;
}


cMainScene::~cMainScene()
{
}

void cMainScene::Init()
{
	m_start = new cButton(D3DXVECTOR2(900, 200), "Play");
	m_howto = new cButton(D3DXVECTOR2(900, 350), "HowTo");
	m_explain = new cButton(Vec2(900, 500), "What");
	m_next = new cButton(Vec2(1000, 600), "Next");
	m_credit = new cButton(Vec2(1100, 200), "Credit");
	b_howto = false;
	b_ex = false;
	b_credit = false;
	play_once = true;
}

void cMainScene::Release()
{
}

void cMainScene::Update()
{
	if (play_once)
	{
		mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);

		mciOpen.lpstrDeviceType = L"mpegvideo";
		mciOpen.lpstrElementName = L"./sound/Main.mp3";
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);


		dwID = mciOpen.wDeviceID;

		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);
		play_once = false;
	}
	if (b_howto)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			b_howto = false;
		}
	}
	else if (b_ex)
	{
		
		if (GetAsyncKeyState(VK_SPACE))
		{
			b_ex = false;
			page = 0;
			m_next = new cButton(Vec2(1000, 600), "Next");	
		}
	}
	else if (b_credit)
	{

		if (GetAsyncKeyState(VK_SPACE))
		{
			b_credit = false;
		}
	}
	else 
	{
		if (m_howto->Update())
		{
			b_howto = true;
		}
		if (m_start->Update())
		{
			SCENEMANAGER->ChangeScene("ingame");
			mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);
		}
		if (m_explain->Update())
		{
			b_ex = true;
		}
		if (m_credit->Update())
		{
			b_credit = true;
		}
	}
}

void cMainScene::Render()
{
	m_background->CenterRender(WINSIZEX/2, WINSIZEY/2);

	m_start->Render();
	m_howto->Render();
	m_explain->Render();
	m_credit->Render();


	if (b_howto)
	{
		IMAGEMANAGER->CenterRender(m_hbimage, m_bpos.x, m_bpos.y);
	}
	if (b_ex)
	{
		IMAGEMANAGER->CenterRender(m_eximageArr[page], m_bpos.x, m_bpos.y);
		if (page < 4)
		{
			if (m_next->Update())
			{
				page += 1;
			}
			m_next->Render();
		}
		else
			SAFE_DELETE(m_next);
		
	}
	if (b_credit)
	{
		IMAGEMANAGER->CenterRender(m_creimage, m_bpos.x, m_bpos.y);
	}
}
