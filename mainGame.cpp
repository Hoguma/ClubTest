#include "DXUT.h"
#include "mainGame.h"

#include "cIngameScene.h"
#include "cTitleScene.h"
#include "cMainScene.h"

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
	Release();	
}

void mainGame::Init()
{
	SCENEMANAGER->AddScene("ingame", new cIngameScene);
	SCENEMANAGER->AddScene("Title", new cTitleScene);
	SCENEMANAGER->AddScene("Main", new cMainScene);

	SCENEMANAGER->ChangeScene("Title");
}

void mainGame::Release()
{
	cImageManager::ReleaseInstance();
	cSceneManager::ReleaseInstance();
}

void mainGame::Update()
{
	INPUT->Update();
	SCENEMANAGER->Update();
}

void mainGame::Render()
{
	IMAGEMANAGER->Begin();

	SCENEMANAGER->Render();

	IMAGEMANAGER->End();
}

void mainGame::LostDevice()
{
}

void mainGame::ResetDevice()
{
}
