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

    long long int dp[101];
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;

    for(int i = 6; i <= 100; i++)
        dp[i] = dp[i-1] + dp[i-5];
    
    int T; std::cin >> T;

    while(T--) {
        int N; std::cin >> N;
        std::cout << dp[N] << "\n";
    }

    return 0;
}