#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    int N;
    std::string str;
    for(int t = 1; t <= T; t++) {
        std::cin >> N >> str;
        for(int i = 0; i < str.length(); i++)
            for(int k = 0; k < N; k++)
                std::cout << str[i];
        std::cout << "\n";
    }

    return 0;
}