#include <iostream>

void print(double x) // print takes a double parameter
{
	std::cout << x << '\n';
}

inline double pi() { return 3.14159; }

double circumference(double radius)
{
	return 2.0 * pi() * radius;
}

int main()
{
	int y{ 5 };
	print(y); // y is of type int

	return 0;
}