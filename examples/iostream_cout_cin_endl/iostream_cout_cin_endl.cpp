#include <iostream> // for std::cout and std::endl
#include <cstdlib>

int main()
{
    /**
    eg1:将文本输出到控制台时，优先使用 \n 而不是 std::endl。
        使用 std::endl 通常效率很低，因为它实际上执行两项工作：输出换行符（将光标移动到控制台的下一行），并刷新缓冲区（速度很慢）
        我们会得到多次刷新，这很慢而且可能是不必要的。
        当将文本输出到控制台时，我们通常不需要自己显式刷新缓冲区。 C++ 的输出系统被设计为定期自刷新，让它自行刷新既简单又高效
    */

    //std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line
    //std::cout << "My name is Alex." << std::endl;

    //int x{ 5 };
    //std::cout << "x is equal to: " << x << '\n'; // single quoted (by itself) (conventional)
    //std::cout << "Yep." << "\n";                 // double quoted (by itself) (unconventional but okay)
    //std::cout << "And that's all, folks!\n";     // between double quotes in existing text (conventional)

    //eg2
    std::cout << "Enter two numbers separated by a space: ";

    int x{}; // define variable x to hold user input (and value-initialize it)
    int y{}; // define variable y to hold user input (and value-initialize it)
    std::cin >> x >> y; // get two numbers and store in variable x and y respectively

    std::cout << "You entered " << x << " and " << y << '\n';

    return EXIT_SUCCESS;
}