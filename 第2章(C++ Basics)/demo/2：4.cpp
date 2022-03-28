#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
  // Print a value and count how many times @print has been called.
  auto print{
    [](auto value) {
      static int callCount{ 0 };
      std::cout << callCount++ << ": " << value << '\n';
    }
  };

  print("hello"); // 0: hello
  print("world"); // 1: world

  print(1); // 0: 1
  print(2); // 1: 2

  print("ding dong"); // 2: ding dong

  return 0;
}

/*
  
  *在上面的示例中，我们定义了一个 lambda，然后使用两个不同的参数（一个字符串字面量参数和一个整数参数）调用它。这会生成两个不同版本的 lambda（一个带有字符串文字参数，一个带有整数参数）。
 
  *大多数时候，这是无关紧要的。但是，请注意，如果通用 lambda 使用静态持续时间变量，则这些变量不会在生成的 lambda 之间共享。
  
*/