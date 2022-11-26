#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::vector<long long int>> dp(1001, std::vector<long long int>(10));
    dp[1] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    for(int n = 2; n <= 1000; n++) {
        dp[n][0] = 1;
        for(int k = 1; k <= 9; k++)
            dp[n][k] = (dp[n][k-1] + dp[n-1][k]) % 10007;
    }

    long long int ans = 0;
    for(int k = 0; k <= 9; k++)
        ans += dp[N][k];
    std::cout << ans % 10007 << "\n";

    return 0;
}