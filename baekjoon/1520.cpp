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

#define MAX 500

int N, M;
int v[MAX][MAX];
int dp[MAX][MAX]; // dp[i][j] = k; there are k ways to reach (N-1, M-1) from (i, j)

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int dfs(int i, int j) {
	if(i == N-1 && j == M-1) return 1;
	if(dp[i][j] != RAND_MAX) return dp[i][j];
	
	dp[i][j] = 0;
	for(int n = 0; n < 4; n++) {
		int r = i + dr[n];
		int c = j + dc[n];
		if(r >= 0 && r < N && c >= 0 && c < M && v[r][c] < v[i][j]) dp[i][j] += dfs(r, c);
	}

	return dp[i][j];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			std::cin >> v[i][j];
			dp[i][j] = RAND_MAX;
		}
	}

	std::cout << dfs(0, 0);
	
	return 0;
}
