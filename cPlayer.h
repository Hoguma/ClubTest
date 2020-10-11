#pragma once
class cBullet;
class cPlayer abstract
{
protected:
	texture* m_playerImage;
	texture* m_playerCS;
	bool b_fire;
	Vec2 m_pos;
	Vec2 m_cspos;
	float m_csspeed;
	bool b_cson;
	bool b_playerskill;

	DWORD nowtime;
	DWORD starttime;

	float m_size;
	float m_speed;
	int m_Hp;
	string m_playerName;

	vector<cBullet*>& m_fireBullet;

public:
	cPlayer(const D3DXVECTOR2& pos, vector<cBullet*>& bullet);
	virtual ~cPlayer() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	bool IsOutMap();
	int inputHp(int inputHp);
	float GetSize() { return m_size; }
	float GetSpeed() { return m_speed; }
	void InputSpeed(int speed) { m_speed = speed; }
	Vec2 GetPos() { return m_pos; }
	int GetHP() { return m_Hp; }
};

