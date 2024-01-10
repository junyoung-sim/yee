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

int N, M;
bool valid = false;

void dfs(int a, std::vector<std::vector<int>> &graph, std::vector<bool> &visited, int cnt) {
	if(cnt == 5) {
		valid = true;
		return;
	}

	visited[a] = true;
	for(int &b: graph[a]) {
		if(!visited[b]) {
			visited[b] = true;
			dfs(b, graph, visited, cnt+1);
			visited[b] = false;
		}
	}
	visited[a] = false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> N >> M;

	std::vector<std::vector<int>> graph(N, std::vector<int>());
	std::vector<bool> visited(N, false);

	int a, b;
	for(int i = 0; i < M; i++) {
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 0; i < N; i++) {
		dfs(i, graph, visited, 1);
		if(valid) {
			std::cout << "1\n";
			return 0;
		}
	}

	std::cout << "0\n";
	return 0;
}
