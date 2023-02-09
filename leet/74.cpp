class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        int i = matrix.size() - 1;
        while(!found && i >= 0) {
            if(matrix[i][0] <= target) {
                for(int j = 0; j < matrix[i].size(); j++) {
                    found = (matrix[i][j] == target);
                    if(found) break;
                }
            }
            i--;
        }
        return found;
    }
};