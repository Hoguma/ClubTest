#pragma once
#include "cMob.h"
class cDororo;
class cBulletAdmin;
class cMobBullet;
class cXBullet;
class cBulletMob : public cMob
{
private:
	cDororo* m_player;
	cBulletAdmin* m_pBullet;
	texture* m_MonsterImage1;
	texture* m_MonsterImage2;
	texture* m_MonsterImage3;

	vector<cMobBullet*>& m_firebullet;

	DWORD imageNowtime;
	DWORD imageStarttime = GetTickCount();

	DWORD barfNowtime;
	DWORD barfStarttime = GetTickCount();

	D3DXVECTOR2 tempTarget;
	D3DXVECTOR2 direction;

	float MPBl;
	float playerSize;
	float x, y;
	bool isplayercheck;
	float m_speed;
	bool b_stop;
public:
	cBulletMob(const Vec2& pos, vector<cMobBullet*>& bullet, cDororo* player);
	virtual ~cBulletMob();


	virtual void Update() override;
	virtual void Render() override;
};

