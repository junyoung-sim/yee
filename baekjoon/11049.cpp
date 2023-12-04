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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> mat(N, std::vector<int>(2));
    std::vector<std::vector<long long int>> dp(N, std::vector<long long int>(N));

    for(int i = 0; i < N; i++)
        std::cin >> mat[i][0] >> mat[i][1];
    
    for(int n = 1; n < N; n++) {
        for(int i = 0; i < N-n; i++) {
            dp[i][i+n] = RAND_MAX;
            for(int k = i; k < i+n; k++)
                dp[i][i+n] = std::min(dp[i][i+n], dp[i][k] + dp[k+1][i+n] + mat[i][0] * mat[k][1] * mat[i+n][1]);
        }
    }

    std::cout << dp[0][N-1] << "\n";

    return 0;
}