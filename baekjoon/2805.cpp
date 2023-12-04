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

    long long int N, M;
    std::cin >> N >> M;

    std::vector<long long int> v(N);
    for(long long int i = 0; i < N; i++) std::cin >> v[i];

    long long int left = 1;
    long long int right = *std::max_element(v.begin(), v.end());
    long long int ans = 0;

    while(left <= right) {
        long long int H = (left + right) / 2;
        long long int sum = 0;
        for(long long int &x: v)
            sum += (x > H ? x - H : 0);
        if(sum < M)
            right = H-1;
        else {
            ans = H;
            left = H+1;
        }
    }

    std::cout << ans << "\n";

    return 0;
}