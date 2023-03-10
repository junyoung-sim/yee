#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> v(N, 0);
    
    int i, j, k;
    for(int m = 0; m < M; m++) {
        std::cin >> i >> j >> k;
        for(int t = i-1; t < j; t++)
            v[t] = k;
    }

    for(int i = 0; i < N; i++)
        std::cout << v[i] << " ";

    return 0;
}