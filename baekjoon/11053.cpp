#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> nums(N);
    for(int i = 0; i < N; i++)
        std::cin >> nums[i];
    
    std::vector<int> dp(N, 1); // dp[i] = max len when stop at nums[i]

    int ans = 1;
    for(int i = 1; i < N; i++) { // stop index
        for(int j = 0; j < i; j++) {
            // (1) stop num is larger (2) larger seq already exists before stop
            if(nums[i] > nums[j] && dp[i] <= dp[j]) dp[i] = dp[j] + 1;
            ans = std::max(dp[i], ans);
        }
    }

    std::cout << ans << "\n";

    return 0;
}