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
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> visit;

int count = 0;
void dfs(int i, int j) {
	visit[i][j] = 1; count++;
	for(int n = 0; n < 4; n++) {
		if(i+dr[n] >= 0 && i+dr[n] < N &&
		   j+dc[n] >= 0 && j+dc[n] < N &&
		   !visit[i+dr[n]][j+dc[n]]) dfs(i+dr[n], j+dc[n]);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	graph.resize(N, std::vector<int>(N));
	visit.resize(N, std::vector<int>(N));

	std::string str;
	for(int i = 0; i < N; i++) {
		std::cin >> str;
		for(int j = 0; j < N; j++) {
			graph[i][j] = str[j] - '0';
			visit[i][j] = !graph[i][j];
		}
	}

	std::vector<int> cmp;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!visit[i][j]) {
				dfs(i, j);
				cmp.push_back(count);
				count = 0;
			}
		}
	}

	std::cout << cmp.size() << "\n";
	if(cmp.size()) {
		std::sort(cmp.begin(), cmp.end());
		for(int &x: cmp)
			std::cout << x << "\n";
	}

	return 0;
}
