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

    int N; std::cin >> N;

    int v[N], dp[N];
    for(int i = 0; i < N; i++) {
        std::cin >> v[i];
        if(i == 0)
            dp[0] = v[0];
        else if(i == 1)
            dp[1] = v[0] + v[1];
        else if(i == 2)
            dp[2] = v[2] + std::max(v[0], v[1]);
        else
            dp[i] = v[i] + std::max(dp[i-3] + v[i-1], dp[i-2]);
    }

    std::cout << dp[N-1] << "\n";

    return 0;
}