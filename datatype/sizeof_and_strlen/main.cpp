#include <iostream>
#include <cstring>
using namespace std;

void test(char str[]);
int my_strlen(char str[]);

int main(int argc, char *argv[])
{
    char str[] = "Hello"; // 字符结尾隐藏结尾符号  \0
    char *p = str;

    cout << "sizeof(str): " << sizeof(str) << endl;
    cout << "strlen(str): " << strlen(str) << endl; // 包括结尾字符串\0

    cout << "sizeof(p): " << sizeof(p) << endl;
    cout << "strlen(p): " << strlen(p) << endl;
    cout << "my_strlen(p): " << my_strlen(p) << endl;

    test(str);

    int num = 1; // 0x00000001
    char *ptr = (char *)&num;

    if (*ptr == 1)
    {

        cout << "Littel Endian" << endl;
    }
    else
    {
        cout << "Big Endian" << endl;
    }
}

void test(char aa[])
{
    cout << "sizeof(str) in function: " << sizeof(aa) << endl;
    cout << "strlen(str) in function: " << strlen(aa) << endl;
}

int my_strlen(char str[])
{
    int count = 0;
    while (*str++ != '\0')
    {
        count++;
    }
    return count;
}