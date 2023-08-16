#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, T;
    std::cin >> N >> T;

    std::vector<int> v(N);
    for(int i = 0; i < N; i++)
        std::cin >> v[i];
    
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(v[i] < T)
            std::cout << v[i] << " ";
    }

    return 0;
}