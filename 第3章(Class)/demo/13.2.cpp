#include <iostream>

class Dollars
{
private:
	int m_dollars{};

public:
	explicit Dollars(int d) // now explicit
		: m_dollars{d}
	{
	}

	int getDollars() const { return m_dollars; }
};

void print(Dollars d)
{
	std::cout << "$" << d.getDollars();
}

int main()
{
	print(5); // compilation error because Dollars(int) is explicit

	print(Dollars{5}); // ok: create Dollars and pass to print() (no conversion required)

	Dollars d1(5); // ok

	return 0;
}