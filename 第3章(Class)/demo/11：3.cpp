#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
		std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice{ power } // this line is required to create Scanner objects, but ignored in this case
    {
		std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer: virtual public PoweredDevice // note: PoweredDevice is now a virtual base class
{
public:
    Printer(int printer, int power)
        : PoweredDevice{ power } // this line is required to create Printer objects, but ignored in this case
    {
		std::cout << "Printer: " << printer << '\n';
    }
};

class Copier: public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : PoweredDevice{ power }, // PoweredDevice is constructed here
        Scanner{ scanner, power }, Printer{ printer, power }
    {
    }
};

/*
    produces the result:
                PoweredDevice: 3
                Scanner: 1
                Printer: 2

    如果 Scanner 和 Printer 共享一个 PoweredDevice 基类，那么谁负责创建它？事实证明，答案是Copier。
        Copier 构造函数负责创建 PoweredDevice。因此，这是允许 Copier 直接调用非直接父构造函数的一次：

    如您所见，PoweredDevice 只被构造一次。

    如果我们不提及，我们将疏忽一些细节:
        *首先，虚拟基类总是在非虚拟基类之前创建，这确保了所有基类在其派生类之前创建。

        *其次，请注意 Scanner 和 Printer 构造函数仍然调用 PoweredDevice 构造函数。创建 Copier 的实例时，这些构造函数调用将被简单地忽略，因为 Copier 负责创建 PoweredDevice，而不是 Scanner 或 Printer。
            但是，如果我们要创建 Scanner 或 Printer 的实例，将使用这些构造函数调用，并应用正常的继承规则。

        *第三，如果一个类继承了一个或多个具有虚拟父类的类，则最派生的类负责构造虚拟基类。
            在这种情况下，Copier 继承了 Printer 和 Scanner，它们都有一个 PoweredDevice 虚拟基类。 Copier 是派生最多的类，负责创建 PoweredDevice。
            请注意，即使在单一继承的情况下也是如此：如果 Copier 单独继承自 Printer，并且 Printer 实际上继承自 PoweredDevice，Copier 仍负责创建 PoweredDevice。

        *第四，所有继承虚基类的类都会有一个虚表，即使它们通常不会有虚表，因此类的实例会比指针大。
*/