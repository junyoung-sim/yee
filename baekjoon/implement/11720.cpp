#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

int main()
{
    int N;
    std::cin >> N;

    std::string str;
    std::cin >> str;

    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += str[i] - '0';
    
    std::cout << sum << "\n";

    return 0;
}