class Solution {
public:
    bool isPalindrome(int x) {
        string x_str = to_string(x);
        bool palindrome = true;
        for(int i = 0; i < x_str.length() / 2; i++) {
            palindrome = (x_str[i] == x_str[x_str.length() - 1 - i]);
            if(!palindrome) break;
        }
        return palindrome;
    }
};