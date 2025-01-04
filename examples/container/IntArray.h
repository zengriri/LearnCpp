#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>
#include <algorithm>
#include <initializer_list>

class IntArray
{
private:
	int m_length{};
	int* m_data{};

public:
	IntArray() = default;

	IntArray(int lenght) :m_length{ lenght }, m_data{ new int[static_cast<std::size_t>(lenght)] {} }
	{
		assert(lenght >= 0);

		if (lenght >= 0)
			m_data = new int[lenght];
	}

	IntArray(std::initializer_list<int> list) :IntArray(static_cast<int>(list.size()))
	{
		std::copy(list.begin(), list.end(), m_data);
	}

	~IntArray()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const { return m_length; }

	void reallocate(int newLength)
	{
		erase();

		if (newLength <= 0) return;

		m_data = new int[newLength];
		m_length = newLength;
	}

	void resize(int newLength)
	{
		if (m_length == newLength) return;

		if (newLength <= 0)
		{
			erase();
			return;
		}

		int* data{ new int[newLength] };
		if (m_length > 0) {
			int elementToCopy{ newLength > m_length ? m_length : newLength };
			std::copy_n(m_data, elementToCopy, data);
		}
		delete[] m_data;
		m_data = data;
		m_length = newLength;
	}

	IntArray(const IntArray& a) :IntArray(a.getLength())
	{
		std::copy_n(a.m_data, m_length, m_data);
	}

	IntArray& operator=(const IntArray& a)
	{
		if (&a == this) return *this;

		reallocate(a.getLength());
		std::copy_n(a.m_data, m_length, m_data);
	}

	void insertBefore(int value, int index)
	{
		assert(index >= 0 && index <= m_length);
		int* data{ new int[m_length + 1] };
		std::copy_n(m_data, index, data);
		data[index] = value;
		std::copy_n(m_data + index, m_length - index, data + index + 1);
		delete[] m_data;
		m_data = data;
		++m_length;
	}

	void remove(int index)
	{
		// Sanity check our index value
		assert(index >= 0 && index < m_length);

		// If this is the last remaining element in the array, set the array to empty and bail out
		if (m_length == 1)
		{
			erase();
			return;
		}

		// First create a new array one element smaller than the old array
		int* data{ new int[m_length - 1] };

		// Copy all of the elements up to the index
		std::copy_n(m_data, index, data);

		// Copy all of the values after the removed element
		std::copy_n(m_data + index + 1, m_length - index - 1, data + index);

		// Finally, delete the old array, and use the new array instead
		delete[] m_data;
		m_data = data;
		--m_length;
	}
};

#endif // !INTARRAY_H
