#include <iostream>
#include <functional>

void invoke(const std::function<void()> &fn)
{
  fn();
}

int main()
{
  int i{0};

  // Increments and prints its local copy of @i.
  auto count{[i]() mutable
             {
               std::cout << ++i << '\n';
             }};

  // std::ref(count) ensures count is treated like a reference
  // thus, anything that tries to copy count will actually copy the reference
  // ensuring that only one count exists
  invoke(std::ref(count));
  invoke(std::ref(count));
  invoke(std::ref(count));

  return 0;
}

/*
  标准库函数可以复制函数对象（提醒：lambda 是函数对象）。如果您想为 lambdas 提供可变捕获变量，请使用 std::ref 通过引用传递它们
*/