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

	std::string str1 = "";
	std::string str2 = "";
	std::string lcs = "";

	std::cin >> str1 >> str2;
	int N = str1.length();
	int M = str2.length();

	int dp[N+1][M+1];
	for(int i = 0; i <= N; i++) dp[i][0] = 0;
	for(int j = 0; j <= M; j++) dp[0][j] = 0;

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = std::max(dp[i][j-1], dp[i-1][j]);
		}
	}
	
	int i = N, j = M;
	while(i >= 1 && j >= 1) {
		if(dp[i][j] > dp[i-1][j] && dp[i-1][j] == dp[i-1][j-1] && dp[i-1][j] == dp[i][j-1]) {
			lcs += str2[j-1];
			i--; j--;
		}
		else if(dp[i][j] == dp[i-1][j] && dp[i-1][j] > dp[i][j-1]) i--;
		else if(dp[i][j] == dp[i][j-1] && dp[i-1][j] < dp[i][j-1]) j--;
		else j--;
	}

	std::cout << dp[N][M] << "\n";
	std::reverse(lcs.begin(), lcs.end());
	std::cout << lcs << "\n";

	return 0;
}