#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::string str;
    for(int i = 0; i < N; i++) {
        std::cin >> str;
        std::cout << str[0] << str[str.length() - 1] << "\n";
    }

    return 0;
}