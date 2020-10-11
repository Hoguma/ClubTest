#include "DXUT.h"
#include "cImageManager.h"

void texture::Render(float x, float y, float size, float rot, D3DCOLOR color)
{
	IMAGEMANAGER->Render(this, x, y, size, rot, color);
}

void texture::Render(float x, float y, float rot)
{
	IMAGEMANAGER->Render(this, x, y, rot);
}

void texture::CenterRender(float x, float y, float size, float rot, D3DCOLOR color)
{
	IMAGEMANAGER->CenterRender(this, x, y, size, rot, color);
}

void texture::CenterRender(float x, float y, float rot)
{
	IMAGEMANAGER->CenterRender(this, x, y, rot);
}

cImageManager::cImageManager()
	:m_sprite(nullptr)
{
	Init();
}


cImageManager::~cImageManager()
{
	Release();
}

//�ҷ��� �̹����� �θ� �̸��� ���
texture* cImageManager::AddImage(const string& key, const string& path)
{
	auto find = m_images.find(key);//�̹� �ִ� �̸��� �ٽ� ������ �ϴ°� �ƴ��� Ȯ���غ���
	if (find == m_images.end())
	{
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;

		if (D3DXCreateTextureFromFileExA(g_device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			texture* text = new texture(texturePtr, info);
			m_images.insert(make_pair(key, text));
			return text;
		}
		#pragma region �ε�����
		DEBUG_LOG("ERROR! �̹��� �ε��� �����߽��ϴ�. ���ϰ�θ� �ٽ� Ȯ�����ּ���");
		DEBUG_LOG("\tkey :" << key.c_str() << "\t path : " << path.c_str());
#pragma endregion
		//�̹��� �ε��� �����������(���� ����, cpu�޸� �������) �̰����� ���� �ȴ�
		return nullptr;
	}
	//�̹� �ҷ��� �̹����� �ٽ� �ҷ����� �߰ų�
	//�ٸ� �̹����� ���� �̸����� ���� ������� �̰����� ���� �ȴ�
	return find->second;
}

texture* cImageManager::FindImage(const string& key)
{
	auto find = m_images.find(key);//�̸����� �̹����� ã�ƺ���
	if (find == m_images.end()) return nullptr;//������ nullptr�� ��´�
	return find->second;//������ �װ� ��´�
}

void cImageManager::Init()
{
	D3DXCreateSprite(g_device, &m_sprite);
	D3DXCreateFont(g_device, 50, 0, 10, 1, false, DEFAULT_CHARSET, 0, 0, 0, TEXT("Fixedsys"), &lpFont);
	D3DXCreateSprite(g_device, &m_sprite2);
	D3DXCreateFont(g_device, 90, 0, 20, 1, false, DEFAULT_CHARSET, 0, 0, 0, TEXT("Fixedsys"), &lpFont2);
}

void cImageManager::Release()
{
	for (auto iter : m_images)
	{
		iter.second->texturePtr->Release();
		SAFE_DELETE(iter.second);
	}
	m_images.clear();

	m_sprite->Release();
	m_sprite2->Release();

	SAFE_RELEASE(lpFont);
	SAFE_RELEASE(lpFont2);
}

void cImageManager::Begin()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_sprite2->Begin(D3DXSPRITE_ALPHABLEND);
}

void cImageManager::End()
{
	m_sprite->End();
	m_sprite2->End();
}

void cImageManager::Render(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;

		D3DXMatrixAffineTransformation2D(&mat, size, nullptr, rot, &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

void cImageManager::Render(texture* texturePtr, float x, float y, float rot)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;

		D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, rot, &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void cImageManager::CenterRender(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color)
{
	Render(texturePtr, x - texturePtr->info.Width / 2, y - texturePtr->info.Height / 2, size, rot, color);
}

void cImageManager::CenterRender(texture* texturePtr, float x, float y, float rot)
{
	Render(texturePtr, x - texturePtr->info.Width / 2, y - texturePtr->info.Height / 2, rot);
}

void cImageManager::drawText(TCHAR * str, D3DXVECTOR2 pos, int type, D3DCOLOR color, bool End)
{
	//mbstowcs(�����ڵ� ����, ��ȯ�ҷ��� �Ϲݹ��ڿ�, ������);

	D3DXMATRIXA16 mat;
	D3DXMatrixTranslation(&mat, pos.x, pos.y, 0.f);
	m_sprite->SetTransform(&mat); 
	m_sprite2->SetTransform(&mat);

	RECT re = { 0 };

	if (!End)
		lpFont->DrawTextW(m_sprite, str, lstrlen(str), &re, DT_NOCLIP, color);
	else
		lpFont2->DrawTextW(m_sprite2, str, lstrlen(str), &re, DT_NOCLIP, color);
}

void cImageManager::PrintText(const string & str, Vec2 pos, float size, D3DCOLOR color, bool Center)
{
	D3DXMATRIX mat;
	if (!Center) {
		D3DXCreateFontA(g_device, size, 0, 10, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "Fixedsys", &pFont);

		D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);
	}
	else {
		D3DXCreateFontA(g_device, size, 0, 0, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "Fixedsys", &pFont);

		D3DXMatrixTranslation(&mat, pos.x - size * (str.size() * 0.25), pos.y - size / 2.f, 0);
	}

	m_sprite->SetTransform(&mat);
	pFont->DrawTextA(m_sprite, str.c_str(), str.size(), nullptr, DT_NOCLIP, color);

	SAFE_RELEASE(pFont);
}

void cImageManager::LostDevice()
{
	m_sprite->OnLostDevice();
}

void cImageManager::ResetDevice()
{
	m_sprite->OnResetDevice();
}

void cFrame::SetFrame(int start, int end, unsigned long delay)
{
	StartFrame = NowFrame = start;
	EndFrame = end;
	FrameDelay = delay;
	FrameSkip = FrameDelay + timeGetTime();
}

bool cFrame::Frame()
{
	if (FrameSkip <= timeGetTime()) {
		if (NowFrame >= EndFrame) {
			NowFrame = StartFrame;
		}
		else NowFrame++;
		FrameSkip = FrameDelay + timeGetTime();

		return true;
	}
	return false;
}


vector<texture*>* cImageManager::ADDVECIMAGE(const string & key, const string & path, int max)
{
	auto find = VECIMAGES.find(key);
	if (find != VECIMAGES.end())
		return find->second;

	vector<texture*>* vec = new vector<texture*>();

	for (int i = 1; i <= max; i++)
	{
		LPDIRECT3DTEXTURE9 lpTexture;
		D3DXIMAGE_INFO info;

		char ch[256];
		wsprintfA(ch, path.c_str(), i);

		if (D3DXCreateTextureFromFileExA(g_device, ch, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, NULL, &info, nullptr, &lpTexture) == S_OK)
		{
			texture * text = new texture(lpTexture, info);
			vec->push_back(text);
		}
		else
		{
			SAFE_RELEASE(lpTexture);
		}
	}
	if (vec->empty())
	{
		SAFE_DELETE(vec);
		return nullptr;
	}
	VECIMAGES[key] = vec;
	return vec;
}
vector<texture*>* cImageManager::FINDVECIMAGE(const string & key, int max)
{
	return VECIMAGES[key];
}