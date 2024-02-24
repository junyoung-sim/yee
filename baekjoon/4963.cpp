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

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(std::vector<std::vector<int>> &graph, int i, int j) {
	int N = graph.size();
	int M = graph[0].size();
	
	std::queue<std::pair<int, int>> q;
	
	q.push({i, j});
	graph[i][j] = RAND_MAX;

	while(!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for(int n = 0; n < 8; n++) {
			int pr = r+dr[n], pc = c+dc[n];
			if(pr >= 0 && pr < N && pc >= 0 && pc < M && graph[pr][pc] == 1) {
				q.push({pr, pc});
				graph[pr][pc] = RAND_MAX;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while(true) {
		int N, M;
		std::cin >> M;
		std::cin >> N;

		if(N == 0 && M == 0) break;

		std::vector<std::vector<int>> graph(N, std::vector<int>(M));
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				std::cin >> graph[i][j];
		
		int components = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(graph[i][j] == 1) {
					bfs(graph, i, j);
					components++;
				}
			}
		}

		std::cout << components << "\n";
	}
	
	return 0;
}