#include <iostream>
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

int r = 0, d = 0;

int recursion(int n) {
    if(n == 1 || n == 2) {
        r++;
        return 1;
    }
    else
        return recursion(n-2) + recursion(n-1);
}

int dynamic(int n) {
    std::vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i-2] + dp[i-1];
        d++;
    }

    return dp[n];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N; std::cin >> N;

    recursion(N);
    dynamic(N);

    std::cout << r << " " << d << "\n";

    return 0;
}