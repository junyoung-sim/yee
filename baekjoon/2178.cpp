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

struct pos {
	int r, c;
	pos(int i, int j) {
		r = i;
		c = j;
	}
};

int N, M;
std::vector<std::vector<int>> graph;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int bfs(int i, int j) {
	std::queue<pos> q;
	q.push(pos(i, j));
	while(!q.empty()) {
		pos x = q.front(); q.pop();
		int r = x.r, c = x.c;
		for(int n = 0; n < 4; n++) {
			int pr = r+dr[n], pc = c+dc[n];
			if(pr >= 0 && pr < N && pc >= 0 && pc < M && graph[r+dr[n]][c+dc[n]] == 1) {
				graph[pr][pc] = graph[r][c] + 1;
				q.push(pos(pr, pc));
			}
		}
	}
	return graph[N-1][M-1];
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	graph.resize(N, std::vector<int>(M));

	std::string str;
	for(int i = 0; i < N; i++) {
		std::cin >> str;
		for(int j = 0; j < M; j++)
			graph[i][j] = str[j] - '0';
	}

	std::cout << bfs(0, 0) << "\n";

	return 0;
}
