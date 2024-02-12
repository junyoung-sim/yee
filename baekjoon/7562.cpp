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

int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

struct pos {
	int r, c;
	pos(int i, int j) {
		r = i;
		c = j;
	}
};

int T, I;
pos start(-1, -1), end(-1, -1);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> T;

	while(T--) {
		std::cin >> I;
		std::cin >> start.r >> start.c;
		std::cin >> end.r >> end.c;

		std::queue<pos> q;
		std::vector<std::vector<int>> graph(I, std::vector<int>(I, 0));

		q.push(start);
		while(!q.empty()) {
			pos x = q.front(); q.pop();
			int r = x.r, c = x.c;
			if(r == end.r && c == end.c) {
				std::cout << graph[r][c] << "\n";
				break;
			}
			for(int n = 0; n < 8; n++) {
				int pr = r+dr[n], pc = c+dc[n];
				if(pr >= 0 && pr < I && pc >= 0 && pc < I && graph[pr][pc] == 0) {
					graph[pr][pc] = graph[r][c] + 1;
					q.push(pos(pr, pc));
				}
			}
		}
	}
	
	return 0;
}
