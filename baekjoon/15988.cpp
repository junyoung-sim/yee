#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

int T, N;
std::string ans = "";

int main()
{
    std::vector<std::vector<long long int>> dp(1000001, std::vector<long long int>(3,0));
    dp[1] = {1, 0 ,0};
    dp[2] = {1, 1, 0};
    dp[3] = {2, 1, 1};
    dp[4] = {4, 2, 1};
    dp[5] = {7, 4, 2};
    dp[6] = {13, 7, 4};

    for(int n = 7; n <= 1000000; n++) {
        dp[n][0] = (dp[n-3][0] + dp[n-2][0] + dp[n-1][0]) % 1000000009;
        dp[n][1] = (dp[n-3][1] + dp[n-2][1] + dp[n-1][1]) % 1000000009;
        dp[n][2] = (dp[n-3][2] + dp[n-2][2] + dp[n-1][2]) % 1000000009;
    }

    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        std::cin >> N;
        ans += std::to_string((dp[N][0] + dp[N][1] + dp[N][2]) % 1000000009) + "\n";
    }

    std::cout << ans;

    return 0;
}