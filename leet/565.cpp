class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int i = 0, ans = 0;
        while(i < nums.size()) {
            int cur = i;
            int len = 0;
            while(nums[cur] != -1) {
                int nex = nums[cur];
                nums[cur] = -1;
                cur = nex;
                len++;
            }
            i++;
            ans = max(len, ans);
        }
        return ans;
    }
};