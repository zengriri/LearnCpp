enum Color // this enum is defined in the global namespace
{
	red, // so red is put into the global namespace
	green,
	blue,
};

int main()
{
	Color apple{red}; // my apple is red

	return 0;
}