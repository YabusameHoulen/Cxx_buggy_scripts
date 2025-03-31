#include <iostream>
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

    A(const A &&other)
    {
        a = other.a;
        std::cout << "Move Constructor" << std::endl;
    }

    // 友元函数重载 <<
    friend ostream &operator<<(ostream &os, const A &obj)
    {
        os << "MyClass Value: " << obj.a;
        return os;
    }
};
void modify(const char *str);

int main(int argc, char *argv[])
{
    double a = 3.14;
    int b = static_cast<int>(a);
    std::cout << "b is " << b << std::endl;
    // int c{a};
    int c = a;
    std::cout << "c is " << c << std::endl;

    char str[] = "Hello";
    str[0] = 'W';
    modify(str);
    std::cout << "str is " << str << std::endl;

    A help = A(3);
    std::cout << "Class A is " << help << std::endl;
}

void modify(const char *str)
{
    // 修改非const字符数组是安全的
    char *p = const_cast<char *>(str);
    p[0] = 'A';
}
