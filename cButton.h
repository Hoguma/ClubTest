#pragma once
class cButton
{
private:

	D3DXVECTOR2 m_pos;
	texture * m_Normal = nullptr;
	texture * m_OnCursor = nullptr;
	texture * m_Click = nullptr;
	bool b_OnCursor;
	bool b_Click;
	RECT m_rc;

	void SettingRect() {
		SetRect(&m_rc, m_pos.x - m_Normal->info.Width / 2,
			m_pos.y - m_Normal->info.Height / 2,
			m_pos.x + m_Normal->info.Width / 2,
			m_pos.y + m_Normal->info.Height / 2);
	};

public:
	cButton(D3DXVECTOR2 Pos, const string& key);
	~cButton();

	bool Update();
	void Render();
	void Release();

};
