#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string str;

    while(std::getline(std::cin, str))
        std::cout << str << "\n";

    return 0;
}