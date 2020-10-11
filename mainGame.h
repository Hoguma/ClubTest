#pragma once
class mainGame
{
private:

public:
	mainGame();
	~mainGame();

	void Init();
	void Release();
	void Update();
	void Render();

	void LostDevice();
	void ResetDevice();
};

