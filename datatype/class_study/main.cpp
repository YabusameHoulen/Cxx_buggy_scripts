#include <iostream>
// #include <utility>

class Empty
{
public:
    // 默认构造和析构函数
    Empty() = default;
    ~Empty() = default;
    // 拷贝构造
    Empty(const Empty &other) = default; // 如果不使用引用会发生无限递归
    // 拷贝赋值运算符
    Empty &operator=(const Empty &other) = default;
    // 移动构造
    Empty(Empty &&other) = default;
    // 移动赋值运算符
    Empty &operator=(Empty &&other) = default;
};

class Empty2
{
};

int main(int argc, char *argv[])
{
    Empty e1;

    Empty e2 = e1;
    e2 = e1;

    Empty *p = new Empty();
    delete p;

    Empty e3 = std::move(e1);
    e3 = std::move(e2);

    std::cout << "This is good" << std::endl;
}
