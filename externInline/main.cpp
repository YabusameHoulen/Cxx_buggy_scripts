#include <iostream>
#include "func_symbol.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Calling function func: " << endl;
    std::string Me{"XiaoJunYu"};
    func(Me);
}