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

#define MAX 1000001

int N;
int dp[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i = 4; i <= N; i++) {
		dp[i] = RAND_MAX;
		if(i % 3 == 0) dp[i] = std::min(dp[i/3]+1, dp[i]);
		if(i % 2 == 0) dp[i] = std::min(dp[i/2]+1, dp[i]);
		dp[i] = std::min(dp[i-1]+1, dp[i]);
	}

	std::cout << dp[N] << "\n";

	int i = N;
	while(i != 1) {
		std::cout << i << " ";
		if(i % 3 == 0 && dp[i] == dp[i/3]+1) { i /= 3; continue; }
		if(i % 2 == 0 && dp[i] == dp[i/2]+1) { i /= 2; continue; }
		i--;
	}

	std::cout << 1;

	return 0;
}
