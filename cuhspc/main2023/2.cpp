#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::string line;
    std::string ans = "";

    std::getline(std::cin, line);
    for(int i = 0; i < N; i++) {
        std::getline(std::cin, line);
        ans += line[0];
    }

    std::cout << ans << "\n";

    return 0;
}