// #include "func_symbol.h"
#include <string>
extern void func(std::string a);

void funcTest()
{
    std::string a = "Here it is";
    func(a);
}