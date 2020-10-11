#pragma once
#include "singleton.h"

class cScene;//클래스도 전방선언이 가능하다
//헤더파일을 직접 추가하게 될경우, 헤더의 처리순서에서 문제가 생기거나
//같은 헤더를 여러번 추가하게 되어 문제가 발생할수 있다.
//그래서 헤더에는 클래스 이름만 추가하고, cpp파일에 헤더파일을 추가하는것을 '클래스 참조' 라고 한다
class cSceneManager : public singleton<cSceneManager>
{
private:
	//cScene temp; //클래스 전방선언시에는 클래스의 포인터만 사용할수 있다
	cScene* m_nowScene;
	cScene* m_nextScene;
	map<string, cScene*> m_scenes;

	void Release();
public:
	cSceneManager();
	~cSceneManager();

	cScene* AddScene(const string& key, cScene* scenePtr);
	cScene* ChangeScene(const string& key);

	void Update();
	void Render();
};

#define SCENEMANAGER cSceneManager::GetInstance()

