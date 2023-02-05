class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int i = 0, j = 1;
        while(nums[i] + nums[j] != target)
            if(++j >= nums.size()) j = ++i + 1;
        return vector<int>({i, j});
    }
}