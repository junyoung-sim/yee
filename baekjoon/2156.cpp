#include <iostream>
#include <cstdlib>
#include <vector>

int N;
std::vector<int> wine;

int main()
{
    std::cin >> N;
    wine.resize(N+1);
    for(int i = 1; i <= N; i++)
        std::cin >> wine[i];

    std::vector<int> dp(N+1, 0);
    dp[1] = wine[1];
    dp[2] = dp[1] + wine[2];

    for(int i = 3; i <= N; i++)
        dp[i] = std::max(std::max(dp[i-1], dp[i-3] + wine[i-1] + wine[i]), dp[i-2] + wine[i]);

    std::cout << dp[N] << "\n";

    return 0;
}