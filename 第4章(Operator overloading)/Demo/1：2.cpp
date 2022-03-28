#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents) : m_cents{ cents } { }

	// add Cents + Cents using a friend function
		// This function is not considered a member of the class, even though the definition is inside the class
	friend Cents operator+(const Cents &c1, const Cents &c2)
	{
		// use the Cents constructor and operator+(int, int)
		// we can access m_cents directly because this is a friend function
		return Cents{ c1.m_cents + c2.m_cents };
	}

	int getCents() const { return m_cents; }
};

int main()
{
	Cents cents1{ 6 };
	Cents cents2{ 8 };
	Cents centsSum{ cents1 + cents2 };
	std::cout << "I have " << centsSum.getCents() << " cents.\n";

	return 0;
}

/*
	即使友元函数不是类的成员，如果需要，它们仍然可以在类中定义：

	我们通常不建议这样做，因为非平凡的函数定义最好保存在单独的 .cpp 文件中
*/