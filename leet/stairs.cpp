class Solution {
public:
    int climbStairs(int n) {
        vector<vector<int>> dp(46, vector<int>(2,0));
        dp[1] = {1, 0};
        dp[2] = {1, 1};
        dp[3] = {2, 1};

        for(int i = 4; i <= 45; i++) {
            dp[i][0] = dp[i-2][0] + dp[i-1][0];
            dp[i][1] = dp[i-2][1] + dp[i-1][1];
        }

        return dp[n][0] + dp[n][1];
    }
};