#include <bits/stdc++.h>
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

/*
dp[i][j]: optimal cost of merging files from i to j
Before merging files from i to j, there must have been a point k
where two intermediate files were merged. Thus, we must find the
optimal point k in order to compute dp[i][j].
*/

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T; std::cin >> T;
    while(T--) {
        int N; std::cin >> N;
        std::vector<int> sum(N+1, 0); // sum of file values from 1 to i
        std::vector<std::vector<int>> dp(N+1, std::vector<int>(N+1, 0)); // optimal merge cost

        for(int i = 1; i <= N; i++) {
            std::cin >> sum[i];
            sum[i] += sum[i-1];
        }

        for(int n = 1; n < N; n++) { // interval size
            for(int i = 1; i <= N-n; i++) { // beginning of interval
                dp[i][i+n] = RAND_MAX;
                for(int k = i; k < i+n; k++)
                    dp[i][i+n] = std::min(dp[i][k] + dp[k+1][i+n] + sum[i+n] - sum[i-1], dp[i][i+n]);
            }
        }
        
        std::cout << dp[1][N] << "\n";
    }

    return 0;
}