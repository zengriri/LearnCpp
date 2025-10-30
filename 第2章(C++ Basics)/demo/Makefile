# Makefile for C++ Function Examples

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

# 目标文件
TARGETS = function_examples lambda_examples template_examples

# 默认目标
all: $(TARGETS)

# 编译规则
function_examples: function_examples.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

lambda_examples: lambda_examples.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

template_examples: template_examples.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# 运行所有示例
run-all: $(TARGETS)
	@echo "=== Running Function Examples ==="
	./function_examples
	@echo ""
	@echo "=== Running Lambda Examples ==="
	./lambda_examples
	@echo ""
	@echo "=== Running Template Examples ==="
	./template_examples

# 清理
clean:
	rm -f $(TARGETS) *.exe

# 只编译，不优化（用于调试）
debug: CXXFLAGS = -std=c++20 -Wall -Wextra -g -O0
debug: $(TARGETS)

# 帮助
help:
	@echo "Available targets:"
	@echo "  all        - 编译所有示例"
	@echo "  run-all    - 运行所有示例"
	@echo "  clean      - 清理编译产物"
	@echo "  debug      - 编译调试版本"
	@echo "  help       - 显示帮助信息"
	@echo ""
	@echo "Individual targets:"
	@echo "  function_examples  - 基础函数示例"
	@echo "  lambda_examples    - Lambda表达式示例"
	@echo "  template_examples  - 模板函数示例"

.PHONY: all run-all clean debug help
