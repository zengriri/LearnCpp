#include <string_view>

class A
{
public:
	virtual std::string_view getName() { return "A"; }
};

class B final : public A // note use of final specifier here
{
public:
	std::string_view getName() override { return "B"; }
};

class C : public B // compile error: cannot inherit from final class
{
public:
	std::string_view getName() override { return "C"; }
};

/*
	在上面的示例中，B 类被声明为 final。因此，当 C 尝试从 B 继承时，编译器将给出编译错误。
*/