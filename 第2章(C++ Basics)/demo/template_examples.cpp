#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <concepts>
#include <array>

// 模板函数示例演示

// 1. 基础函数模板
template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

// 2. 多参数模板函数
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b)
{
    return a + b;
}

// 3. 非类型模板参数
template <typename T, size_t N>
void printArray(const std::array<T, N> &arr)
{
    std::cout << "Array of " << N << " elements: ";
    for (const auto &element : arr)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// 4. 可变参数模板
template <typename... Args>
void print(Args... args)
{
    // C++17 折叠表达式
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

// 5. 递归可变参数模板 (C++11/14 风格)
template <typename T>
void printRecursive(T &&t)
{
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void printRecursive(T &&t, Args &&...args)
{
    std::cout << t << " ";
    printRecursive(args...);
}

// 6. 模板特化示例
template <typename T>
void processValue(T value)
{
    std::cout << "Generic processing: " << value << std::endl;
}

// 全特化
template <>
void processValue<std::string>(std::string value)
{
    std::cout << "String processing: \"" << value << "\"" << std::endl;
}

template <>
void processValue<bool>(bool value)
{
    std::cout << "Boolean processing: " << (value ? "true" : "false") << std::endl;
}

// 7. SFINAE 示例 (Substitution Failure Is Not An Error)
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
processNumber(T value)
{
    std::cout << "Processing integer: " << value << std::endl;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
processNumber(T value)
{
    std::cout << "Processing floating point: " << value << std::endl;
}

// 8. constexpr 模板函数
template <int N>
constexpr int factorial()
{
    if constexpr (N <= 1)
    {
        return 1;
    }
    else
    {
        return N * factorial<N - 1>();
    }
}

// 9. 完美转发模板
template <typename Func, typename... Args>
auto callFunction(Func &&func, Args &&...args)
    -> decltype(func(std::forward<Args>(args)...))
{
    std::cout << "Calling function with perfect forwarding" << std::endl;
    return func(std::forward<Args>(args)...);
}

// 10. 类型萃取示例
template <typename T>
void analyzeType(T value)
{
    std::cout << "Analyzing type of: " << value << std::endl;
    std::cout << "  Is integral: " << std::is_integral<T>::value << std::endl;
    std::cout << "  Is floating point: " << std::is_floating_point<T>::value << std::endl;
    std::cout << "  Is pointer: " << std::is_pointer<T>::value << std::endl;
    std::cout << "  Size: " << sizeof(T) << " bytes" << std::endl;
}

// 11. C++20 概念示例
#if __cplusplus >= 202002L
template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <typename T>
concept Addable = requires(T a, T b) {
    a + b;
};

template <Numeric T>
T multiply(T a, T b)
{
    return a * b;
}

template <typename T>
    requires Addable<T>
T addValues(T a, T b)
{
    return a + b;
}
#endif

// 12. 函数模板重载
template <typename T>
void process(T value)
{
    std::cout << "Single value: " << value << std::endl;
}

template <typename T>
void process(const std::vector<T> &values)
{
    std::cout << "Vector of values: ";
    for (const auto &v : values)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

// 13. 模板参数推导指引示例
template <typename T>
class Wrapper
{
public:
    T value;
    Wrapper(T v) : value(v) {}

    template <typename U>
    auto combine(const Wrapper<U> &other)
    {
        return Wrapper(value + other.value);
    }
};

// 14. 通用Lambda和auto模板参数 (C++20)
#if __cplusplus >= 202002L
auto genericFunction(auto a, auto b)
{
    return a + b;
}
#endif

// 15. 编译时字符串处理
template <size_t N>
constexpr size_t stringLength(const char (&str)[N])
{
    return N - 1; // 减去空终止符
}

// 示例函数
void basicTemplateExamples()
{
    std::cout << "=== 基础模板函数示例 ===" << std::endl;

    std::cout << "maximum(10, 20) = " << maximum(10, 20) << std::endl;
    std::cout << "maximum(3.14, 2.71) = " << maximum(3.14, 2.71) << std::endl;
    std::cout << "maximum('a', 'z') = " << maximum('a', 'z') << std::endl;

    std::cout << "add(5, 3.14) = " << add(5, 3.14) << std::endl;
    std::cout << "add(string, string) = " << add(std::string("Hello "), std::string("World")) << std::endl;
}

void nonTypeTemplateExamples()
{
    std::cout << "\n=== 非类型模板参数示例 ===" << std::endl;

    std::array<int, 5> intArray = {1, 2, 3, 4, 5};
    std::array<std::string, 3> stringArray = {"Hello", "World", "Template"};

    printArray(intArray);
    printArray(stringArray);

    constexpr int fact5 = factorial<5>();
    constexpr int fact10 = factorial<10>();
    std::cout << "factorial<5>() = " << fact5 << std::endl;
    std::cout << "factorial<10>() = " << fact10 << std::endl;

    constexpr size_t len = stringLength("Hello World");
    std::cout << "String length: " << len << std::endl;
}

void variadicTemplateExamples()
{
    std::cout << "\n=== 可变参数模板示例 ===" << std::endl;

    print(1, 2.5, "hello", 'x');
    print("Only", "strings");
    print(42);

    std::cout << "Recursive variadic:" << std::endl;
    printRecursive(1, 2.5, "hello", 'x', true);
}

void specializationExamples()
{
    std::cout << "\n=== 模板特化示例 ===" << std::endl;

    processValue(42);
    processValue(3.14);
    processValue(std::string("Hello"));
    processValue(true);

    std::cout << "\nSFINAE examples:" << std::endl;
    processNumber(42);
    processNumber(3.14);
    // processNumber("string"); // 编译错误，没有匹配的重载
}

void typeAnalysisExamples()
{
    std::cout << "\n=== 类型分析示例 ===" << std::endl;

    analyzeType(42);
    analyzeType(3.14);
    analyzeType("hello");

    int x = 10;
    analyzeType(&x);
}

void perfectForwardingExample()
{
    std::cout << "\n=== 完美转发示例 ===" << std::endl;

    auto testFunc = [](int &x)
    {
        x++;
        return x;
    };

    int value = 10;
    auto result = callFunction(testFunc, value);
    std::cout << "Result: " << result << ", Original value: " << value << std::endl;
}

void overloadingExamples()
{
    std::cout << "\n=== 模板重载示例 ===" << std::endl;

    process(42);
    process(std::vector<int>{1, 2, 3, 4, 5});
    process(std::vector<std::string>{"Hello", "World", "Templates"});
}

#if __cplusplus >= 202002L
void conceptsExamples()
{
    std::cout << "\n=== C++20 概念示例 ===" << std::endl;

    std::cout << "multiply(5, 6) = " << multiply(5, 6) << std::endl;
    std::cout << "multiply(2.5, 4.0) = " << multiply(2.5, 4.0) << std::endl;

    std::cout << "addValues(10, 20) = " << addValues(10, 20) << std::endl;
    std::cout << "addValues strings = " << addValues(std::string("Hello "), std::string("Concepts")) << std::endl;

    std::cout << "genericFunction(5, 7) = " << genericFunction(5, 7) << std::endl;
    std::cout << "genericFunction(1.5, 2.5) = " << genericFunction(1.5, 2.5) << std::endl;
}
#endif

void advancedTemplateExamples()
{
    std::cout << "\n=== 高级模板示例 ===" << std::endl;

    Wrapper<int> w1(10);
    Wrapper<double> w2(3.14);

    auto combined = w1.combine(w2);
    std::cout << "Combined wrapper value: " << combined.value << std::endl;

    // 模板参数推导
    Wrapper w3(42); // C++17 类模板参数推导
    std::cout << "Deduced wrapper value: " << w3.value << std::endl;
}

int main()
{
    basicTemplateExamples();
    nonTypeTemplateExamples();
    variadicTemplateExamples();
    specializationExamples();
    typeAnalysisExamples();
    perfectForwardingExample();
    overloadingExamples();

#if __cplusplus >= 202002L
    conceptsExamples();
#else
    std::cout << "\n=== C++20 概念示例 ===" << std::endl;
    std::cout << "需要 C++20 或更高版本才能运行概念示例" << std::endl;
#endif

    advancedTemplateExamples();

    return 0;
}
