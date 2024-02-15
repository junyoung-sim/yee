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

int N, M;
long long int v[100000];
long long int seg[1000000];

// [a,b]: array interval
// n: node of segment tree
int segtree(int a, int b, int n) {
	if(a == b)
		return seg[n] = a;
	int mid = (a+b)/2;
	int l = segtree(a, mid, 2*n+1);
	int r = segtree(mid+1, b, 2*n+2);
	return seg[n] = (v[l] < v[r] ? l : r);
}

// [a,b]: array interval
// [l,r]: segtree interval
// n: segtree node
int argmin(int a, int b, int l, int r, int n) {
	if(b < l || r < a) return RAND_MAX;
	if(a <= l && r <= b) return seg[n];

	int mid = (l+r)/2;
	int lx = argmin(a, b, l, mid, 2*n+1);
	int rx = argmin(a, b, mid+1, r, 2*n+2);

	if(lx == RAND_MAX) return rx;
	if(rx == RAND_MAX) return lx;

	return (v[lx] < v[rx] ? lx : rx);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	for(int i = 0; i < N; i++)
		std::cin >> v[i];
	
	segtree(0, N-1, 0);
	
	int a, b, arg;
	while(M--) {
		std::cin >> a >> b;
		arg = argmin(a-1, b-1, 0, N-1, 0);
		std::cout << v[arg] << "\n";
	}
	
	return 0;
}
