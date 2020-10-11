#pragma once
#include "cMob.h"

class cDororo;
class cBullet;
class cBulletAdmin;
class cNormalMob : public cMob
{
private:

	cDororo* m_player;
	cBulletAdmin* m_pBullet;

	D3DXVECTOR2 tempTarget;
	D3DXVECTOR2 direction;

	float x, y;
	bool isplayercheck;
	float m_speed;
	bool b_once;

public:
	cNormalMob(const D3DXVECTOR2& pos, cDororo* player);
	~cNormalMob();

	virtual void Update() override;
	virtual void Render() override;
	void Release();

	D3DXVECTOR2 GetMPos() { return m_pos; }
};
