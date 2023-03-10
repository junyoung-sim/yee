#include <iostream>
#include <cstdlib>
#include <cstdio>

int main()
{
    int N, M;
    std::cin >> N >> M;

    int v[N];
    for(int i = 0; i < N; i++)
        v[i] = i+1;
    
    int i, j;
    for(int m = 0; m < M; m++) {
        std::cin >> i >> j;
        int temp = v[i-1];
        v[i-1] = v[j-1];
        v[j-1] = temp;
    }

    for(int i = 0; i < N; i++)
        std::cout << v[i] << " ";

    return 0;
}