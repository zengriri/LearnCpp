#include <iostream>
class Base
{
private:
	int m_value {};

public:
	Base(int value)
		: m_value { value }
	{
	}

	int getValue() const { return m_value; }
};

class Derived : public Base
{
public:
	Derived(int value)
		: Base { value }
	{
	}


	int getValue() = delete; // mark this function as inaccessible
};

int main()
{
	Derived derived { 7 };

	// The following won't work because getValue() has been deleted!
	std::cout << derived.getValue();

	return 0;
}

/*
	在上面的示例中，我们已将 getValue() 函数标记为已删除。这意味着当我们尝试调用函数的派生版本时，编译器会报错。
	
	请注意，getValue() 的基本版本仍然可以访问。这意味着 Derived 对象仍然可以通过首先将 Derived 对象向上转换为 Base 来访问 getValue()：
	int main()
	{
		Derived derived { 7 };

		// We can still access the function deleted in the Derived class through the Base class
		std::cout << static_cast<Base&>(derived).getValue();

		return 0;
	}
*/