#pragma once

#include "singleton.h"
//C++������ ����ü�� Ŭ������ ���̰� ���� ����
//struct�� �⺻�� public
//class�� �⺻�� private�� �Ǿ�������
//���� ������ ���� ���� �ȿ� �Լ��� ������ �ִ�.
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

//singleton�� ��ӹ޾Ҵ�. ��𼭵� ������ ��������
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
	//stl���� map�̶�� �ڷ����� �ִµ�
	//�̸����� ���� ã����, ���� ���� ȿ���� �����ش�
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
	//�»���� �������� �̹��� ������

	void CenterRender(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(texture* texturePtr, float x, float y, float rot = 0);
	//����� �������� �̹��� ������

	void LostDevice();
	void ResetDevice();
	void drawText(TCHAR * str, D3DXVECTOR2 pos, int type, D3DCOLOR color, bool End);
	void PrintText(const string & str, Vec2 pos, float size, D3DCOLOR color, bool Center);
	vector<texture*>* FINDVECIMAGE(const string& key, int max);
	vector<texture*>* ADDVECIMAGE(const string & key, const string & path, int max);
	//�Լ��� ���ڴ� �⺻������ 4������ ����ϴ°��� ����.(4���� �Ѿ�� �ް��� ��������)
	//�ڼ��� ������ ���߿� �������Ϳ� �ý��� ĳ�ø� �����Ҷ� �˾ƺ��� ����
};

#define IMAGEMANAGER cImageManager::GetInstance()
//�Ź� �Լ����� �������� cImageManager::GetInstance()->AddImage();���ִ°��� ����� ���ŷο���
//���� ���� �ٿ��� ����Ѵ�