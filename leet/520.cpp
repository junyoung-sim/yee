class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap = 0;
        for(int i = 0; i < word.length(); i++)
            cap += (word[i] == toupper(word[i]));
        return cap == word.length() || cap == 0 || (word[0] == toupper(word[0]) && cap == 1);
    }
};