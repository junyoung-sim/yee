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

int N, M, R, k = 1;
std::vector<std::vector<int>> graph;
std::vector<int> visit;

void dfs(int i) {
	visit[i] = k++;
	for(int &j: graph[i])
		if(!visit[j]) dfs(j);
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

	int a, b;
	while(M--) {
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for(int i = 0; i < N; i++)
		std::sort(graph[i].begin(), graph[i].end());
	
	dfs(R);
	for(int i = 1; i <= N; i++)
		std::cout << visit[i] << "\n";
	
	return 0;
}