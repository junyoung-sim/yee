#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> T(N+1);
    std::vector<int> P(N+1);
    std::vector<int> dp(N+1); // max. profit up until [i]

    for(int i = 1; i <= N; i++) {
        std::cin >> T[i] >> P[i];
        dp[i] = P[i];
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            if(i - j >= T[j])
                dp[i] = std::max(P[i] + dp[j], dp[i]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(i + T[i] <= N+1)
            ans = std::max(dp[i], ans);
    }
    std::cout << ans << "\n";

    return 0;
}