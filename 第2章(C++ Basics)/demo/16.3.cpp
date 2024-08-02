#include <iostream>

int main()
{
	constexpr int arr[]{9, 7, 5, 3, 1};

	const int *begin{arr};				  // begin points to start element
	const int *end{arr + std::size(arr)}; // end points to one-past-the-end element

	for (; begin != end; ++begin) // iterate from begin up to (but excluding) end
	{
		std::cout << *begin << ' '; // dereference our loop variable to get the current element
	}

	return 0;
}