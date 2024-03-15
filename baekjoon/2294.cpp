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

	int N, K;
	std::cin >> N >> K;

	std::vector<int> v(N);
	std::vector<long long int> dp(K+1, RAND_MAX);

	for(int i = 0; i < N; i++)
		std::cin >> v[i];
	
	dp[0] = 0;
	for(int i = 0; i < N; i++) {
		for(int k = v[i]; k <= K; k++)
			dp[k] = std::min(dp[k - v[i]] + 1, dp[k]);
	}

	std::cout << (dp[K] == RAND_MAX ? -1 : dp[K]);

	return 0;
}
