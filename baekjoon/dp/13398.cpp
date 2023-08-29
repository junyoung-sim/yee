#include <iostream>
#include <cstdlib>
#include <vector>

int N;
std::vector<int> arr;

int ans = -RAND_MAX;

int main()
{
    std::cin >> N;
    arr.resize(N);
    for(int i = 0; i < N; i++) {
        std::cin >> arr[i];
        ans = std::max(arr[i], ans);
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(2,0));

    for(int i = 0; i < N; i++) {
        dp[i][0] = arr[i];
        dp[i][1] = 0;

        if(i != 0) {
            dp[i][0] = std::max(dp[i-1][0] + arr[i], arr[i]);
            dp[i][1] = std::max(dp[i-1][0], dp[i-1][1] + arr[i]);
            ans = std::max(std::max(dp[i][0], dp[i][1]), ans);
        }
    }

    std::cout << ans << "\n";

    return 0;
}