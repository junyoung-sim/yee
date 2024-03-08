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

int T, k, n;
int dp[15][15] = {0};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for(int i = 0; i <= 14; i++) {
		for(int j = 1; j <= 14; j++) {
			if(i == 0) { dp[i][j] = j; continue; }
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}

	std::cin >> T;
	while(T--) {
		std::cin >> k >> n;
		std::cout << dp[k][n] << "\n";
	}
	
	return 0;
}
