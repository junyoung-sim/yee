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

	int N; std::cin >> N;

	std::vector<int> v(N+1, 0);
	for(int i = 1; i <= N; i++) std::cin >> v[i];
	
	std::vector<std::vector<int>> dp(N+1, std::vector<int>(N+1, 0));
	for(int n = 1; n <= N; n++) {
		for(int i = 1; i <= n; i++) {
			dp[n][i] = dp[n][i-1];
			for(int k = 1; k <= n/i; k++)
				dp[n][i] = std::max(dp[n][i], v[i]*k + dp[n-i*k][n-i*k]);
		}
	}

	std::cout << dp[N][N] << "\n";
	
	return 0;
}
