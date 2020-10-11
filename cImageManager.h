#pragma once

#include "singleton.h"
//C++에서는 구조체와 클래스의 차이가 거의 없다
//struct는 기본이 public
//class는 기본이 private로 되어있을뿐
//내부 구조도 거의 같고 안에 함수도 넣을수 있다.
struct texture
{
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;

	texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
		:texturePtr(texturePtr), info(info)
	{
	}

	void Render(float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(float x, float y, float rot = 0);

	void CenterRender(float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(float x, float y, float rot = 0);
};

class cFrame {
public:
	int NowFrame = 0;
	int StartFrame = 0;
	int EndFrame = 0;

	unsigned long FrameSkip = 0;
	unsigned long FrameDelay = 0;
	void SetFrame(int start, int end, unsigned long delay);

	bool Frame();
};

//singleton을 상속받았다. 어디서든 접근이 가능해짐
class cImageManager : public singleton <cImageManager>
{
private:
	LPD3DXSPRITE m_sprite;
	LPD3DXSPRITE m_sprite2;
	map<string, texture*> m_images;
	map<string, vector<texture*>*> VECIMAGES;

	LPD3DXFONT pFont = nullptr;
	LPD3DXFONT lpFont;
	LPD3DXFONT lpFont2;
	//stl에는 map이라는 자료형이 있는데
	//이름으로 값을 찾을때, 가장 높은 효율을 보여준다
private:
	void Init();
	void Release();
public:
	cImageManager();
	~cImageManager();

	texture* AddImage(const string& key, const string& path);
	texture* FindImage(const string& key);

	void Begin();
	void End();

	void Render(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(texture* texturePtr, float x, float y, float rot = 0);
	//좌상단을 기준으로 이미지 랜더링

	void CenterRender(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(texture* texturePtr, float x, float y, float rot = 0);
	//가운데를 기준으로 이미지 랜더링

	void LostDevice();
	void ResetDevice();
	void drawText(TCHAR * str, D3DXVECTOR2 pos, int type, D3DCOLOR color, bool End);
	void PrintText(const string & str, Vec2 pos, float size, D3DCOLOR color, bool Center);
	vector<texture*>* FINDVECIMAGE(const string& key, int max);
	vector<texture*>* ADDVECIMAGE(const string & key, const string & path, int max);
	//함수의 인자는 기본적으로 4개까지 사용하는것이 좋다.(4개를 넘어가면 급격히 느려진다)
	//자세한 이유는 나중에 레지스터와 시스템 캐시를 공부할때 알아보면 좋음
};

#define IMAGEMANAGER cImageManager::GetInstance()
//매번 함수들을 쓸때마다 cImageManager::GetInstance()->AddImage();해주는것은 상당히 번거로워서
//위와 같이 줄여서 사용한다