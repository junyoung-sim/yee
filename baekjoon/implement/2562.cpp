#include <iostream>
#include <cstdlib>
#include <cstdio>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int max = -RAND_MAX;
    int ind = -1;

    int v;
    for(int i = 0; i < 9; i++) {
        std::cin >> v;
        if(v > max) {
            max = v;
            ind = i;
        }
    }

    std::cout << max << "\n" << ind + 1 << "\n";

    return 0;
}