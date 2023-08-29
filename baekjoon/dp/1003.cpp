#include <iostream>
#include <vector>
#include <string>

int T, N;
std::string ans = "";

int main()
{
    std::vector<std::vector<int>> dp(41, std::vector<int>(2));
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    dp[2] = {1, 1};

    for(int n = 3; n <= 40; n++) {
        dp[n][0] = dp[n-2][0] + dp[n-1][0];
        dp[n][1] = dp[n-1][0] + dp[n-1][1];
    }

    std::cin >> T;
    for(int t = 0; t < T; t++) {
        std::cin >> N;
        ans += std::to_string(dp[N][0]) + " " + std::to_string(dp[N][1]) + "\n";
    }

    std::cout << ans;

    return 0;
}