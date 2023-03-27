#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int a1, a0;
    std::cin >> a1 >> a0;

    int c;
    std::cin >> c;

    int n0;
    std::cin >> n0;

    int n = n0;
    bool pass = true;
    while(n++ <= 100 && pass)
        pass = (a1 * n + a0 <= c * n);
    std::cout << pass << "\n";

    return 0;
}