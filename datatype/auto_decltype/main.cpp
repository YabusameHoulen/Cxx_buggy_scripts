#include <iostream>
#include <vector>
#include <memory>

template <class T1, class T2>
auto add(T1 a, T2 b) -> decltype(a + b) // 后置返回类型
{
    return a + b;
}

int main(int argc, char *argv[])
{
    auto a = std::make_unique<int>(3);
    auto b = std::make_shared<int>(4);
    auto c = std::vector<int>{3, 4, 99, 5, 6};

    for (std::vector<int>::iterator it = c.begin(); it != c.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    for (auto it = c.begin(); it != c.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    for (auto &&i : c)
    {
        std::cout << i << std::endl;
    }

    std::cout << "-----------------" << std::endl;

    int d = 20;
    auto &ref = d;

    const int e = 30;
    const auto y = e; // 要保持 const 属性的话

    std::cout << "-----------------" << std::endl;

    int g = 10;
    auto &z = g;
    std::cout << g << std::endl;
    auto x = z;
    x += 1;
    std::cout << g << std::endl;
    decltype(auto) yy = z;
    yy += 1;
    std::cout << g << std::endl;

    // std::cout <<  << std::endl;
}