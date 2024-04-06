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
int M;
int ans = 0;

std::vector<std::vector<int>> graph;
std::vector<bool> visit;
std::queue<int> q;

void bfs(int r) {
	q.push(r);
	visit[r] = true;
	while(!q.empty()) {
		int i = q.front(); q.pop();
		for(int &j: graph[i]) {
			if(!visit[j]) {
				q.push(j);
				visit[j] = true;
				ans++;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	std::cin >> M;

	graph.resize(N+1, std::vector<int>());
	visit.resize(N+1, false);

	int u, v;
	while(M--) {
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bfs(1);

	std::cout << ans;
	
	return 0;
}
