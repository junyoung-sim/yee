class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp = {{1}};
        for(int r = 1; r < numRows; r++) {
            vector<int> row(r+1, 0);
            row[0] = 1;
            row[r] = 1;

            for(int i = 1; i < r; i++)
                row[i] = dp[r-1][i-1] + dp[r-1][i];
            dp.push_back(row);
        }
        return dp;
    }
};