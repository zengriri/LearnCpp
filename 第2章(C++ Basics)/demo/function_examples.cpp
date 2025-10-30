#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

// 1. 基础函数示例
int add(int a, int b)
{
    return a + b;
}

// 2. 函数重载示例
void print(int value)
{
    std::cout << "Integer: " << value << std::endl;
}

void print(double value)
{
    std::cout << "Double: " << value << std::endl;
}

void print(const std::string &value)
{
    std::cout << "String: " << value << std::endl;
}

// 3. 默认参数示例
void createWindow(int width = 800, int height = 600, bool fullscreen = false)
{
    std::cout << "Creating window: " << width << "x" << height
              << (fullscreen ? " (fullscreen)" : " (windowed)") << std::endl;
}

// 4. 函数模板示例
template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

// 5. 非类型模板参数示例
template <int N>
void printNTimes(const std::string &message)
{
    for (int i = 0; i < N; ++i)
    {
        std::cout << message << " ";
    }
    std::cout << std::endl;
}

// 6. constexpr函数示例
constexpr int factorial(int n)
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// 7. lambda表达式和STL算法示例
void demonstrateLambdaWithSTL()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Original numbers: ";
    for (int n : numbers)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // 使用lambda查找偶数
    auto even_count = std::count_if(numbers.begin(), numbers.end(),
                                    [](int n)
                                    { return n % 2 == 0; });
    std::cout << "Even numbers count: " << even_count << std::endl;

    // 使用lambda变换
    std::transform(numbers.begin(), numbers.end(), numbers.begin(),
                   [](int n)
                   { return n * n; });

    std::cout << "Squared numbers: ";
    for (int n : numbers)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// 8. 函数指针示例
int multiply(int a, int b) { return a * b; }
int subtract(int a, int b) { return a - b; }

void demonstrateFunctionPointers()
{
    int (*operation)(int, int);

    operation = add;
    std::cout << "5 + 3 = " << operation(5, 3) << std::endl;

    operation = multiply;
    std::cout << "5 * 3 = " << operation(5, 3) << std::endl;

    operation = subtract;
    std::cout << "5 - 3 = " << operation(5, 3) << std::endl;
}

// 9. std::function示例
void demonstrateStdFunction()
{
    std::function<int(int, int)> func;

    // 存储普通函数
    func = add;
    std::cout << "Function: 7 + 8 = " << func(7, 8) << std::endl;

    // 存储lambda
    func = [](int a, int b)
    { return a * b; };
    std::cout << "Lambda: 7 * 8 = " << func(7, 8) << std::endl;
}

// 10. 递归函数示例
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 11. 高阶函数示例
template <typename Func>
auto applyTwice(Func f, int x)
{
    return f(f(x));
}

int main()
{
    std::cout << "=== C++ 函数示例演示 ===" << std::endl;

    // 1. 基础函数调用
    std::cout << "\n1. 基础函数:" << std::endl;
    std::cout << "add(5, 3) = " << add(5, 3) << std::endl;

    // 2. 函数重载
    std::cout << "\n2. 函数重载:" << std::endl;
    print(42);
    print(3.14);
    print("Hello World");

    // 3. 默认参数
    std::cout << "\n3. 默认参数:" << std::endl;
    createWindow();
    createWindow(1024);
    createWindow(1024, 768);
    createWindow(1920, 1080, true);

    // 4. 函数模板
    std::cout << "\n4. 函数模板:" << std::endl;
    std::cout << "maximum(10, 20) = " << maximum(10, 20) << std::endl;
    std::cout << "maximum(3.14, 2.71) = " << maximum(3.14, 2.71) << std::endl;
    std::cout << "maximum('a', 'z') = " << maximum('a', 'z') << std::endl;

    // 5. 非类型模板参数
    std::cout << "\n5. 非类型模板参数:" << std::endl;
    printNTimes<3>("Hello");
    printNTimes<5>("World");

    // 6. constexpr函数
    std::cout << "\n6. constexpr函数:" << std::endl;
    constexpr int fact5 = factorial(5);
    std::cout << "factorial(5) = " << fact5 << std::endl;

    // 7. lambda和STL算法
    std::cout << "\n7. Lambda表达式和STL算法:" << std::endl;
    demonstrateLambdaWithSTL();

    // 8. 函数指针
    std::cout << "\n8. 函数指针:" << std::endl;
    demonstrateFunctionPointers();

    // 9. std::function
    std::cout << "\n9. std::function:" << std::endl;
    demonstrateStdFunction();

    // 10. 递归函数
    std::cout << "\n10. 递归函数:" << std::endl;
    std::cout << "fibonacci(10) = " << fibonacci(10) << std::endl;

    // 11. 高阶函数
    std::cout << "\n11. 高阶函数:" << std::endl;
    auto double_func = [](int x)
    { return x * 2; };
    std::cout << "applyTwice(double_func, 5) = " << applyTwice(double_func, 5) << std::endl;

    return 0;
}
