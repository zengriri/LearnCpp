#include<iostream>

class Display; // forward declaration for class Display

class Storage
{
private:
	int m_nValue {};
	double m_dValue {};
public:
	Storage(int nValue, double dValue)
		: m_nValue { nValue }, m_dValue { dValue }
	{
	}

	// Make the Display::displayItem member function a friend of the Storage class
	friend void Display::displayItem(const Storage& storage); // error: Storage hasn't seen the full definition of class Display
};

class Display
{
private:
	bool m_displayIntFirst {};

public:
	Display(bool displayIntFirst)
		: m_displayIntFirst { displayIntFirst }
	{
	}

	void displayItem(const Storage& storage)
	{
		if (m_displayIntFirst)
			std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
		else // display double first
			std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
	}
};

/*
    然而，事实证明这行不通。为了使成员函数成为友元，编译器必须查看友元成员函数类的完整定义（不仅仅是前向声明.
    由于类 Storage 还没有看到类 Display 的完整定义，所以编译器会在我们尝试使成员函数成为朋友时出错。

    幸运的是，这很容易解决，只需将类 Display 的定义移到 Storage 类的定义之前。 eg 2-5
*/