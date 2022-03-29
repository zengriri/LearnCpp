#include<iostream>

template<class T>
class Auto_ptr3
{
	T* m_ptr;
public:
	Auto_ptr3(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr3()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3(const Auto_ptr3& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr3& operator=(const Auto_ptr3& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Copy the resource
		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr3<Resource> generateResource()
{
	Auto_ptr3<Resource> res(new Resource);
	return res; // this return value will invoke the copy constructor
}

int main()
{
	Auto_ptr3<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the copy assignment

	return 0;
}

/*
		output:
			Resource acquired
			Resource acquired
			Resource destroyed
			Resource acquired
			Resource destroyed
			Resource destroyed

		让我们仔细看看。此程序中有 6 个关键步骤:
			1:在 generateResource() 内部，局部变量 res 被创建并使用动态分配的资源进行初始化，这导致了第一个“资源获取”。

			2:res 按值返回给 main()。我们这里按值返回，因为 res 是一个局部变量。它不能通过地址或引用返回，因为 res 将在 generateResource() 结束时被销毁。所以 res 是复制构造成一个临时对象。
				由于我们的复制构造函数进行了深度复制，因此在这里分配了一个新的资源，这导致了第二个“资源获取”。

			3：Res 超出范围，破坏了最初创建的 Resource，这导致了第一个“Resourcedestroyed”。

			4：临时对象通过复制分配分配给 mainres。由于我们的复制分配也进行了深度复制，因此分配了一个新资源，从而导致另一个“资源获取”

			5：赋值表达式结束，临时对象超出表达式范围并被销毁，导致“资源被销毁”

			6：在 main() 结束时，mainres 超出范围，并显示我们最终的“资源已销毁”。

*/