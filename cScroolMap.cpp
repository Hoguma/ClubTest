#include "DXUT.h"
#include "cScroolMap.h"


cScroolMap::cScroolMap()
	:m_scrool(0)
{
	m_backGround = IMAGEMANAGER->AddImage("mapBackGround", "./image/background.png");
}

cScroolMap::~cScroolMap()
{
}

void cScroolMap::Update(float speed)
{
	m_scrool -= speed * DXUTGetElapsedTime();
}

void cScroolMap::Render()
{
	//�ݺ��Ǵ� ��׶��� �̹����� ���÷� ����Ұ���
	float renderPos = (int)m_scrool % m_backGround->info.Width;
	m_backGround->CenterRender(1280 / 2 + renderPos - m_backGround->info.Width, 720 / 2);
	m_backGround->CenterRender(1280 / 2 + renderPos, 720 / 2);
}
