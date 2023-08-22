#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> nums(N);
    std::vector<int> dp(N); // dp[i] = max sum when stop at nums[i]

    for(int i = 0; i < N; i++) {
        std::cin >> nums[i];
        dp[i] = nums[i];
    }

    int ans = dp[0];
    for(int i = 1; i < N; i++) { // stop
        for(int j = 0; j < i; j++) {
            // (1) stop num is larger (2) seq with larger sum exists
            if(nums[i] > nums[j] && dp[j] + nums[i] > dp[i])
                dp[i] = dp[j] + nums[i];
            ans = std::max(dp[i], ans);
        }
    }

    std::cout << ans << "\n";

    return 0;
}