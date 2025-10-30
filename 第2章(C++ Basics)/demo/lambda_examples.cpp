#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>

// Lambda表达式示例演示

void basicLambdaExamples()
{
    std::cout << "=== 基础Lambda示例 ===" << std::endl;

    // 1. 最简单的lambda
    auto simple = []()
    { std::cout << "Hello Lambda!" << std::endl; };
    simple();

    // 2. 带参数的lambda
    auto add = [](int a, int b)
    { return a + b; };
    std::cout << "add(5, 3) = " << add(5, 3) << std::endl;

    // 3. 明确指定返回类型
    auto divide = [](double a, double b) -> double
    {
        return b != 0 ? a / b : 0.0;
    };
    std::cout << "divide(10.0, 3.0) = " << divide(10.0, 3.0) << std::endl;

    // 4. 立即调用的lambda (IIFE)
    int result = [](int x)
    { return x * x; }(7);
    std::cout << "Square of 7 = " << result << std::endl;
}

void captureExamples()
{
    std::cout << "\n=== Lambda捕获示例 ===" << std::endl;

    int x = 10, y = 20;

    // 1. 按值捕获
    auto capture_by_value = [x, y]()
    {
        std::cout << "Captured by value: x=" << x << ", y=" << y << std::endl;
        // x++; // 错误：不能修改按值捕获的变量
    };
    capture_by_value();

    // 2. 按引用捕获
    auto capture_by_reference = [&x, &y]()
    {
        x++;
        y++;
        std::cout << "Captured by reference: x=" << x << ", y=" << y << std::endl;
    };
    capture_by_reference();
    std::cout << "After lambda: x=" << x << ", y=" << y << std::endl;

    // 3. 混合捕获
    int z = 30;
    auto mixed_capture = [x, &z](int param)
    {
        // x值被复制，z通过引用访问
        z += param;
        std::cout << "x=" << x << ", z=" << z << ", param=" << param << std::endl;
    };
    mixed_capture(5);
    std::cout << "After mixed capture: z=" << z << std::endl;

    // 4. 默认捕获
    auto default_capture_value = [=]()
    {
        std::cout << "Default capture by value: x=" << x << ", y=" << y << ", z=" << z << std::endl;
    };
    default_capture_value();

    auto default_capture_ref = [&]()
    {
        x += 10;
        y += 10;
        std::cout << "Default capture by reference: x=" << x << ", y=" << y << std::endl;
    };
    default_capture_ref();
}

void mutableLambdaExamples()
{
    std::cout << "\n=== 可变Lambda示例 ===" << std::endl;

    int counter = 0;

    // mutable lambda允许修改按值捕获的变量
    auto mutable_lambda = [counter](int increment) mutable
    {
        counter += increment;
        std::cout << "Inside lambda: counter = " << counter << std::endl;
        return counter;
    };

    int result1 = mutable_lambda(5);
    int result2 = mutable_lambda(3); // counter在lambda内部保持状态

    std::cout << "Original counter: " << counter << std::endl;
    std::cout << "Results: " << result1 << ", " << result2 << std::endl;
}

void genericLambdaExamples()
{
    std::cout << "\n=== 泛型Lambda示例 (C++14) ===" << std::endl;

    // 泛型lambda可以接受任何类型的参数
    auto generic_add = [](auto a, auto b)
    {
        return a + b;
    };

    std::cout << "generic_add(5, 3) = " << generic_add(5, 3) << std::endl;
    std::cout << "generic_add(2.5, 1.5) = " << generic_add(2.5, 1.5) << std::endl;
    std::cout << "generic_add(string) = " << generic_add(std::string("Hello "), std::string("World")) << std::endl;

    // 变参模板lambda
    auto sum_all = [](auto... args)
    {
        return (args + ...); // C++17折叠表达式
    };

    std::cout << "sum_all(1, 2, 3, 4, 5) = " << sum_all(1, 2, 3, 4, 5) << std::endl;
}

void stlAlgorithmExamples()
{
    std::cout << "\n=== Lambda与STL算法示例 ===" << std::endl;

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Original: ";
    for (int n : numbers)
        std::cout << n << " ";
    std::cout << std::endl;

    // 1. std::for_each
    std::cout << "Doubled: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n)
                  { std::cout << n * 2 << " "; });
    std::cout << std::endl;

    // 2. std::count_if
    auto even_count = std::count_if(numbers.begin(), numbers.end(),
                                    [](int n)
                                    { return n % 2 == 0; });
    std::cout << "Even numbers: " << even_count << std::endl;

    // 3. std::find_if
    auto it = std::find_if(numbers.begin(), numbers.end(),
                           [](int n)
                           { return n > 7; });
    if (it != numbers.end())
    {
        std::cout << "First number > 7: " << *it << std::endl;
    }

    // 4. std::transform
    std::vector<int> squares;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squares),
                   [](int n)
                   { return n * n; });

    std::cout << "Squares: ";
    for (int n : squares)
        std::cout << n << " ";
    std::cout << std::endl;

    // 5. std::sort
    std::vector<int> sortable = {5, 2, 8, 1, 9, 3};
    std::sort(sortable.begin(), sortable.end(),
              [](int a, int b)
              { return a > b; }); // 降序

    std::cout << "Sorted (desc): ";
    for (int n : sortable)
        std::cout << n << " ";
    std::cout << std::endl;

    // 6. std::accumulate
    auto sum = std::accumulate(numbers.begin(), numbers.end(), 0,
                               [](int acc, int n)
                               { return acc + n; });
    std::cout << "Sum: " << sum << std::endl;
}

void recursiveLambdaExamples()
{
    std::cout << "\n=== 递归Lambda示例 ===" << std::endl;

    // 使用std::function实现递归lambda
    std::function<int(int)> factorial = [&factorial](int n) -> int
    {
        return n <= 1 ? 1 : n * factorial(n - 1);
    };

    std::cout << "factorial(5) = " << factorial(5) << std::endl;

    // 另一种递归lambda的实现方式
    auto make_factorial = [](auto &self, int n) -> int
    {
        return n <= 1 ? 1 : n * self(self, n - 1);
    };

    auto fib = [](auto &self, int n) -> int
    {
        return n <= 1 ? n : self(self, n - 1) + self(self, n - 2);
    };

    std::cout << "make_factorial(6) = " << make_factorial(make_factorial, 6) << std::endl;
    std::cout << "fibonacci(10) = " << fib(fib, 10) << std::endl;
}

void advancedLambdaExamples()
{
    std::cout << "\n=== 高级Lambda示例 ===" << std::endl;

    // 1. Lambda作为类成员
    class Calculator
    {
    public:
        Calculator(int initial) : value(initial) {}

        auto getMultiplier()
        {
            return [this](int factor)
            { return value * factor; };
        }

        auto getAdder()
        {
            return [=](int addend) mutable
            { return value + addend; };
        }

    private:
        int value;
    };

    Calculator calc(10);
    auto multiplier = calc.getMultiplier();
    auto adder = calc.getAdder();

    std::cout << "multiplier(5) = " << multiplier(5) << std::endl;
    std::cout << "adder(3) = " << adder(3) << std::endl;

    // 2. 完美转发lambda
    auto perfect_forward = [](auto &&func, auto &&...args)
    {
        return func(std::forward<decltype(args)>(args)...);
    };

    auto test_func = [](int &x)
    { return ++x; };
    int x = 10;
    std::cout << "perfect_forward result: " << perfect_forward(test_func, x) << std::endl;
    std::cout << "x after perfect_forward: " << x << std::endl;

    // 3. 条件编译lambda
    auto conditional = [](auto value)
    {
        if constexpr (std::is_integral_v<decltype(value)>)
        {
            return value * 2;
        }
        else
        {
            return value + 1.0;
        }
    };

    std::cout << "conditional(5) = " << conditional(5) << std::endl;
    std::cout << "conditional(3.14) = " << conditional(3.14) << std::endl;
}

void lambdaPerformanceExample()
{
    std::cout << "\n=== Lambda性能考虑 ===" << std::endl;

    const int SIZE = 1000000;
    std::vector<int> data(SIZE);
    std::iota(data.begin(), data.end(), 1);

    // 无捕获的lambda可以转换为函数指针
    auto no_capture = [](int x)
    { return x * 2; };

    // 有捕获的lambda生成函数对象
    int multiplier = 3;
    auto with_capture = [multiplier](int x)
    { return x * multiplier; };

    std::cout << "两种lambda都可以正常工作，但性能特征可能不同" << std::endl;
    std::cout << "无捕获lambda可以转换为函数指针" << std::endl;
    std::cout << "有捕获lambda生成函数对象，可能有轻微开销" << std::endl;
}

int main()
{
    basicLambdaExamples();
    captureExamples();
    mutableLambdaExamples();
    genericLambdaExamples();
    stlAlgorithmExamples();
    recursiveLambdaExamples();
    advancedLambdaExamples();
    lambdaPerformanceExample();

    return 0;
}
