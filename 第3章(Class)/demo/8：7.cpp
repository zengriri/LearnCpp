#include <iostream>
class Base
{
public:
    ~Base() // note: not virtual
    {
        std::cout << "Calling ~Base()\n";
    }
};

class Derived: public Base
{
private:
    int* m_array;

public:
    Derived(int length)
      : m_array{ new int[length] }
    {
    }

    ~Derived() // note: not virtual (your compiler may warn you about this)
    {
        std::cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

int main()
{
    Derived *derived { new Derived(5) };
    Base *base { derived };

    delete base;

    return 0;
}

/*
		output:
				Calling ~Base()

	注意：如果您编译上面的示例，您的编译器可能会警告您有关非虚拟析构函数（这是本示例的故意）。您可能需要禁用将警告视为错误的编译器标志才能继续。

	因为 base 是一个 Base 指针，所以当 base 被删除时，程序会查看 Base 析构函数是否是虚拟的。不是，所以它假设它只需要调用 Base 析构函数。我们可以从上面的示例打印的事实中看到这一点：
*/