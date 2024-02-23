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

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::cin >> N;
	std::cin >> K;

	std::vector<int> graph(100001, RAND_MAX);
	std::queue<int> q;
	
	q.push(N);
	graph[N] = 0;

	while(!q.empty()) {
		int x = q.front(); q.pop();
		if(x == K) break;
		if(x-1 >= 0 && graph[x-1] == RAND_MAX) { q.push(x-1); graph[x-1] = graph[x] + 1; }
		if(x+1 <= 100000 && graph[x+1] == RAND_MAX) { q.push(x+1); graph[x+1] = graph[x] + 1; }
		if(x*2 <= 100000 && graph[x*2] == RAND_MAX) { q.push(x*2); graph[x*2] = graph[x] + 1; }
	}

	int x = K;
	std::vector<int> path = {K};

	while(x != N) {
		if(x-1 >= 0 && graph[x-1] < graph[x]) x--;
		else if(x+1 <= 100000 && graph[x+1] < graph[x]) x++;
		else if(x%2 == 0 && graph[x/2] < graph[x]) x /= 2;
		path.push_back(x);
	}
	std::reverse(path.begin(), path.end());

	std::cout << graph[K] << "\n";
	for(int &p: path)
		std::cout << p << " ";
	std::cout << "\n";
	
	return 0;
}
