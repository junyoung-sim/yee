class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int N = arr.size();
        vector<int> dp(N+1, 0);
        for(int i = 1; i <= N; i++) {
            int wmax = -RAND_MAX;
            for(int j = 1; j <= min(i, k); j++) {
                wmax = max(arr[i-j], wmax);
                dp[i] = max(dp[i-j] + wmax * j, dp[i]);
            }
        }
        return dp[N];
    }
};
