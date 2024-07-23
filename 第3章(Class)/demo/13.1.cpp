#include <algorithm> // for std::max
#include <iostream>

class Foo
{
private:
	int m_x{};
	int m_y{};

public:
	Foo(int x, int y)
		: m_y{std::max(x, y)}, m_x{m_y} // issue on this line
	{
	}

	void print() const
	{
		std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
	}
};

int main()
{
	Foo foo{6, 7};
	foo.print();

	return 0;
}

/**
 * 在上面的例子中，我们的目的是计算传入的初始化值中较大的一个（通过 std::max(x, y)），然后使用这个值来初始化 m_x 和 m_y。但是，在作者的机器上，以下打印结果：Foo(-858993460, 7)
 * why?
 * 尽管 m_y 在成员初始化列表中列在第一位，但由于 m_x 在类中首先定义，因此 m_x 首先被初始化。 m_x 被初始化为尚未初始化的 m_y 的值。最后，m_y 被初始化为初始化值中的较大者
 *
 */