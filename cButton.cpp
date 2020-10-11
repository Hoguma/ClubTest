#include "DXUT.h"
#include "cButton.h"
#include "stdafx.h"


cButton::cButton(D3DXVECTOR2 Pos, const string& key)
	: m_pos(Pos)
{

	//DEBUG_LOG("1");
	m_Normal = IMAGEMANAGER->FindImage(key + "_Normal");
	m_OnCursor = IMAGEMANAGER->FindImage(key + "_OnCursor");
	m_Click = IMAGEMANAGER->FindImage(key + "_Click");
	SettingRect();
}


cButton::~cButton()
{
	Release();
}

bool cButton::Update()
{
	POINT ptMouse;
	GetCursorPos(&ptMouse);
	ScreenToClient(DXUTGetHWND(), &ptMouse);
	if (PtInRect(&m_rc, ptMouse)) {
		b_OnCursor = true;
	}
	else {
		b_OnCursor = false;
		b_Click = false;
	}

	if (b_OnCursor) {
		if (INPUT->MouseLPress())
			b_Click = true;
		else if (INPUT->MouseLUp())
			return true;
		else
			b_Click = false;
	}
	return false;
}

void cButton::Render()
{
	if (b_Click)
	{
		IMAGEMANAGER->CenterRender(m_Click, m_pos.x, m_pos.y);
	}
	else if (b_OnCursor)
	{
		IMAGEMANAGER->CenterRender(m_OnCursor, m_pos.x, m_pos.y);
	}
	else
	{
		IMAGEMANAGER->CenterRender(m_Normal, m_pos.x, m_pos.y);
	}
}

void cButton::Release()
{
}
