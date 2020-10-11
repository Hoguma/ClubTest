#include "DXUT.h"
#include "cInputManager.h"


cInputManager::cInputManager()
{
}


cInputManager::~cInputManager()
{
}

bool cInputManager::MouseLPress()
{
	return (NowMouseInput[0] == true && OldMouseInput[0] == true);
}

bool cInputManager::MouseLDown()
{
	return (NowMouseInput[0] == true && OldMouseInput[0] == false);
}

bool cInputManager::MouseLUp()
{
	return (NowMouseInput[0] == false && OldMouseInput[0] == true);
}

bool cInputManager::MouseRPress()
{
	return (NowMouseInput[1] == true && OldMouseInput[1] == true);
}

bool cInputManager::MouseRDown()
{
	return (NowMouseInput[1] == true && OldMouseInput[1] == false);
}

bool cInputManager::MouseRUp()
{
	return (NowMouseInput[1] == false && OldMouseInput[1] == true);
}

bool cInputManager::KeyPress(int key)
{
	return (NowInput[key] == true && OldInput[key] == true);
}

bool cInputManager::KeyDown(int key)
{
	return (NowInput[key] == true && OldInput[key] == false);
}

bool cInputManager::KeyUp(int key)
{
	return (NowInput[key] == false && OldInput[key] == true);
}

void cInputManager::Update()
{
	for (int i = 0; i < 2; i++)
		OldMouseInput[i] = NowMouseInput[i];
	for (int i = 0; i < 256; i++)
		OldInput[i] = NowInput[i];

	for (int i = 0; i < 256; i++) {
		if (GetAsyncKeyState(i)) {
			NowInput[i] = true;
		}
		else
			NowInput[i] = false;
	}

	if (GetAsyncKeyState(VK_LBUTTON))
		NowMouseInput[0] = true;
	else
		NowMouseInput[0] = false;

	if (GetAsyncKeyState(VK_RBUTTON))
		NowMouseInput[1] = true;
	else
		NowMouseInput[1] = false;
}
