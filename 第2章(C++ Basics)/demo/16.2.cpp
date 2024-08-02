#include <array>
#include <iostream>

int main()
{
	const int arr[]{9, 8, 7, 6, 5};
	const int *ptr{arr}; // arr decays into a pointer to element 0

	// Prove that we're pointing at element 0
	std::cout << *ptr << ptr[0] << '\n'; // prints 99
	// Prove that ptr[1] is element 1
	std::cout << *(ptr + 1) << ptr[1] << '\n'; // prints 88

	// Now set ptr to point at element 3
	ptr = &arr[3];

	// Prove that we're pointing at element 3
	std::cout << *ptr << ptr[0] << '\n'; // prints 66
	// Prove that ptr[1] is element 4!
	std::cout << *(ptr + 1) << ptr[1] << '\n'; // prints 55

	return 0;
}