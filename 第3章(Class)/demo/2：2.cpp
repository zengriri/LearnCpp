#include <iostream>

class Humidity;

class Temperature
{
private:
    int m_temp {};

public:
    Temperature(int temp=0)
        : m_temp { temp }
    {
    }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

class Humidity
{
private:
    int m_humidity {};

public:
    Humidity(int humidity=0)
        : m_humidity { humidity }
    {
    }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

void printWeather(const Temperature& temperature, const Humidity& humidity)
{
    std::cout << "The temperature is " << temperature.m_temp <<
       " and the humidity is " << humidity.m_humidity << '\n';
}

int main()
{
    Humidity hum(10);
    Temperature temp(12);

    printWeather(temp, hum);

    return 0;
}

/*
    请注意示例顶部的以下行：
        class Humidity;

    这是一个类原型，它告诉编译器我们将来要定义一个名为 Humidity 的类。
    如果没有这一行，编译器会告诉我们在解析温度类中 printWeather() 的原型时它不知道湿度是什么

    *类原型与函数原型的作用相同——它们告诉编译器某些东西是什么样子的，因此可以现在使用并在以后定义。
    *但是，与函数不同，类没有返回类型或参数，因此类原型总是简单的类 ClassName，其中 ClassName 是类的名称。

*/