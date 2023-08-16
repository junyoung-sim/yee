#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

int calls = 0;

bool recursion(const char *str, int l, int r) {
    calls++;
    if(l >= r) return true;
    else if(str[l] != str[r]) return false;
    else return recursion(str, l+1, r-1);
}

bool isPalindrome(const char *str) {
    calls = 0;
    return recursion(str, 0, strlen(str) - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T; std::cin >> T;
    while(T--) {
        char str[1001];
        std::cin >> str;
        std::cout << isPalindrome(str) << " " << calls << "\n";
    }

    return 0;
}