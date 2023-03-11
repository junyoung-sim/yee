#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string str;
    std::cin >> str;

    int i;
    std::cin >> i;

    std::cout << str[i-1] << "\n";

    return 0;
}