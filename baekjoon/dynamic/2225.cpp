#include <iostream>
#include <cstdlib>
#include <vector>

int N, K;
long long int ans = 0;

int main()
{
    std::cin >> N >> K;

    std::vector<std::vector<long long int>> dp(N+1, std::vector<long long int>(K+1, 0));
    for(int k = 1; k <= K; k++) {
        dp[0][k] = 1;
        dp[1][k] = k;
    }

    for(int n = 2; n <= N; n++) {
        dp[n][1] = 1;
        for(int k = 2; k <= K; k++)
            dp[n][k] = (dp[n][k-1] + dp[n-1][k]) % 1000000000;
    }

    std::cout << dp[N][K] << "\n";

    return 0;
}