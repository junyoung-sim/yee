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

int N, M, R, C, MAX = 100;
std::vector<std::vector<int>> mat(MAX, std::vector<int>(MAX, 0));
std::vector<std::vector<int>> tmp(MAX, std::vector<int>(MAX, 0));

void refresh() {
	mat.swap(tmp);
	tmp.resize(MAX, std::vector<int>(MAX, 0));
	std::swap(N, M);
}

void f1() {
	for(int i = 0; i < N/2; i++) {
		for(int j = 0; j < M; j++)
			std::swap(mat[i][j], mat[N-1-i][j]);
	}
}

void f2() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M/2; j++)
			std::swap(mat[i][j], mat[i][M-1-j]);
	}
}

void f3() {
	for(int j = 0; j < M; j++) {
		for(int i = N-1; i >= 0; i--)
			tmp[j][N-1-i] = mat[i][j];
	}
	refresh();
}

void f4() {
	for(int j = M-1; j >= 0; j--) {
		for(int i = 0; i < N; i++)
			tmp[M-1-j][i] = mat[i][j];
	}
	refresh();
}

void f5() {
	for(int i = 0; i < N/2; i++) {
		for(int j = 0; j < M/2; j++)
			std::swap(mat[i][j], mat[i][j+M/2]);
	}
	for(int i = 0; i < N/2; i++) {
		for(int j = 0; j < M/2; j++)
			std::swap(mat[i][j], mat[i+N/2][j]);
	}
	for(int i = N/2; i < N; i++) {
		for(int j = 0; j < M/2; j++) {
			std::swap(mat[i][j], mat[i][j+M/2]);
		}
	}
}

void f6() {
	for(int i = 0; i < N/2; i++) {
		for(int j = 0; j < M/2; j++)
			std::swap(mat[i][j], mat[i+N/2][j]);
	}
	for(int i = 0; i < N/2; i++) {
		for(int j = 0; j < M/2; j++)
			std::swap(mat[i][j], mat[i][j+M/2]);
	}
	for(int i = 0; i < N/2; i++) {
		for(int j = M/2; j < M; j++)
			std::swap(mat[i][j], mat[i+N/2][j]);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M >> R;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) std::cin >> mat[i][j];
	
	while(R--) {
		std::cin >> C;
		if(C == 1) { f1(); continue; }
		if(C == 2) { f2(); continue; }
		if(C == 3) { f3(); continue; }
		if(C == 4) { f4(); continue; }
		if(C == 5) { f5(); continue; }
		if(C == 6) { f6(); continue; }
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++)
			std::cout << mat[i][j] << " ";
		std::cout << "\n";
	}
	
	return 0;
}