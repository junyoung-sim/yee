#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string str;
    std::getline(std::cin, str);

    int count = 0;
    for(int i = 0; i < str.length(); i++) {
        count += (i > 0 && str[i] == ' ' && str[i-1] != ' ');
        count += (i == str.length() - 1 && str[i] != ' ');
    }

    std::cout << count << "\n";

    return 0;
}