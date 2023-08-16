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

    int min_x = 10000;
    int max_x = -10000;
    int min_y = 10000;
    int max_y = -10000;

    int x, y;
    for(int i = 0; i < N; i++) {
        std::cin >> x >> y;
        min_x = std::min(x, min_x);
        max_x = std::max(x, max_x);
        min_y = std::min(y, min_y);
        max_y = std::max(y, max_y);
    }

    std::cout << (max_x - min_x) * (max_y - min_y) << "\n";

    return 0;
}