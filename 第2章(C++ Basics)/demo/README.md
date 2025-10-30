# C++ 函数学习示例

这个目录包含了C++函数相关的各种示例代码，配合 `2：函数.txt` 学习文档使用。

## 文件说明

### 示例代码
- `function_examples.cpp` - 基础函数示例，包括：
  - 基本函数定义和调用
  - 函数重载
  - 默认参数
  - 函数模板基础
  - 函数指针和std::function
  - 递归函数
  - 高阶函数

- `lambda_examples.cpp` - Lambda表达式详细示例，包括：
  - 基础Lambda语法
  - 捕获机制（按值、按引用、混合捕获）
  - 可变Lambda
  - 泛型Lambda
  - Lambda与STL算法的结合
  - 递归Lambda
  - 高级Lambda特性

- `template_examples.cpp` - 模板函数深入示例，包括：
  - 基础函数模板
  - 非类型模板参数
  - 可变参数模板
  - 模板特化
  - SFINAE技术
  - 完美转发
  - C++20概念
  - 高级模板技巧

### 编译和运行

#### 使用Makefile（推荐）
```bash
# 编译所有示例
make all

# 运行所有示例
make run-all

# 编译并运行单个示例
make function_examples
./function_examples

# 清理编译产物
make clean

# 查看帮助
make help
```

#### 手动编译
```bash
# 编译基础函数示例
g++ -std=c++20 -Wall -Wextra -O2 -o function_examples function_examples.cpp

# 编译Lambda示例
g++ -std=c++20 -Wall -Wextra -O2 -o lambda_examples lambda_examples.cpp

# 编译模板示例
g++ -std=c++20 -Wall -Wextra -O2 -o template_examples template_examples.cpp
```

#### Windows编译
```cmd
# 使用MSVC
cl /EHsc /std:c++20 function_examples.cpp
cl /EHsc /std:c++20 lambda_examples.cpp
cl /EHsc /std:c++20 template_examples.cpp

# 使用MinGW
g++ -std=c++20 -Wall -Wextra -O2 -o function_examples.exe function_examples.cpp
g++ -std=c++20 -Wall -Wextra -O2 -o lambda_examples.exe lambda_examples.cpp
g++ -std=c++20 -Wall -Wextra -O2 -o template_examples.exe template_examples.cpp
```

## 学习建议

### 初学者路径
1. 先阅读 `2：函数.txt` 中的基础概念
2. 运行 `function_examples` 了解基本函数使用
3. 学习 `lambda_examples` 掌握现代C++的Lambda表达式
4. 最后深入 `template_examples` 学习模板编程

### 每个示例的重点

#### function_examples.cpp
- 理解函数的基本概念和语法
- 掌握函数重载的规则
- 学会使用默认参数
- 了解函数指针和std::function的区别
- 理解递归函数的实现

#### lambda_examples.cpp
- 掌握Lambda表达式的各种语法形式
- 理解捕获机制的不同方式
- 学会在STL算法中使用Lambda
- 了解Lambda的性能特点
- 掌握高级Lambda技巧

#### template_examples.cpp
- 理解模板的工作原理
- 掌握模板特化和SFINAE
- 学会使用可变参数模板
- 了解C++20的概念机制
- 掌握现代C++的模板技巧

## 编译要求

- C++20兼容的编译器（GCC 10+, Clang 10+, MSVC 2019+）
- 部分C++20特性示例在旧编译器上可能无法编译，但会有条件编译保护

## 扩展练习

1. 修改现有示例，添加自己的功能
2. 尝试将Lambda表达式改写为函数对象
3. 实现自己的模板函数库
4. 使用C++20概念约束模板参数
5. 性能测试：比较不同实现方式的性能差异

## 相关资源

- [C++ Reference](https://en.cppreference.com/)
- [ISO C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [Modern C++ Features](https://github.com/AnthonyCalandra/modern-cpp-features)

## 注意事项

- 示例代码注重教学清晰性，实际项目中可能需要更多的错误处理
- 某些高级特性需要较新的编译器支持
- 建议结合调试器逐步执行代码，观察程序行为
