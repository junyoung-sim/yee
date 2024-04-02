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

int N, M;
int m[101];
int c[101];

int dp[101][10001]; // dp[i][c] = m; maximum of m bytes can be freed from [1, i] at cost c
int ans = RAND_MAX; // minimum cost

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	std::cin >> M;

	for(int i = 1; i <= N; i++) std::cin >> m[i];
	for(int i = 1; i <= N; i++) std::cin >> c[i];

	for(int i = 1; i <= N; i++) {
		for(int cost = 0; cost <= 10000; cost++) {
			if(cost < c[i]) dp[i][cost] = dp[i-1][cost];
			else {
				dp[i][cost] = std::max(dp[i-1][cost-c[i]] + m[i], dp[i-1][cost]);
				if(dp[i][cost] >= M)
					ans = std::min(cost, ans);
			}
		}
	}

	std::cout << ans;
	
	return 0;
}