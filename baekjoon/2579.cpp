#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> v(N+1, 0);
    std::vector<int> dp(N+1, 0);

    for(int i = 1; i <= N; i++) {
        std::cin >> v[i];
        if(i == 1)
            dp[i] = v[i];
        if(i == 2)
            dp[i] = dp[i-1] + v[i];
    }

    for(int i = 3; i <= N; i++)
        dp[i] = std::max(dp[i-3] + v[i-1] + v[i], dp[i-2] + v[i]);
    
    std::cout << dp[N] << "\n";

    return 0;
}