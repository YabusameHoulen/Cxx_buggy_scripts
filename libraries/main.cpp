#include <iostream>
#include "math.h"


int main(int argc, char *argv[])
{
    std::cout << adding(3, 4) << std::endl;
    /// g++ -c math.cpp 生成 math.o 文件
    /// ar rcs libmath.a math.o  生成静态库 libmath.a
    // (-l 链接库时省略 lib 和 .a 扩展名)
    /// g++ main.cpp -L. -lmath -o app 静态链接生成可执行文件app


    /// g++ -fPIC -c math.cpp 生成 math.o 文件
    /// g++ -shared -o libmath.so math.o 生成动态库 libmath.so
    /// g++ main.cpp -L. -lmath -o app 链接生成可执行文件app

    /// 运行程序时需要 在环境变量中设置动态库的位置
    /// LD_LIBRARY_PATH 告诉可执行文件库文件的位置以加载动态库
}