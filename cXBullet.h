#pragma once
#include "cMobBullet.h"

class cXBullet : public cMobBullet
{
private:
	Vec2 vDirection;

public:
	cXBullet(const Vec2& pos, const Vec2& direction, float speed);
	virtual ~cXBullet();

	virtual void Update() override;
};

