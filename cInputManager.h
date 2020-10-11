#pragma once
#include "singleton.h"
class cInputManager : public singleton<cInputManager>
{
private:
	bool NowMouseInput[2];
	bool OldMouseInput[2];

	bool NowInput[256];
	bool OldInput[256];
public:
	cInputManager();
	virtual ~cInputManager();

	bool MouseLPress();
	bool MouseLDown();
	bool MouseLUp();

	bool MouseRPress();
	bool MouseRDown();
	bool MouseRUp();

	bool KeyPress(int key);
	bool KeyDown(int key);
	bool KeyUp(int key);

	void Update();

	D3DXVECTOR2 GetMousePos() {
		POINT pt;
		GetCursorPos(&pt);
		ScreenToClient(DXUTGetHWND(), &pt);

		return D3DXVECTOR2((float)pt.x, (float)pt.y);
	}

};

#define INPUT cInputManager::GetInstance()