struct Something
{
	int x;	  // no initialization value (bad)
	int y{};  // value-initialized by default
	int z{2}; // explicit default value
};

int main()
{
	Something s1; // s1.x is uninitialized, s1.y is 0, and s1.z is 2

	return 0;
}