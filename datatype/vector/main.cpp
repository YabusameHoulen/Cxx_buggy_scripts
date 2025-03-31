#include <iostream>
#include <vector>
using namespace std;

class A
{
private:
    int a;

public:
    A(int v) : a(v)
    {
        std::cout << "Constructor" << std::endl;
    }

    A(const A &other)
    {
        a = other.a;
        std::cout << "Copy Constructor" << std::endl;
    }

    A(const A &&other) noexcept
    {
        a = other.a;
        std::cout << "Move Constructor" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    std::vector<int> vec;
    vec.reserve(10);
    vec.push_back(1);
    std::cout << "--------------" << std::endl;
    vec.emplace_back(3);
    for (auto &&num : vec)
    {
        std::cout<< num <<std::endl;
    }
}