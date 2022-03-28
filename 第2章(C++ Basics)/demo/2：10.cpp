#include <iostream>
#include <functional>

void invoke(const std::function<void()>& fn)
{
    fn();
}

int main()
{
    int i{ 0 };

    // Increments and prints its local copy of @i.
    auto count{ [i]() mutable {
      std::cout << ++i << '\n';
    } };

    invoke(count);
    invoke(count);
    invoke(count);

    return 0;
}

/*
  Output:
      1
      1
      1

  这以更晦涩的形式展示了与先前示例相同的问题。

  当使用 lambda 创建 std::function 时，std::function 在内部制作 lambda 对象的副本。因此，我们对 fn() 的调用实际上是在 lambda 的副本上执行的，而不是实际的 lambda

  如果我们需要传递一个可变的 lambda，并且想要避免无意中复制的可能性，有两种选择
    *一种选择是改用非捕获 lambda
    *防止我们的 lambda 副本被复制。
      幸运的是，C++ 提供了一种方便的类型（作为 <functional> 标头的一部分），称为 std::reference_wrapper，它允许我们像传递引用一样传递普通类型。
      通过将我们的 lambda 包装在 std::reference_wrapper 中，每当有人试图复制我们的 lambda 时，他们都会复制引用，这将复制引用而不是实际对象。

      eg:2-11

*/