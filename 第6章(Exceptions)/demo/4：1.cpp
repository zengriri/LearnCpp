#include <iostream>

class A
{
private:
	int m_x;
public:
	A(int x) : m_x{x}
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	B(int x) try : A{x} // note addition of try keyword here
	{
	}
	catch (...) // note this is at same level of indentation as the function itself
	{
                // Exceptions from member initializer list or constructor body are caught here

                std::cerr << "Exception caught\n";

                // If an exception isn't explicitly thrown here, the current exception will be implicitly rethrown
	}
};

int main()
{
	try
	{
		B b{0};
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}
}

/*
    让我们更详细地研究一下这个程序:
        *首先，注意在成员初始化列表之前添加了“try”关键字。这表明该点之后的所有内容（直到函数结束）都应考虑在 try 块内
        *其次，请注意关联的 catch 块与整个函数处于同一缩进级别。在 try 关键字和函数体结尾之间抛出的任何异常都可以在此处捕获
        *最后，与普通的 catch 块不同，它允许您解决异常、抛出新异常或重新抛出现有异常，
            使用函数级 try 块，您必须抛出或重新抛出异常
                如果你没有显式地抛出一个新的异常，或者重新抛出当前的异常（单独使用 throw 关键字），异常将被隐式地重新抛出堆栈。

    在上面的程序中，由于我们没有从函数级的catch块中显式地抛出异常，异常被隐式地重新抛出，并被main()中的catch块捕获
        这就是上面程序打印“Oops”的原因！

*/