#include <iostream>
class Base
{
public:
	virtual ~Base() // note: virtual
	{
		std::cout << "Calling ~Base()\n";
	}
};

class Derived : public Base
{
private:
	int* m_array;

public:
	Derived(int length)
		: m_array{ new int[length] }
	{
	}

	virtual ~Derived() // note: virtual
	{
		std::cout << "Calling ~Derived()\n";
		delete[] m_array;
	}
};

int main()
{
	Derived *derived{ new Derived(5) };
	Base *base{ derived };

	delete base;

	return 0;
}

/*
    我们确实希望delete函数调用Derived的析构函数（它会依次调用Base的析构函数），否则m_array不会被删除。我们通过将 Base 的析构函数设为虚拟来做到这一点：
*/