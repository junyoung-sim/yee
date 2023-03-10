#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int v;
    int min = RAND_MAX, max = -RAND_MAX;
    for(int i = 0; i < N; i++) {
        std::cin >> v;
        min = std::min(v, min);
        max = std::max(v, max);
    }

    std::cout << min << " " << max << "\n";

    return 0;
}