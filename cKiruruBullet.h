#pragma once
#include "cMobBullet.h"
class cKiruruBullet : public cMobBullet
{
private:
	Vec2 vDirection;
public:
	cKiruruBullet(const Vec2& pos, const Vec2& direction, float speed);
	virtual ~cKiruruBullet();

	virtual void Update() override;
};

