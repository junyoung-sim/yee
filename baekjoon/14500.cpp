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

int N, M, ans = -RAND_MAX;
std::vector<std::vector<int>> v;
std::vector<std::vector<int>> f;

void dfs(int i, int j, int k, int sum) {
	if(k == 4) {
		ans = std::max(sum, ans);
		return;
	}

	int dr[4] = {-1, 0, 1, 0};
	int dc[4] = {0, 1, 0, -1};
	for(int n = 0; n < 4; n++) {
		int r = i + dr[n], c = j + dc[n];
		if(r < 0 || r == N || c < 0 || c == M) continue;
		if(!f[r][c]) {
			f[r][c] = 1;
			dfs(r, c, k+1, sum + v[r][c]);
			f[r][c] = 0;
		}
	}
}

void tblock(int i, int j) {
	int dr[4][3] = {{0, 0, 1},{0, -1, 1},{0, -1, 0},{-1, 0, 1}};
	int dc[4][3] = {{-1, 1, 0},{-1, 0, 0},{-1, 0, 1},{0, 1, 0}};
	for(int n = 0; n < 4; n++) {
		int sum = v[i][j];
		bool valid = true;
		for(int k = 0; k < 3; k++) {
			int r = i + dr[n][k], c = j + dc[n][k];
			if(r < 0 || r == N || c < 0 || c == M) { valid = false; break; }
			sum += v[r][c];
		}
		if(valid) ans = std::max(sum, ans);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	v.resize(N, std::vector<int>(M,0));
	f.resize(N, std::vector<int>(M,0));

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) std::cin >> v[i][j];

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			f[i][j] = 1;
			dfs(i, j, 1, v[i][j]);
			f[i][j] = 0;

			tblock(i, j);		
		}
	}

	std::cout << ans << "\n";

	return 0;
}
