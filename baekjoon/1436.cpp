#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    int n = 0;
    int i = 666;
    while(n < N) {
        n += (std::to_string(i).find("666") != -1);
        i++;
    }

    std::cout << i-1 << "\n";

    return 0;
}