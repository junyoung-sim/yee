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

#define MAX 100

int N, M, u, v;
std::vector<int> cost(MAX+1, 0);
std::vector<int> jump(MAX+1, 0);

std::queue<int> q;

void input() {
	std::cin >> N;
	std::cin >> M;
	for(int i = 0; i < N+M; i++) {
		std::cin >> u >> v;
		jump[u] = v;
	}
}

void bfs(int x0) {
	q.push(x0);
	while(!q.empty()) {
		int x = q.front();
		int c = cost[x];
		q.pop();
		for(int i = 1; i <= 6; i++) {
			int nx = x + i;
			if(nx > MAX) continue;
			if(nx == MAX) {
				cost[nx] = c+1;
				return;
			}

			while(jump[nx]) nx = jump[nx];

			if(cost[nx]) continue;

			cost[nx] = c+1;
			q.push(nx);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	input();
	bfs(1);

	std::cout << cost[MAX] << "\n";

	return 0;
}