#pragma once
class cScene abstract
{
public:
	virtual void Init() PURE;
	virtual void Release() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;

	cScene();
	virtual ~cScene();
	//상속을 시킬 클래스라면 소멸자는 virtual.
	//안그러면 8바이트의 메모리가 줄줄 샌다.
};