class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for(int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
            if(i+1 < s.length())
                dp[i][i+1] = (s[i] == s[i+1]);
        }

        string ans = "";
        int i = 0, j = 0;
        while(j < s.length()) {
            while(i <= j) {
                if(!dp[i][j])
                    dp[i][j] = (s[i] == s[j] && i+1 < s.length() && j-1 >= 0 && dp[i+1][j-1]);
                if(dp[i][j] && j-i+1 > ans.length())
                    ans = s.substr(i, j-i+1);
                i++;
            }
            j++;
            i=0;
        }

        return ans;
    }
};