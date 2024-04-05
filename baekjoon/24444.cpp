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
int R;

int k = 1;

std::vector<std::vector<int>> graph;
std::vector<int> visit;
std::queue<int> q;

void bfs() {
	q.push(R);
	visit[R] = k++;
	while(!q.empty()) {
		int i = q.front(); q.pop();
		for(int &j: graph[i])
			if(!visit[j]) {
				q.push(j);
				visit[j] = k++;
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
	std::cin >> R;

	graph.resize(N+1, std::vector<int>());
	visit.resize(N+1, 0);

	int u, v;
	for(int m = 0; m < M; m++) {
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int n = 1; n <= N; n++)
		std::sort(graph[n].begin(), graph[n].end());
	
	bfs();

	for(int n = 1; n <= N; n++)
		std::cout << visit[n] << "\n";
	
	return 0;
}
