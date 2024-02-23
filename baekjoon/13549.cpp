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

typedef std::pair<int, int> Pair;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::cin >> N;
	std::cin >> K;

	std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
	std::vector<bool> visit(100001, false);

	pq.push({0, N});

	while(!pq.empty()) {
		int t = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		visit[x] = true;
		if(x == K) {
			std::cout << t << "\n";
			break;
		}

		if(x-1 >= 0 && !visit[x-1]) pq.push({t+1, x-1});
		if(x+1 <= 100000 && !visit[x+1]) pq.push({t+1, x+1});
		if(x*2 <= 100000 && !visit[x*2]) pq.push({t, x*2});
	}
	
	return 0;
}
