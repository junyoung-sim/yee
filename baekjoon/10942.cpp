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

#define MAX 2001

int N, M, S, E;
int v[MAX];
int dp[MAX][MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for(int i = 1; i <= N; i++)
		std::cin >> v[i];
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++)
			dp[i][j] = (i == j);
	}

	

	std::cin >> M;
	while(M--) {
		std::cin >> S >> E;
		std::cout << dp[S][E] << "\n";
	}
	
	return 0;
}
