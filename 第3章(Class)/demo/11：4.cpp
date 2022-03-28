#include <iostream>

class Base
{
public:
	// Here's our overloaded operator<<
	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		// Delegate printing responsibility for printing to member function print()
		return b.print(out);
	}

	// We'll rely on member function print() to do the actual printing
	// Because print is a normal member function, it can be virtualized
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	// Here's our override print function to handle the Derived case
	std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b{};
	std::cout << b << '\n';

	Derived d{};
	std::cout << d << '\n'; // note that this works even with no operator<< that explicitly handles Derived objects

	Base& bref{ d };
	std::cout << bref << '\n';

	return 0;
}

/*
    请注意，我们不需要为每个派生类定义 operator<<！处理 Base 对象的版本适用于 Base 对象和从 Base 派生的任何类！
*/