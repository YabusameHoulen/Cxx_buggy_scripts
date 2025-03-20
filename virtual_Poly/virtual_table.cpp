#include <iostream>

class Base
{
public:
    virtual void func1()
    {
        std::cout << "Base" << std::endl;
    }
    virtual void func2() {}
};

class Derived : public Base
{
public:
    void func1() override
    {

        std::cout << "Derived" << std::endl;
    }
};

void test()
{
    Base *ptr = new Derived();
    ptr->func1();

    delete ptr;
}

class A
{
    virtual void f() {}
};
class B
{
    virtual void f() {}
};
class C : public A, public B
{
    
};

int main(int argc, char *argv[])
{
    test();
}