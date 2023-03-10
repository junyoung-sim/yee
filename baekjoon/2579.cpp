#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> v(N+1, 0);
    std::vector<int> dp(N+1, 0); // dp[i] = max sum when stopping at v[i]

    for(int i = 1; i <= N; i++) {
        std::cin >> v[i];
        if(i == 1)
            dp[i] = v[i];
        if(i == 2)
            dp[i] = dp[i-1] + v[i];
    }

    // (1) can take 1 or 2 steps at a time
    // (2) cannot take 3 adjacent steps
    // (3) must arrive to the last step

    for(int i = 3; i <= N; i++)
        dp[i] = v[i] + std::max(dp[i-3] + v[i-1], dp[i-2]);
    
    std::cout << dp[N] << "\n";

    return 0;
}