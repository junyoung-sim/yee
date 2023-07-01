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
    
    int dp[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            std::cin >> dp[i][j];
    
    for(int i = N-2; i >= 0; i--)
        for(int j = 0; j <= i; j++)
            dp[i][j] += std::max(dp[i+1][j], dp[i+1][j+1]);
    
    std::cout << dp[0][0] << "\n";

    return 0;
}