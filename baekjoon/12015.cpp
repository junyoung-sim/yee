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

long long int search(std::vector<long long int> &lis, long long int x) {
    long long int low = 0, high = lis.size() - 1;
    while(low < high) {
        long long int mid = (low + high) / 2;
        (x <= lis[mid]) ? (high = mid) : (low = mid + 1);
    }
    return high;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long int N;
    std::cin >> N;

    std::vector<long long int> v(N);
    std::vector<long long int> lis(1); // Longest Increasing Sequence (LIS)

    for(long long int i = 0; i < N; i++) std::cin >> v[i];

    lis[0] = v[0];
    for(long long int i = 1; i < N; i++) {
        if(lis.back() < v[i]) lis.push_back(v[i]);
        else {
            long long arg = search(lis, v[i]); // search index of value in LIS that is greater than and closest to v[i]
            lis[arg] = v[i];
        }
    }

    std::cout << lis.size() << "\n";

    return 0;
}