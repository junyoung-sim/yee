#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    std::vector<int> v0(N);
    std::vector<int> v1(N);
    for(int i = 0; i < N; i++) {
        std::cin >> v0[i];
        v1[i] = v0[i];
    }

    std::sort(v1.begin(), v1.end());
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());

    for(int i = 0; i < N; i++)
        std::cout << std::lower_bound(v1.begin(), v1.end(), v0[i]) - v1.begin() << " ";

    return 0;
}