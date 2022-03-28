#include <iostream>

class Base
{
public:
	virtual ~Base() = default;
	virtual const char* getName() const { return "Base"; }
};

class Derived : public Base
{
public:
	virtual const char* getName() const { return "Derived"; }
};

int main()
{
	Derived derived;
	const Base &base{ derived };
	// Calls Base::GetName() instead of the virtualized Derived::GetName()
	std::cout << base.Base::getName() << '\n';

	return 0;
}