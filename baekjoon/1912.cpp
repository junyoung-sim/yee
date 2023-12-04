#include <iostream>
#include <cstdlib>
#include <vector>

int N;
int ans = -1000;

int main()
{
    std::cin >> N;
    std::vector<int> given(N);
    for(int i = 0; i < N; i++) {
        std::cin >> given[i];
        ans = std::max(given[i], ans);
    }

    std::vector<int> dp(N);
    for(int i = 0; i < N; i++) {
        dp[i] = given[i];
        if(dp[i] < dp[i-1] + given[i])
            dp[i] = dp[i-1] + given[i];
        ans = std::max(dp[i], ans);
    }

    std::cout << ans << "\n";

    return 0;
}