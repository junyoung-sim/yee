#include <iostream>
#include <cstdlib>
#include <vector>

int N;

int main()
{
    std::cin >> N;

    std::vector<std::vector<long long int>> dp(100001, std::vector<long long int>(3));
    dp[1] = {1, 1, 1};

    for(int n = 2; n <= 100000; n++) {
        dp[n][0] = (dp[n-1][0] + dp[n-1][1] + dp[n-1][2]) % 9901;
        dp[n][1] = (dp[n-1][0] + dp[n-1][1]) % 9901;
        dp[n][2] = dp[n][1];
    }

    std::cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901 << "\n";

    return 0;
}