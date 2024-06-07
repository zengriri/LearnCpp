#include <iostream>

void print(double x) // print takes a double parameter
{
	std::cout << x << '\n';
}

int main()
{
	int y{ 5 };
	print(y); // y is of type int

	return 0;
}