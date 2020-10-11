#pragma once

class cMobBullet abstract
{
protected:
	texture* m_image;
	D3DXVECTOR2 m_pos;

	string name;

	float m_speed;
	double m_size;
public:
	cMobBullet(const Vec2& pos, double size, float speed);
	virtual ~cMobBullet();

	bool isDestroy;

	virtual void Update() PURE;
	void Render();

	bool IsOutMap();

	const D3DXVECTOR2 & GetPos() { return m_pos; }
	float GetSize() { return m_size; }
	string GetName() { return name; }
};