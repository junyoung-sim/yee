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

    std::vector<int> v(N+1);
    for(int i = 0; i <= N; i++)
        v[i] = i;
    
    for(int m = 0; m < M; m++) {
        int i, j;
        std::cin >> i >> j;
        while(i < j)
            std::swap(v[i++], v[j--]);
    }

    for(int i = 1; i <= N; i++)
        std::cout << v[i] << " ";

    return 0;
}