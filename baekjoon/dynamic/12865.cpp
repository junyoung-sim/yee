#include <iostream>
#include <cstdlib>
#include <vector>

int N, W;

int main()
{
    std::cin >> N >> W;

    std::vector<int> w(N+1,0);
    std::vector<int> v(N+1,0);
    for(int i = 1; i <= N; i++)
        std::cin >> w[i] >> v[i];

    std::vector<std::vector<int>> dp(N+1, std::vector<int>(W+1,0));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= W; j++) {
            dp[i][j] = dp[i-1][j];
            if(j - w[i] >= 0)
                dp[i][j] = std::max(v[i] + dp[i-1][j-w[i]], dp[i-1][j]);
        }
    }

    std::cout << dp[N][W] << "\n";

    return 0;
}