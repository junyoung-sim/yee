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

#define MAX 1000

struct pos {
	int f;
	int i;
	int j;
};

int N, M;
int ans = RAND_MAX;

int graph[MAX][MAX];
int visit[2][MAX][MAX] = {0};

int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

std::queue<pos> q;

void input() {
	std::cin >> N;
	std::cin >> M;
	std::string row;
	for(int i = 0; i < N; i++) {
		std::cin >> row;
		for(int j = 0; j < M; j++)
			graph[i][j] = row[j] - '0';
	}
}

bool valid(int f, int i, int j) {
	return (i >= 0) && (i < N) && (j >= 0) && (j < M) && !visit[f][i][j];
}

int bfs(int f0, int i0, int j0) {
	q.push({f0, i0, j0});
	visit[f0][i0][j0] = 1;

	while(!q.empty()) {
		pos p = q.front();
		f0 = p.f;
		i0 = p.i;
		j0 = p.j;
		q.pop();

		if(i0 == N-1 && j0 == M-1) return visit[f0][i0][j0];

		for(int n = 0; n < 4; n++) {
			int i = i0 + di[n];
			int j = j0 + dj[n];
			if(!valid(f0, i, j)) continue;
			if(!graph[i][j]) {
				visit[f0][i][j] = visit[f0][i0][j0] + 1;
				q.push({f0, i, j});
			}
			if(graph[i][j] && !f0) {
				visit[1][i][j] = visit[f0][i0][j0] + 1;
				q.push({1, i, j});
			}
		}
	}

	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	input();

	std::cout << bfs(0, 0, 0) << "\n";
	
	return 0;
}