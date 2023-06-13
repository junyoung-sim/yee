#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

void star(int i, int j, int N) {
    if((i / N) % 3 == 1 && (j / N) % 3 == 1) std::cout << " ";
    else {
        if(N / 3 == 0) std::cout << "*";
        else star(i, j, N / 3);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N; std::cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            star(i, j, N);
        std::cout << "\n";
    }

    return 0;
}