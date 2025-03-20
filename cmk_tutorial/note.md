cmake 是开源、 跨平台的自动化构建工具
并不是包管理工具、 并不只支持C/C++、 支持几乎所有常用编程语言
专注现代C++、 细粒度且透明、 跨平台、 支持生成几乎所有IDE的项目

C/C++ 生成可执行文件 toolchain 流程：
1. 预处理 (-E 参数 宏替换)
2. 编译 (gcc/msvc/clang -S 参数)
3. 汇编 (-C 参数 linux 中生成.o 文件，windows 生.obj 文件)
4. 连接 (将多个二进制文件连接生成一个可执行文件)

cmake 根据平台情况、 编译器类型判断是否生成makefile
Make 工具(类似批处理工具) --- 通过调用 makefile 文件中的命令实现编译和链接、

configure --> generate --> build

cmake -B build -G "Ninja"
cmake --build build

不通过 CMakeLists.txt 运行 CMake  ---> 适合学习cmake语法
cmake -P *.cmake 