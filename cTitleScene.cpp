#include "DXUT.h"
#include "cTitleScene.h"


cTitleScene::cTitleScene()
{
	m_image = IMAGEMANAGER->AddImage("Title", "./image/Title.png");

	SCENEMANAGER->ChangeScene("Main");
	mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);

	mciOpen.lpstrDeviceType = L"mpegvideo";
	mciOpen.lpstrElementName = L"./sound/Title.mp3";
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);


	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);

	b_click = false;
}


cTitleScene::~cTitleScene()
{

}

void cTitleScene::Init()
{
}

void cTitleScene::Release()
{
}

void cTitleScene::Update()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		SCENEMANAGER->ChangeScene("Main");
		mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);
	}
}

void cTitleScene::Render()
{
	m_image->CenterRender(1280/2, 720/2);
}
