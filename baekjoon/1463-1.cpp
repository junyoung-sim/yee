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

    int dp[N+1];

    for(int i = 1; i <= N; i++) {
        if(i == 1) { dp[1] = 0; continue; }
        if(i == 2) { dp[2] = 1; continue; }
        if(i == 3) { dp[3] = 1; continue; }

        dp[i] = RAND_MAX;
        if(i % 3 == 0) dp[i] = std::min(dp[i/3]+1, dp[i]);
        if(i % 2 == 0) dp[i] = std::min(dp[i/2]+1, dp[i]);
        dp[i] = std::min(dp[i-1]+1, dp[i]);
    }

    std::cout << dp[N] << "\n";

    return 0;
}