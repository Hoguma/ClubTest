#include "DXUT.h"
#include "cSceneManager.h"

#include "cScene.h"
//클래스를 전방선언 해줬다면 cpp파일에선 헤더파일을 추가해주자(윗줄을 지워보면 왜 추가해야하는지 알수 있다)

cSceneManager::cSceneManager()
	:m_nowScene(nullptr), m_nextScene(nullptr)
{
}


cSceneManager::~cSceneManager()
{
	Release();
}

void cSceneManager::Release()
{
	if (m_nowScene)
		m_nowScene->Release();

	for (auto iter : m_scenes)
	{
		SAFE_DELETE(iter.second);
	}
	m_scenes.clear();
}

cScene* cSceneManager::AddScene(const string& key, cScene* scenePtr)
{
	if (!scenePtr)//어떤 이유로 없는 씬을 넣었을땐 추가하지 않는다
		return nullptr;

	if (m_scenes.find(key) != m_scenes.end())//이름이 겹치려 해도 추가하지 않는다
		return nullptr;

	m_scenes.insert(make_pair(key, scenePtr));//위의 사항이 적용되지 않으면 추가한다
	return scenePtr;
}

cScene* cSceneManager::ChangeScene(const string& key)
{
	auto find = m_scenes.find(key);
	if (find == m_scenes.end())
		return nullptr;//없는 씬으로는 바꾸지 않는다

	m_nextScene = find->second;//바꿀 씬을 예약해둔다
	return m_nextScene;
}

void cSceneManager::Update()
{
	if (m_nextScene)//대기중인 씬이 있는지 확인해본다
	{
		if (m_nowScene)//현재 씬이 있으면
			m_nowScene->Release();//비워주고
		m_nextScene->Init();
		m_nowScene = m_nextScene;//씬을 바꿔준다
		m_nextScene = nullptr;
	}
	if (m_nowScene)
		m_nowScene->Update();
}

void cSceneManager::Render()
{
	if (m_nowScene)
		m_nowScene->Render();
}
