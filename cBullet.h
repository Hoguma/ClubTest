#pragma once
class cBullet abstract
{
protected:
	texture* m_image;
	D3DXVECTOR2 m_pos;

	int m_offense;
	double m_size;
public:
	cBullet(const D3DXVECTOR2& pos, double size);
	virtual ~cBullet();

	virtual void Update() PURE;
	void Render();

	bool IsOutMap();

	int GetOffense() { return m_offense; }
	void InputOffense(int offendse) { m_offense = offendse; }
	const D3DXVECTOR2 & GetPos() { return m_pos; }
	float GetSize() { return m_size; }
};