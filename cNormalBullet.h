#pragma once
#include "cMobBullet.h"
class cDororo;

class cNormalBullet : public cMobBullet
{
private:

	D3DXVECTOR2 vDirection;
public:
	cNormalBullet(const Vec2& pos, const Vec2& direction, float speed);
	virtual ~cNormalBullet();

	virtual void Update() override;
};

