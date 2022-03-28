class Accumulator
{
private:
    int m_value { 0 };

public:
    void add(int value) { m_value += value; }

    // Make the reset() function a friend of this class
    friend void reset(Accumulator& accumulator);
};

// reset() is now a friend of the Accumulator class
void reset(Accumulator& accumulator)
{
    // And can access the private data of Accumulator objects
    accumulator.m_value = 0;
}

int main()
{
    Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    reset(acc); // reset the accumulator to 0

    return 0;
}

//*因为 Accumulator 已明确将此 reset() 函数声明为该类的友元，所以 reset() 函数可以访问 Accumulator 的私有成员。
//*请注意，我们必须将 Accumulator 对象传递给 reset()。这是因为 reset() 不是成员函数。它没有 *this 指针，也没有可供使用的 Accumulator 对象，除非给定一个