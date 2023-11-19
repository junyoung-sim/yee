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

int N, M, K;
int ans = -RAND_MAX;

std::vector<std::vector<int>> v;
std::vector<std::vector<int>> filled;

void solve(int r, int c, int k, int sum) {
	if(k == K) {
		ans = std::max(sum, ans);
		return;
	}

	if(c > M) { r++; c = 1; }
	if(r > N) return;

	int i = r, j = c;
	while(i <= N) {
		if(!filled[i-1][j]) {
			filled[i][j] = 1;
			solve(i, j+2, k+1, sum+v[i][j]);
			filled[i][j] = 0;
		}
		if(++j > M) { i++; j = 1; }
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M >> K;

	v.resize(N+1, std::vector<int>(M+1, 0));
	filled.resize(N+1, std::vector<int>(M+1, 0));

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) std::cin >> v[i][j];

	solve(1, 1, 0, 0);
	std::cout << ans << "\n";

	return 0;
}
