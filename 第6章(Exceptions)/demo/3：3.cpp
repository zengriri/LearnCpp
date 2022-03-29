#include <cstddef> // for std::size_t
#include <iostream>
#include <exception> // for std::exception
#include <limits>
#include <string> // for this example

int main()
{
    try
    {
        // Your code using standard library goes here
        // We'll trigger one of these exceptions intentionally for the sake of the example
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max()); // will trigger a std::length_error or allocation exception
    }
    // This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception& exception)
    {
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }

    return 0;
}

/*
    上面的例子应该很简单.值得注意的一件事是 std::exception 有一个名为 what() 的虚成员函数，它返回异常的 C 风格字符串描述。
    
    大多数派生类会覆盖 what() 函数来更改消息。请注意，此字符串仅用于描述性文本 - 不要将其用于比较，因为不保证在编译器中相同。
*/