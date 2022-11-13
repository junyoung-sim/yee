#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

int T, N;
std::string ans = "";

int main()
{
    std::vector<std::vector<long long int>> dp(100001, std::vector<long long int>(3));
    dp[1] = {1, 0, 0};
    dp[2] = {0, 1, 0};
    dp[3] = {1, 1, 1};
    dp[4] = {2, 0, 1};

    for(int n = 5; n <= 100000; n++) {
        dp[n][0] = (dp[n-1][1] + dp[n-1][2]) % 1000000009;
        dp[n][1] = (dp[n-2][0] + dp[n-2][2]) % 1000000009;
        dp[n][2] = (dp[n-3][0] + dp[n-3][1]) % 1000000009;
    }

    std::cin >> T;
    for(int t = 0; t < T; t++) {
        std::cin >> N;
        long long int sum = (dp[N][0] + dp[N][1] + dp[N][2]) % 1000000009;
        ans += std::to_string(sum) + "\n";
    }

    std::cout << ans;

    return 0;
}