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

    long long int dp[N+1][10];

    for(int n = 1; n <= N; n++) {
        for(int i = 1; i <= 9; i++) {
            if(n == 1) { dp[n][i] = 1; continue; }
            
            dp[n][1] = (dp[n-1][2] + dp[n-1][9]) % 1000000000;
            dp[n][9] = dp[n-1][8] % 1000000000;

            if(i > 1 && i < 9)
                dp[n][i] = (dp[n-1][i-1] + dp[n-1][i+1]) % 1000000000;
        }
    }

    long long int ans = 0;
    for(int i = 1; i <= 9; i++)
        ans += dp[N][i];
    
    std::cout << ans % 1000000000 << "\n";

    return 0;
}