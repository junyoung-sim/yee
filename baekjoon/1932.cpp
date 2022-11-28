#include <iostream>
#include <cstdlib>
#include <vector>

int N;
int ans;

int main()
{
    std::cin >> N;
    std::vector<std::vector<int>> dp(N, std::vector<int>(N,0));

    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++)
            std::cin >> dp[i][j];

    for(int i = N-2; i >= 0; i--)
        for(int j = 0; j <= i; j++)
            dp[i][j] = std::max(dp[i][j] + dp[i+1][j], dp[i][j] + dp[i+1][j+1]);

    std::cout << dp[0][0] << "\n";

    return 0;
}