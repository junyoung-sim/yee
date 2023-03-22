#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> factor;

    for(int i = 1; i <= N; i++)
        if(N % i == 0)
            factor.push_back(i);

    if(factor.size() >= K)
        std::cout << factor[K-1] << "\n";
    else
        std::cout << "0\n";

    return 0;
}