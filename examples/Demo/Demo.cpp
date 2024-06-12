#include <iostream>

int main()
{
    std::cout << (true ? 1 : 2) << '\n';    // okay: both operands have matching type int

    std::cout << (false ? 1 : 2.2) << '\n'; // okay: int value 1 converted to double

    std::cout << (true ? "ewrtert" : 2u) << '\n';  // surprising result: -1 converted to unsigned int, result out of range

    return 0;
}