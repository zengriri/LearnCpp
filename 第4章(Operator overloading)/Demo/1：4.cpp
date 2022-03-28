#include <iostream>

class Cents
{
private:
  int m_cents{};

public:
  Cents(int cents)
    : m_cents{ cents }
  {}

  int getCents() const { return m_cents; }
};

// note: this function is not a member function nor a friend function!
Cents operator+(const Cents& c1, const Cents& c2)
{
  // use the Cents constructor and operator+(int, int)
  // we don't need direct access to private members here
  return Cents{ c1.getCents() + c2.getCents() };
}

int main()
{
  Cents cents1{ 6 };
  Cents cents2{ 8 };
  Cents centsSum{ cents1 + cents2 };
  std::cout << "I have " << centsSum.getCents() << " cents.\n";

  return 0;
}

/*
	因为普通函数和友元函数的工作方式几乎相同（它们只是对私有成员具有不同级别的访问权限），所以我们通常不会区分它们。

	一个区别是类中的友元函数声明也用作原型。使用普通函数版本，您必须提供自己的函数原型

	一般来说，如果可以使用现有的可用成员函数（接触类内部的函数越少越好），通常应该优先使用普通函数而不是友元函数。但是，不要仅仅为了将运算符重载为普通函数而不是友元函数而添加额外的访问函数！
*/