#include<iostream>

class Base
{
protected:
    int m_value {};

public:
    Base(int value)
        : m_value { value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base { value }
    {
    }
};
int main()
{
    Base base { 5 };
    base.identify();

    Derived derived { 7 };
    derived.identify();

    return 0;
}

/*
    This prints:
        I am a Base
        I am a Base

    当调用 derived.identify() 时，编译器会查看是否在 Derived 类中定义了函数 identify()。它没有。然后它开始查找继承的类（在本例中为 Base）。
    Base 定义了一个 identify() 函数，所以它使用了这个函数。换句话说，使用 Base::identify() 是因为 Derived::identify() 不存在。

    这意味着如果基类提供的行为足够，我们可以简单地使用基类行为。
    

*/