#include <cassert> // for assert()
#include <initializer_list> // for std::initializer_list
#include <iostream>

class IntArray
{
private:
	int m_length {};
	int* m_data {};

public:
	IntArray() = default;

	IntArray(int length)
		: m_length{ length }
		, m_data{ new int[length]{} }
	{

	}

	IntArray(std::initializer_list<int> list) // allow IntArray to be initialized via list initialization
		: IntArray(static_cast<int>(list.size())) // use delegating constructor to set up initial array
	{
		// Now initialize our array from the list
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	~IntArray()
	{
		delete[] m_data;
		// we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
	}

	IntArray(const IntArray&) = delete; // to avoid shallow copies
	IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const { return m_length; }
};

int main()
{
	IntArray array{ 5, 4, 3, 2, 1 }; // initializer list
	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	return 0;
}

/*
	在第 1 行：如上所述，我们必须使用尖括号来表示我们期望列表中的元素类型。在这种情况下，因为这是一个 IntArray，，我们希望列表被 int 填充。
	请注意，我们不会通过 const 引用传递列表。就像 std::string_view 一样，std::initializer_list 非常轻量级，并且副本往往比间接更便宜。

	在第 2 行：我们通过委托构造函数将 IntArray 的内存分配委托给另一个构造函数（以减少冗余代码）。这个其他构造函数需要知道数组的长度，所以我们将它传递给 list.size()，其中包含列表中元素的数量。
	请注意， list.size() 返回一个 size_t （无符号），因此我们需要在此处转换为带符号的 int。

	我们使用直接初始化，而不是大括号初始化，因为大括号初始化更喜欢列表构造函数。
	尽管构造函数会被正确解析，但如果我们不想使用列表构造函数，使用直接初始化来初始化具有列表构造函数的类会更安全。
*/