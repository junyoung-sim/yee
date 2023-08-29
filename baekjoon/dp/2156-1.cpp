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
    for(int i = 0; i < N; i++)
        std::cin >> v[i];
    
    for(int i = 0; i < N; i++) {
        if(i == 0) { dp[0] = v[0]; continue; }
        if(i == 1) { dp[1] = v[0] + v[1]; continue; }
        if(i == 2) { dp[2] = std::max(v[2] + std::max(v[0], v[1]), dp[1]); continue; }
        
        dp[i] = std::max(v[i] + std::max(dp[i-2], v[i-1] + dp[i-3]), dp[i-1]);
    }

    std::cout << dp[N-1] << "\n";

    return 0;
}