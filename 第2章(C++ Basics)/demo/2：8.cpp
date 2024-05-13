#include <array>
#include <iostream>
#include <algorithm>

int main()
{
  std::array areas{100, 25, 121, 40, 56};

  int width{};
  int height{};

  std::cout << "Enter width and height: ";
  std::cin >> width >> height;

  // We store areas, but the user entered width and height.
  // We need to calculate the area before we can search for it.
  auto found{std::find_if(areas.begin(), areas.end(),
                          // Declare a new variable that's visible only to the lambda.
                          // The type of userArea is automatically deduced to int.
                          [userArea{width * height}](int knownArea)
                          {
                            return (userArea == knownArea);
                          })};

  if (found == areas.end())
  {
    std::cout << "I don't know this area :(\n";
  }
  else
  {
    std::cout << "Area found :)\n";
  }

  return 0;
}

/*
  userArea 只会在定义 lambda 时计算一次。.计算出的面积存储在 lambda 对象中，每次调用都相同。
  如果 lambda 是可变的并修改了在捕获中定义的变量，则原始值将被覆盖。
*/