class Solution {
public:
    int xorOperation(int n, int start) {
        int arr[n];
        arr[0] = start;
        for(int i = 1; i < n; i++)
            arr[i] = arr[i-1] ^ (arr[0] + 2 * i);
        return arr[n-1];
    }
};