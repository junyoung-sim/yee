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

bool binary_search(std::vector<long long int> &v, long long int q, int l, int r) {
    if(l > r) return false;
    int mid = (l + r) / 2;
    if(q > v[mid]) return binary_search(v, q, mid+1, r);
    if(q < v[mid]) return binary_search(v, q, l, mid-1);
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N; std::cin >> N;
    std::vector<long long int> v(N);
    for(int i = 0; i < N; i++) std::cin >> v[i];

    std::sort(v.begin(), v.end());

    int M; std::cin >> M;
    for(int i = 0; i < M; i++) {
        long long int q; std::cin >> q;
        std::cout << binary_search(v, q, 0, N-1) << "\n";
    }

    return 0;
}