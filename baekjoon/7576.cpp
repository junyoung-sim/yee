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

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

struct pos {
	int r, c;
	pos(int i, int j) {
		r = i;
		c = j;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int M, N;
	std::cin >> M >> N;

	std::queue<pos> q;
	std::vector<std::vector<int>> graph(N, std::vector<int>(M));

	bool complete = true;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			std::cin >> graph[i][j];
			if(graph[i][j] == 1) q.push(pos(i, j));
			if(!graph[i][j]) complete = false;
		}
	}
	if(complete) { std::cout << "0\n"; return 0; }

	int itr = 0, n = q.size();
	while(!q.empty()) {
		pos x = q.front(); q.pop();
		int r = x.r, c = x.c;
		for(int n = 0; n < 4; n++) {
			int pr = r+dr[n], pc = c+dc[n];
			if(pr >= 0 && pr < N && pc >= 0 && pc < M && graph[pr][pc] == 0) {
				graph[pr][pc] = 1;
				q.push(pos(pr, pc));
			}
		}
		if(--n == 0) { n = q.size(); itr++; }
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(!graph[i][j]) {
				std::cout << "-1\n";
				return 0;
			}
		}
	}

	std::cout << itr-1 << "\n";
	return 0;
}
