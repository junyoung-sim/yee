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

	std::vector<int> v(N+1);
	for(int i = 1; i <= N; i++)
		std::cin >> v[i];
	
	std::vector<int> dp(N+1, 0);
	for(int i = 1; i <= N; i++) {
		dp[i] = v[i];
		for(int k = 1; k <= i; k++)
			dp[i] = std::min(dp[i], dp[i-k] + dp[k]);
	}

	std::cout << dp[N] << "\n";
	
	return 0;
}