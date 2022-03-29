#include <iostream>

template<class T>
class Auto_ptr4
{
	T* m_ptr;
public:
	Auto_ptr4(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}

	~Auto_ptr4()
	{
		delete m_ptr;
	}

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4(const Auto_ptr4& a)
	{
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4(Auto_ptr4&& a) noexcept
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr; // we'll talk more about this line below
	}

	// Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& a)
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

	// Move assignment
	// Transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete m_ptr;

		// Transfer ownership of a.m_ptr to m_ptr
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr; // we'll talk more about this line below

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

Auto_ptr4<Resource> generateResource()
{
	Auto_ptr4<Resource> res(new Resource);
	return res; // this return value will invoke the move constructor
}

int main()
{
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment

	return 0;
}

/*
	output:
		Resource acquired
		Resource destroyed

	让我们仔细看看。此程序中有 6 个关键步骤:
		1:在 generateResource() 内部，局部变量 res 被创建并使用动态分配的资源进行初始化，这导致了第一个“资源获取”。
		2:Res 按值返回给 main()。 res被move构造成一个临时对象，将res中存储的动态创建的对象传递给临时对象。我们将在下面讨论为什么会发生这种情况。
		3:Res超出范围。因为 res 不再管理指针（它被移动到临时的），所以这里没有任何有趣的事情发生。
		4:临时对象被移动分配给 mainres。这会将存储在临时文件中的动态创建的对象传输到 mainres。
		5:赋值表达式结束，临时对象超出表达式范围并被销毁。但是，由于临时不再管理指针（它已移至 mainres），因此这里也没有任何有趣的事情发生。
		6:在 main() 结束时，mainres 超出范围，并显示我们最终的“资源已销毁”。
	
*/