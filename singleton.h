	#pragma once

//싱글톤이란 클래스를 전역변수와 비슷하게 만들어 주는것을 의미한다.
template <typename T>
class singleton
{
private:
	//클래스 내부 변수에 static을 사용하게 되면
	//클래스를 따로 만들지 않아도 변수가 먼저 만들어지게 된다.
	static T* p;
public:
	singleton() {};
	virtual ~singleton() {};

	//함수에 static을 사용하게 되면
	//클래스가 없어도 클래스이름만으로 함수를 사용할수 있게 된다
	static T* GetInstance()
	{
		if (!p)
			p = new T;
		return p;
	}
	static void ReleaseInstance()
	{
		if (p)
			delete p;
		p = nullptr;
	}
	//이제 이 singleton클래스를 상속받게 되면, 그 클래스는 전역변수와 비슷하게 사용할수 있다.
	//하지만 처리속도가 일반클래스에 비해 느리고
	//객체 지향을 무시하는 방법중에 하나이므로
	//꼭 필요한곳이 아니면 사용하지 않는것이 좋다.
};

template <typename T>
T* singleton<T>::p = nullptr;
//스태틱 변수는 내부에선 초기화를 못하고, 클래스 외부에서 한번 초기화 해주어야 한다