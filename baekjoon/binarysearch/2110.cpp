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

    int N, C;
    std::cin >> N >> C;

    std::vector<long long int> x(N);
    for(int i = 0; i < N; i++)
        std::cin >> x[i];
    std::sort(x.begin(), x.end());

    long long int min_dist = 1;
    long long int max_dist = x[N-1] - x[0];
    long long int ans = -RAND_MAX;

    while(min_dist <= max_dist) {
        long long int mid = (min_dist + max_dist) / 2;
        long long p = 0;
        int routers = 1;
        for(int i = 1; i < N; i++) {
            if(x[i] - x[p] >= mid) {
                p = i;
                routers++;
            }
        }
        
        if(routers < C) max_dist = mid-1;
        else {
            min_dist = mid+1;
            ans = std::max(mid, ans);
        }
    }

    std::cout << ans << "\n";

    return 0;
}