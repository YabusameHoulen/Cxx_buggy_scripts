#include <iostream>

template <typename T>
class SharedCount
{ // 辅助类：用于管理管理共享指针的引用计数
private:
    T *ptr;    // 指向管理的对象
    int count; // 共享指针的引用计数
    // 禁止拷贝构造和拷贝赋值，避免多次管理同一个资源
    SharedCount(const SharedCount &) = delete;
    SharedCount &operator=(const SharedCount &) = delete;

public:
    // 构造函数，初始化资源指针并把引用计数设置为1
    SharedCount(T *p) : ptr(p), count(1) {}
    // 析构函数释放资源
    ~SharedCount() { delete ptr; }

    // 增加引用计数
    void increment() { count++; }

    // 减少引用计数
    void decrement()
    {
        if (--count == 0)
        {
            delete this;
        }
    }

    // Getter
    T *get() const
    {
        return ptr;
    }
};

template <typename T>
class shared_ptr
{
private:
    T *ptr;                   // 指向管理对象
    SharedCount<T> *countPtr; // 管理智能指针引用计数类对象

public:
    shared_ptr(T *p = nullptr) : ptr(p)
    {
        if (p)
        {
            countPtr = new SharedCount<T>{p};
        }
        else
        {
            p = nullptr;
        }
    }
    // 拷贝构造
    shared_ptr(const shared_ptr &other) : ptr(other.ptr), countPtr(other.countPtr)
    {
        if (countPtr)
        {
            countPtr->increment();
        }
    }
    // 移动构造
    shared_ptr(shared_ptr &&other) : ptr(other.ptr), countPtr(other.countPtr)
    {
        other.ptr = nullptr;
        other.countPtr = nullptr;
    }

    ~shared_ptr()
    {
        if (countPtr)
        {
            countPtr->decrement();
        }
    }

    T *operator->() const
    {
        return ptr;
    }

    T &operator*() const
    {
        return *ptr;
    }
    // reset
    void reset(T *p = nullptr)
    {
        if (p != ptr)
        {
            if (countPtr)
            {
                countPtr->decrement();
            }
        }

        ptr = p;
        if (p)
        {
            countPtr = new SharedCount<T>(p);
        }
        else
        {
            countPtr = nullptr;
        }
    }
    // Getter
    T *get() const
    {
        return ptr;
    }
};

int main(int argc, char *argv[])
{
    shared_ptr<int> ptr1(new int(10)); // std::make_shared<> ...
    shared_ptr<int> ptr2 = ptr1;

    std::cout << "ptr: " << *ptr1 << std::endl;
    std::cout << "ptr: " << *ptr2 << std::endl;

    ptr1.reset();
    std::cout << "ptr: " << *ptr2 << std::endl;
    shared_ptr<int> ptr3 = std::move(ptr2);
    std::cout << "ptr: " << *ptr3.get() << std::endl;
}