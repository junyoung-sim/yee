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

int N;
long long int ans = 0;
long long int h[100000];
long long int seg[1000000];

// [a,b]: interval in array
// n: node of segment tree
// segment tree consists of nodes having the index of the minimum value in [a,b]
int segtree(int a, int b, int n) {
	if(a == b)
		return seg[n] = a;
	int mid = (a + b) / 2;
	int l = segtree(a, mid, n*2+1);
	int r = segtree(mid+1, b, n*2+2);
	return seg[n] = (h[l] < h[r] ? l : r);
}

// [a,b]: interval in array
// [l,r]: interval in segment tree
// n: node of segment tree
int argmin(int a, int b, int l, int r, int n) {
	if(r < a || b < l) return RAND_MAX; // segment tree range out of bounds
	if(a <= l && r <= b) return seg[n]; // segment tree range in bounds

	int mid = (l + r) / 2;
	int lx = argmin(a, b, l, mid, n*2+1);
	int rx = argmin(a, b, mid+1, r, n*2+2);

	if(lx == RAND_MAX) return rx;
	if(rx == RAND_MAX) return lx;

	return (h[lx] < h[rx] ? lx : rx);
}

void solve(int a, int b) {
	if(a > b) return;
	int p = argmin(a, b, 0, N-1, 0);
	ans = std::max(h[p]*(b-a+1), ans);

	solve(a, p-1);
	solve(p+1, b);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

	while(std::cin >> N && N) {
		for(int i = 0; i < N; i++)
			std::cin >> h[i];
		segtree(0, N-1, 0);
		solve(0, N-1);
		std::cout << ans << "\n";
		ans = 0;
	}

    return 0;
}