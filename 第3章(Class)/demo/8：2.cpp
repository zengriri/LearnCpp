#include <iostream>
#include <string_view>

class Base
{
public:
    virtual std::string_view getName() const { return "Base"; } // note addition of virtual keyword
};

class Derived: public Base
{
public:
    virtual std::string_view getName() const { return "Derived"; }
};

int main()
{
    Derived derived;
    Base& rBase{ derived };
    std::cout << "rBase is a " << rBase.getName() << '\n';

    return 0;
}

/*
    因为 rBase 是对 Derived 对象的 Base 部分的引用，当 rBase.getName() 被评估时，它通常会解析为 Base::getName()
    但是， Base::getName() 是虚拟的，它告诉程序去查看在 Base 和 Derived 之间是否还有可用的函数的派生版本
    在这种情况下，它将解析为 Derived::getName()！
*/