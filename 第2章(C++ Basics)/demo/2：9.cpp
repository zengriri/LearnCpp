#include <iostream>

int main()
{
  int i{0};

  // Create a new lambda named count
  auto count{[i]() mutable
             {
               std::cout << ++i << '\n';
             }};

  count(); // invoke count

  auto otherCount{count}; // create a copy of count

  // invoke both count and the copy
  count();
  otherCount();

  return 0;
}

/*
  代码不是打印 1、2、3，而是打印 2 两次。当我们创建 otherCount 作为 count 的副本时，我们创建了当前状态的 count 副本
  count 的 i 是 1，所以 otherCount 的 i 也是 1。由于 otherCount 是 count 的副本，因此它们每个都有自己的 i。
*/