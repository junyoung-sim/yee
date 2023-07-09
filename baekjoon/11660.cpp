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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M; std::cin >> N >> M;

    int v[N+1][N+1];
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            std::cin >> v[i][j];

    return 0;
}