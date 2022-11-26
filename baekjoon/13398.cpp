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
    for(int i = 0; i < N; i++)
        std::cin >> arr[i];

    std::vector<int> dp(N);
    dp[0] = arr[0];
    dp[1] = std::max(arr[1], std::max(dp[0], dp[0] + arr[1]));


    std::cout << dp[0] << " " << dp[1] << " ";
    for(int i = 2; i < N; i++) {
        dp[i] = std::max(arr[i], std::max(std::max(dp[i-1], dp[i-1] + arr[i]), std::max(dp[i-2], dp[i-2] + arr[i])));
        std::cout << dp[i] << " ";
    }

    std::cout << "\n";

    return 0;
}