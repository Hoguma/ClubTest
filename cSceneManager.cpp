#include "DXUT.h"
#include "cSceneManager.h"

#include "cScene.h"
//Ŭ������ ���漱�� ����ٸ� cpp���Ͽ��� ��������� �߰�������(������ �������� �� �߰��ؾ��ϴ��� �˼� �ִ�)

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
	if (!scenePtr)//� ������ ���� ���� �־����� �߰����� �ʴ´�
		return nullptr;

	if (m_scenes.find(key) != m_scenes.end())//�̸��� ��ġ�� �ص� �߰����� �ʴ´�
		return nullptr;

	m_scenes.insert(make_pair(key, scenePtr));//���� ������ ������� ������ �߰��Ѵ�
	return scenePtr;
}

cScene* cSceneManager::ChangeScene(const string& key)
{
	auto find = m_scenes.find(key);
	if (find == m_scenes.end())
		return nullptr;//���� �����δ� �ٲ��� �ʴ´�

	m_nextScene = find->second;//�ٲ� ���� �����صд�
	return m_nextScene;
}

void cSceneManager::Update()
{
	if (m_nextScene)//������� ���� �ִ��� Ȯ���غ���
	{
		if (m_nowScene)//���� ���� ������
			m_nowScene->Release();//����ְ�
		m_nextScene->Init();
		m_nowScene = m_nextScene;//���� �ٲ��ش�
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
