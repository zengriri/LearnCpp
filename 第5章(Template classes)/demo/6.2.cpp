template <typename T = int, typename U = int> // default T and U to type int
struct Pair
{
	T first{};
	U second{};
};

template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

int main()
{
	Pair<int, int> p1{1, 2}; // explicitly specify class template Pair<int, int> (C++11 onward)
	Pair p2{1, 2};			 // CTAD used to deduce Pair<int, int> from the initializers (C++17)

	Pair p3; // uses default Pair<int, int>

	return 0;
}