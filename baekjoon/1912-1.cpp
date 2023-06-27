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

    int N;
    std::cin >> N;

    int v[N];
    int dp[N];

    for(int i = 0; i < N; i++)
        std::cin >> v[i];

    dp[0] = v[0];
    int ans = dp[0];
    
    for(int i = 1; i < N; i++) {
        dp[i] = std::max(v[i], std::max(dp[i-1] + v[i], v[i-1] + v[i]));
        ans = std::max(dp[i], ans);
    }

    std::cout << ans << "\n";

    return 0;
}