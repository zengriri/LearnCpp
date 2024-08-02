#include <iostream>
int main()
{
	const int arr[]{9, 7, 5, 3, 1};

	const int *ptr{arr}; // a normal pointer holding the address of element 0
	std::cout << ptr[2]; // subscript ptr to get element 2, prints 5  = *((ptr) + (n)) or *(ptr + 2)

	return 0;
}