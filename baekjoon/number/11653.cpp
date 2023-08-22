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

    while(N != 1) {
        for(int i = 2; i <= N; i++) {
            if(N % i == 0) {
                N /= i;
                std::cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}