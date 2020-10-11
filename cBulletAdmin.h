#pragma once
class cMobBullet;
class cBullet;
class cNormalBullet;
class cBulletAdmin
{
private:
	vector<cBullet*> m_playerBullet;
	vector<cMobBullet*> m_mobBullet;

	DWORD NowTime;
	DWORD StartTime;

private:
	void CheckCollision();
	void CheckMonsterCollision();
	
public:
	cBulletAdmin();
	~cBulletAdmin();

	void Reset();

	void Update();
	void Render();

	vector<cBullet*>& GetPlayerBullet() { return m_playerBullet; }
	vector<cMobBullet*>& GetMobBullet() { return m_mobBullet; }
};

