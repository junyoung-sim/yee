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

#define MAX 50

int T, N, M, K, ans;
int field[MAX][MAX];
int visit[MAX][MAX];

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

void init() {
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++)
			field[i][j] = visit[i][j] = 0;
	}
	ans = 0;
}

void test_case() {
	std::cin >> N;
	std::cin >> M;
	std::cin >> K;

	int i, j;
	while(K--) {
		std::cin >> i >> j;
		field[i][j] = 1;
	}
}

void dfs(int r, int c) {
	visit[r][c] = 1;
	for(int n = 0; n < 4; n++) {
		int i = r + dr[n];
		int j = c + dc[n];
		if(i >= 0 && i < N && j >= 0 && j < M && field[i][j] && !visit[i][j]) dfs(i, j);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	while(T--) {
		init();
		test_case();
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(field[i][j] && !visit[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		std::cout << ans << "\n";
	}
	
	return 0;
}