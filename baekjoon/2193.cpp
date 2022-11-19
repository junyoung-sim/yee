#include <iostream>
#include <cstdlib>
#include <vector>

int N;

int main()
{
    std::vector<long long int> dp(91, 0);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for(int n = 4; n <= 90; n++)
        dp[n] = dp[n-2] + dp[n-1];

    std::cin >> N;
    std::cout << dp[N] << "\n";

    return 0;
}