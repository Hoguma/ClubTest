#pragma once
#include "cMob.h"
class cDororo;
class cBulletAdmin;
class cInvisibleMob : public cMob
{
private:
	cDororo* m_player;
	cBulletAdmin* m_pBullet;
	texture* m_MonstersImage;

	D3DXVECTOR2 tempTarget;
	D3DXVECTOR2 direction;

	float MPBl;
	float playerSize;
	float x, y;
	bool isplayercheck;
	float m_speed;
	bool b_once;
public:
	cInvisibleMob(const D3DXVECTOR2& pos, cDororo* player);
	virtual ~cInvisibleMob();

	virtual void Update() override;
	virtual void Render() override;
};

