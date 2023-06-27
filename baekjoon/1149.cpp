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

    int dp[N][3];
    for(int i = 0; i < N; i++)
        std::cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    
    for(int i = 1; i < N; i++) {
        dp[i][0] += std::min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += std::min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += std::min(dp[i-1][0], dp[i-1][1]);
    }

    int ans = RAND_MAX;
    for(int j = 0; j < 3; j++)
        ans = std::min(dp[N-1][j], ans);
    
    std::cout << ans << "\n";

    return 0;
}