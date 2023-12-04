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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N; std::cin >> N;

    int v[N], dp[N];
    for(int i = 0; i < N; i++) {
        std::cin >> v[i];
        dp[i] = 1;
    }
    
    int ans = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j] && dp[i] <= dp[j])
                dp[i] = dp[j] + 1;
            ans = std::max(dp[i], ans);
        }
    }

    std::cout << ans << "\n";

    return 0;
}