#pragma once
#include "cBullet.h"

class cDororoBullet : public cBullet
{
private:

public:
	cDororoBullet(const D3DXVECTOR2& pos);
	virtual ~cDororoBullet();

	virtual void Update() override;
};

