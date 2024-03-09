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

int N, K;
int v[101];
long long int dp[10001] = {0};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> K;
	for(int n = 1; n <= N; n++)
		std::cin >> v[n];
	
	dp[0] = 1;
	for(int n = 1; n <= N; n++) {
		for(int k = v[n]; k <= K; k++)
			dp[k] += dp[k - v[n]];
	}

	std::cout << dp[K];
	
	return 0;
}
