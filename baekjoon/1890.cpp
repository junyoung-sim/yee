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

int N;
int v[MAX][MAX];
long long int dp[MAX][MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			std::cin >> v[i][j];
			dp[i][j] = 0;
		}
	}
	
	dp[0][0] = 1; // dp[i][j] = k; there are k ways to reach (i, j)
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(i == N-1 && j == N-1) break;
			if(i + v[i][j] < N) dp[i + v[i][j]][j] += dp[i][j];
			if(j + v[i][j] < N) dp[i][j + v[i][j]] += dp[i][j];
		}
	}

	std::cout << dp[N-1][N-1];
	
	return 0;
}