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

    int i = 1;
    int ans = 0;

    while(i < N && ans == 0) {
        int M = i;
        int temp = i;
        while(temp > 0) {
            M += temp % 10;
            temp /= 10;
        }

        if(M == N) ans = i;

        i++;
    }

    std::cout << ans << "\n";

    return 0;
}