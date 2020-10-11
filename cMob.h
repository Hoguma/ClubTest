#pragma once

class cBullet;
class cMob abstract
{
protected:
	texture * m_MonsterImage;

	D3DXVECTOR2 m_pos;

	float m_size;

	float m_speed;
	int score;

	int m_HP;

	int m_gold;

	DWORD StartTime = GetTickCount();
	DWORD NowTime;

	//DWORD HitStartTime = 0;

	int HitScore;

	string m_name;


public:
	cMob::cMob(const D3DXVECTOR2& pos);
	virtual ~cMob();

	virtual void Update() PURE;
	virtual void Render() PURE;
	bool IsOutMap();


	//void SpellHit();
	string GetMonsterName() { return m_name; }
	int GetHitScore() { return HitScore; }
	int GetScore() { return score; }
	D3DXVECTOR2 GetPos() { return m_pos; }
	float GetSize() { return m_size; }
	int GetHp() { return m_HP; }
	int inputHp(int inputHp);
	int GetGold() { return m_gold; }

};