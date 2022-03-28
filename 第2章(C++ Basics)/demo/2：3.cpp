#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
  constexpr std::array months{ // pre-C++17 use std::array<const char*, 12>
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };

  // Search for two consecutive months that start with the same letter.
  const auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
                                      [](const auto& a, const auto& b) {
                                        return (a[0] == b[0]);
                                      }) };

  // Make sure that two months were found.
  if (sameLetter != months.end())
  {
    // std::next returns the next iterator after sameLetter
    std::cout << *sameLetter << " and " << *std::next(sameLetter)
              << " start with the same letter\n";
  }

  return 0;
}

/*
  在上面的示例中，我们使用自动参数通过 const 引用来捕获我们的字符串。

  因为所有字符串类型都允许通过 operator[] 访问它们各自的字符，所以我们不需要关心用户是否传入了 std::string、C 风格的字符串或其他东西。
  这允许我们编写一个可以接受其中任何一个的 lambda，这意味着如果我们在几个月后更改类型，我们将不必重写 lambda。
*/