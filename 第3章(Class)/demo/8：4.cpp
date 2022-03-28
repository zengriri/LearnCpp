#include <string_view>

class A
{
public:
	virtual std::string_view getName() { return "A"; }
};

class B : public A
{
public:
	// note use of final specifier on following line -- that makes this function no longer overridable
	std::string_view getName() override final { return "B"; } // okay, overrides A::getName()
};

class C : public B
{
public:
	std::string_view getName() override { return "C"; } // compile error: overrides B::getName(), which is final
};

/*
	在上面的代码中，B::getName() 覆盖了 A::getName()，这很好。但是 B::getName() 具有 final 说明符，这意味着对该函数的任何进一步覆盖都应视为错误
	事实上， C::getName() 试图覆盖 B::getName() （这里的覆盖说明符不相关，它只是为了良好的实践），所以编译器会给出一个编译错误。
*/