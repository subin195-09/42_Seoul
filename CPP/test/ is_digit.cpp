#include <iostream>
#include <cctype>
#include <cstring>
#include <cstring>

int main(void)
{
    std::string test;

    std::cin >> test;
    for(int i = 0; test[i]; i++)
        std::cout << isdigit(test[i]) << std::endl;
}