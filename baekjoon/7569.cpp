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

struct pos {
	int H, I, J;
	pos(int h, int i, int j) {
		H = h;
		I = i;
		J = j;
	}
	int h() { return H; }
	int i() { return I; }
	int j() { return J; }
};

int N, M, H;
int field[MAX][MAX][MAX];

int itr = 0;
bool complete = true;

int dh[6] = {0, 0, 0, 0, 1, -1};
int di[6] = {-1, 0, 1, 0, 0, 0};
int dj[6] = {0, 1, 0, -1, 0, 0};

std::queue<pos> q;

void input() {
	std::cin >> M >> N >> H;
	for(int h = 0; h < H; h++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				std::cin >> field[h][i][j];
				if(field[h][i][j] == 0) complete = false;
				if(field[h][i][j] == 1) q.push(pos(h, i, j));
			}
		}
	}
}

bool valid_pos(int h, int i, int j) {
	return (h >= 0 && h < H) && (i >= 0 && i < N) && (j >= 0 && j < M);
}

void bfs() {
	int n = q.size();
	while(!q.empty()) {
		int h0 = q.front().h();
		int i0 = q.front().i();
		int j0 = q.front().j();
		q.pop();

		for(int n = 0; n < 6; n++) {
			int h = h0 + dh[n];
			int i = i0 + di[n];
			int j = j0 + dj[n];
			if(valid_pos(h, i, j) && field[h][i][j] == 0) {
				field[h][i][j] = 1;
				q.push(pos(h, i, j));
			}
		}
		if(--n == 0) { n = q.size(); itr++; }
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	input();

	if(complete) {
		std::cout << "0\n";
		return 0;
	}

	bfs();

	for(int h = 0; h < H; h++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(field[h][i][j] == 0) {
					std::cout << "-1\n";
					return 0;
				}
			}
		}
	}

	std::cout << itr-1 << "\n";
	
	return 0;
}