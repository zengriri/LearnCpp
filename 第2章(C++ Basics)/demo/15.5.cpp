#include <iostream>

struct Foo
{
	int a{};
	int b{};
	int c{};
};

int main()
{
	Foo foo{1, 2, 3};

	Foo x = foo; // copy initialization
	Foo y(foo);	 // direct initialization
	Foo z{foo};	 // list initialization

	std::cout << x.a << ' ' << y.b << ' ' << z.c << '\n';

	return 0;
}