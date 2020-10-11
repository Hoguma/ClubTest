#pragma once
#include "cMobBullet.h"
class cKiruru;
class cXFBullet : public cMobBullet
{
private:
	cKiruru* m_mob;
	Vec2 m_FPos;
public:
	cXFBullet(const Vec2& pos, float speed, cKiruru* mob);
	virtual ~cXFBullet();

	virtual void Update() override;
};

