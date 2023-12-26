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

	if(N % 2) {
		std::cout << "0\n";
		return 0;
	}

	int dp[31];
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for(int i = 3; i <= 30; i++) {
		if(i % 2) {
			dp[i] = 0;
			continue;
		}
		dp[i] = dp[i-2] * 3;
		for(int k = 4; k <= i; k += 2)
			dp[i] += dp[i-k] * 2;
	}

	std::cout << dp[N] << "\n";

	return 0;
}
