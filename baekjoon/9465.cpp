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

	int T;
	std::cin >> T;

	while(T--) {
		int N;
		std::cin >> N;

		std::vector<std::vector<int>> dp(2, std::vector<int>(N));
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < N; j++) std::cin >> dp[i][j];
		
		for(int k = 1; k < N; k++) {
			dp[0][k] += dp[1][k-1];
			dp[0][k] = std::max(dp[0][k-1], dp[0][k]);

			dp[1][k] += dp[0][k-1];
			dp[1][k] = std::max(dp[1][k-1], dp[1][k]);
		}
		
		std::cout << std::max(dp[0][N-1], dp[1][N-1]) << "\n";
	}
	
	return 0;
}
