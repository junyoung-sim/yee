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

std::vector<std::vector<int>> graph;
std::vector<bool> visit;

void dfs(int i) {
	visit[i] = true;
	std::cout << i << " ";

	for(int &j: graph[i])
		if(!visit[j]) dfs(j);
}

void bfs(int i) {
	std::queue<int> q;
	q.push(i); visit[i] = true;

	while(!q.empty()) {
		int x = q.front(); q.pop();
		std::cout << x << " ";
		for(int &k: graph[x]) {
			if(!visit[k]) {
				q.push(k);
				visit[k] = true;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m, v;
	std::cin >> n >> m >> v;

	graph.resize(n+1, std::vector<int>());
	visit.resize(n+1, false);

	int a, b;
	for(int i = 0; i < m; i++) {
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 1; i <= n; i++) std::sort(graph[i].begin(), graph[i].end());

	dfs(v); std::cout << "\n";
	std::fill(visit.begin(), visit.end(), false);
	bfs(v);
	
	return 0;
}
