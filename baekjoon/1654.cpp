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

typedef long long int lint;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    lint K, N;
    std::cin >> K >> N;

    std::vector<lint> v(K);
    for(lint i = 0; i < K; i++)
        std::cin >> v[i];

    lint ans = 0;
    lint l = 1, r = *std::max_element(v.begin(), v.end());
    while(l <= r) {
        lint mid = (l + r) / 2;
        lint sum = 0;
        for(lint &x: v)
            sum += x / mid;
        if(sum < N) // need more blocks (shorter blocks needed)
            r = mid - 1;
        else { // enough blocks (larger blocks)
            l = mid + 1;
            ans = mid;
        }
    }
    std::cout << ans << "\n";

    return 0;
}