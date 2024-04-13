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

	int N;
	std::cin >> N;

	int v[N];
	for(int i = 0; i < N; i++) std::cin >> v[i];

	std::stack<int> line;
	std::stack<int> side;

	for(int i = N-1; i >= 0; i--) line.push(v[i]);

	int turn = 1;
	while(!line.empty()) {
		if(line.top() == turn) { line.pop(); turn++; continue; }
		if(!side.empty() && side.top() == turn) { side.pop(); turn++; continue; }
		side.push(line.top()); line.pop();
	}

	while(!side.empty() && side.top() == turn) { side.pop(); turn++; }

	std::cout << (turn == N+1 ? "Nice": "Sad");
	
	return 0;
}