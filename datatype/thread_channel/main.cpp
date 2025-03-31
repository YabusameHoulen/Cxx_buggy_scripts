#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

void heavy_task()
{
    for (size_t i = 999999999; i >= 0; i--)
    {
        // volatile 防止被编译器优化
        volatile size_t x = 1 + i;
    }
}

void dead_loop()
{
    int i = 1;
    while (i > 0)
    {
        1 + i;
    }
}

int main(int argc, char *argv[])
{
    std::vector<std::thread> threads;
    threads.emplace_back(heavy_task);
    threads.emplace_back(dead_loop);
    std::cout << "Here is a big threading!" << std::endl;
    for (auto &&i : threads)
    {
        i.join();
    }
}