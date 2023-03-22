#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::vector<int> x(4,0);
    std::vector<int> y(4,0);

    int i, j;
    int cx = 0, cy = 0;

    for(int k = 0; k < 3; k++) {
        std::cin >> i >> j;
        if(i != x[0] && i != x[1])
            x[cx++] = i;
        if(j != y[0] && j != y[1])
            y[cy++] = j;
        
        x[2] += (i == x[0]);
        x[3] += (i == x[1]);

        y[2] += (j == y[0]);
        y[3] += (j == y[1]);
    }

    std::cout << (x[2] != 2 ? x[0] : x[1]) << " ";
    std::cout << (y[2] != 2 ? y[0] : y[1]) << "\n";

    return 0;
}