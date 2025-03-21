#include <iostream>
#include <vector>
#include <span>
using namespace std;

void process(int &x) { cout << "Lvalue reference" << endl; }
void process(int &&x) { cout << "Rvalue reference" << endl; }

template <typename T>
void forwardExample(T &&arg)
{
    cout << "Normal Forward: " << endl;
    process(arg);
    cout << "Perfect Forward: " << endl;
    process(std::forward<T>(arg)); // std::forward 保持原始类型
}

int main(int argc, char *argv[])
{
    int a{10};
    forwardExample(a);  // 传递左值
    forwardExample(20); // 传递右值
    cout << "Number of args: " << argc << endl;
    for (size_t i = 0; i < argc; i++)
    {
        cout << "Name of kwargs: " << argv[i] << endl;
    }

    // 将 argv 转换为 vector 容器
    std::vector<char *> args(argv, argv + argc);

    std::cout << "程序接受的参数名称和值(vector)：" << std::endl;

    // 使用基于范围的 for 循环
    for (auto &&arg : args)
    {
        std::cout << "参数: " << arg << std::endl;
    }

    std::cout << "程序接受的参数名称和值(span c++20)：" << std::endl;
    std::span args2{argv, static_cast<size_t>(argc)};
    for (auto &&arg : args2)
    {
        std::cout << "参数: " << arg << std::endl;
    }
}