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
int ans = RAND_MAX;
int alpha = -1;

std::vector<int> v;
std::vector<std::vector<int>> w;

void tsp(int i, int depth, int cost) {
	if(depth == N) {
		if(w[i][alpha] != 0)
			ans = std::min(cost + w[i][alpha], ans);
		return;
	}

	for(int k = 0; k < N; k++) {
		if(v[k] || w[i][k] == 0) continue;
		v[k] = 1;
		tsp(k, depth+1, cost+w[i][k]);
		v[k] = 0;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	v.resize(N, 0);
	w.resize(N, std::vector<int>(N));

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) std::cin >> w[i][j];

	for(int i = 0; i < N; i++) {
		v[i] = 1; alpha = i;
		tsp(i, 1, 0);
		v[i] = 0;
	}

	std::cout << ans << "\n";

	return 0;
}