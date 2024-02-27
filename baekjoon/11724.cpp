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

void dfs(int i, std::vector<std::vector<int>> &graph, std::vector<bool> &visit) {
	visit[i] = true;
	for(int &j: graph[i])
		if(!visit[j]) dfs(j, graph, visit);
}

void bfs(int i, std::vector<std::vector<int>> &graph, std::vector<bool> &visit) {
	std::queue<int> q;
	q.push(i);

	while(!q.empty()) {
		int x = q.front(); q.pop();
		visit[x] = true;
		for(int &k: graph[x])
			if(!visit[k]) q.push(k);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	std::vector<std::vector<int>> graph(N+1, std::vector<int>());
	std::vector<bool> visit(N+1, false);

	int a, b;
	for(int i = 0; i < M; i++) {
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	int ans = 0;
	for(int i = 1; i <= N; i++) {
		if(!visit[i]) {
			dfs(i, graph, visit);
			//bfs(i, graph, visit);
			ans++;
		}
	}

	std::cout << ans << "\n";
	
	return 0;
}
