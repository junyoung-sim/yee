#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    std::vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    std::vector<std::vector<int>> dp(prices.size() - 1, std::vector<int>(prices.size(), 0));

    for(int i = 0; i < prices.size() - 1; i++)
        for(int j = i+1; j < prices.size(); j++)
            dp[i][j] = prices[j] - prices[i];

    int k = 2; // transaction cap

    for(int i = 0; i < dp.size(); i++) {
        for(int j = 0; j < dp[i].size(); j++) std::cout << dp[i][j] << " ";
        std::cout << "\n";
    }

    return 0;
}