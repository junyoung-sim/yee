#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int x, y, w, h;
    std::cin >> x >> y >> w >> h;

    std::cout << std::min(std::min(x, w-x), std::min(y, h-y)) << "\n";

    return 0;
}