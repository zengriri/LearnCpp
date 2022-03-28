#include <iostream>
class Base
{
public:
	int m_value {};
};

class Derived : public Base
{
private:
	using Base::m_value;

public:
	Derived(int value)
	// We can't initialize m_value, since it's a Base member (Base must initialize it)
	{
		// But we can assign it a value
		m_value = value;
	}
};

int main()
{
	Derived derived { 7 };

	// The following won't work because m_value has been redefined as private
	std::cout << derived.m_value;

	return 0;
}

/*
	请注意，这允许我们采用设计不佳的基类并将其数据封装在派生类中.或者，不是公开继承 Base 的成员并通过覆盖其访问说明符将 m_value 设为私有，我们可以私有继承 Base，
	我们可以私下继承 Base，这会导致 Base 的所有成员一开始都是私下继承的。
*/