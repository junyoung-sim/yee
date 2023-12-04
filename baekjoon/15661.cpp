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

int N, ans = RAND_MAX;
std::vector<int> t;
std::vector<std::vector<int>> v;

void solve(int i, int x, int sum) {
	t[i] = x;
	if(i == N-1) {
		if(sum == 0 || sum == N) return;

		std::vector<int> t0, t1;
		for(int k = 0; k < N; k++) {
			if(t[k]) t1.push_back(k);
			else t0.push_back(k);
		}

		int s0 = 0;
		for(int &x: t0)
			for(int &y: t0) s0 += v[x][y];
		int s1 = 0;
		for(int &x: t1)
			for(int &y: t1) s1 += v[x][y];

		ans = std::min(abs(s0 - s1), ans);
		return;
	}

	solve(i+1, 0, sum + 0);
	solve(i+1, 1, sum + 1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	t.resize(N);
	v.resize(N, std::vector<int>(N));
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) std::cin >> v[i][j];

	solve(0, 0, 0);
	solve(0, 1, 1);

	std::cout << ans << "\n";

	return 0;
}
