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

int T, V, E, a, b;
std::vector<std::vector<int>> graph;
std::vector<int> group;
std::queue<int> q;

void bfs(int start) {
	group[start] = 0; q.push(start);
	while(!q.empty()) {
		int i = q.front(); q.pop();
		for(int &j: graph[i]) {
			if(group[j] == RAND_MAX) {
				group[j] = !group[i];
				q.push(j);
			}
		}
	}
}

bool bipartite() {
	for(int i = 1; i <= V; i++) {
		for(int &j: graph[i])
			if(group[i] == group[j]) return false;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;
	while(T--) {
		std::cin >> V >> E;
		graph.clear(); graph.resize(V+1, std::vector<int>());
		group.clear(); group.resize(V+1, RAND_MAX);

		for(int i = 0; i < E; i++) {
			std::cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for(int i = 1; i <= V; i++)
			if(group[i] == RAND_MAX) bfs(i);

		std::cout << (bipartite() ? "YES" : "NO") << "\n";
	}
	
	return 0;
}
