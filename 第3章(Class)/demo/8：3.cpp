#include <string_view>

class A
{
public:
	virtual std::string_view getName1(int x) { return "A"; }
	virtual std::string_view getName2(int x) { return "A"; }
	virtual std::string_view getName3(int x) { return "A"; }
};

class B : public A
{
public:
	std::string_view getName1(short int x) override { return "B"; } // compile error, function is not an override
	std::string_view getName2(int x) const override { return "B"; } // compile error, function is not an override
	std::string_view getName3(int x) override { return "B"; } // okay, function is an override of A::getName3(int)

};

int main()
{
	return 0;
}

/*
    上面的程序产生了两个编译错误：一个针对 B::getName1()，一个针对 B::getName2()，因为两者都没有覆盖先前的函数。 B::getName3() 确实覆盖了 A::getName3()，因此该行不会产生错误
*/