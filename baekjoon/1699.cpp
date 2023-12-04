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

	std::vector<int> dp(N+1, 0);
	dp[1] = 1; dp[2] = 2; dp[3] = 3; dp[4] = 1;

	for(int i = 5; i <= N; i++) {
		dp[i] = RAND_MAX;
		for(int k = 1; k*k <= i; k++)
			dp[i] = std::min(dp[i], dp[i-k*k]+1);
	}

	std::cout << dp[N] << "\n";

	return 0;
}
