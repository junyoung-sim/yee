#include <bits/stdc++.h>
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

    long long int N, K;
    std::cin >> N >> K;

    long long int l = 1;
    long long int r = K; // B[k] <= k
    long long int m, ans;

    while(l <= r) {
        m = (l + r) / 2;
        long long int count = 0;
        // count number of i * j values that are less than m
        for(long long int i = 1; i <= N; i++)
            count += std::min(m / i, N);
        
        if(count >= K) { // at least K number of lower values -> m is big enough (decrease)
            ans = m;
            r = m - 1;
        }
        else l = m + 1; // not enough lower values -> m is too small (increase)
    }

    std::cout << ans << "\n";

    return 0;
}