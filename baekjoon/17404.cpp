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

	int v[N+1][3];
	for(int i = 1; i <= N; i++) {
		std::cin >> v[i][0];
		std::cin >> v[i][1];
		std::cin >> v[i][2];
	}

	int dp[N][3], ans = 10000000;
	for(int k = 0; k < 3; k++) {
		for(int i = 1; i <= N; i++) {
			dp[i][0] = v[i][0]; 
			dp[i][1] = v[i][1];
			dp[i][2] = v[i][2];
			
			if(i == 1) {
				for(int j = 0; j < 3; j++)
					if(j != k) dp[i][j] = 10000000;
				continue;
			}
			if(i == 2 || i == N) dp[i][k] = 10000000;

			dp[i][0] += std::min(dp[i-1][1], dp[i-1][2]);
			dp[i][1] += std::min(dp[i-1][0], dp[i-1][2]);
			dp[i][2] += std::min(dp[i-1][0], dp[i-1][1]);
		}
		for(int j = 0; j < 3; j++)
			ans = std::min(dp[N][j], ans);
	}

	std::cout << ans << "\n";
	
	return 0;
}
