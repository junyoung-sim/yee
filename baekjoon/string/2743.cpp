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

    std::cout << str.length() << "\n";

    return 0;
}