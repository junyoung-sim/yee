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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    // brute force all possibilites for (N,M) where N=[1,3] and M=[1,5]
    // record number of possibilities for each (N,M) in a 2D DP table
    std::vector<std::vector<long long int>> dp(31, std::vector<long long int>(31));
    for(int n = 1; n <= 30; n++) {
        for(int m = 1; m <= 30; m++) {
            if(n == 1)
                dp[n][m] = m;
            else {
                if(n > m) dp[n][m] = 0;
                else if(n == m) dp[n][m] = 1;
                else dp[n][m] = dp[n-1][m-1] + dp[n][m-1];
            }
        }
    }

    int T;
    std::cin >> T;

    int N, M;
    for(int t = 1; t <= T; t++) {
        std::cin >> N >> M;
        std::cout << dp[N][M] << "\n";
    }

    return 0;
}