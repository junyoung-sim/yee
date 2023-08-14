#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    int x;
    std::map<int, int> df;
    for(int i = 0; i < N; i++) {
        std::cin >> x;
        df[x]++;
    }

    int M;
    std::cin >> M;
    for(int i = 0; i < M; i++) {
        std::cin >> x;
        std::cout << df[x] << " ";
    }

    return 0;
}