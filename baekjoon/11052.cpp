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
	
	std::vector<int> dp(N+1);
	for(int n = 1; n <= N; n++) {
		dp[n] = v[n];
		for(int i = 1; i <= n; i++)
			dp[n] = std::max(dp[n], dp[n-i] + dp[i]);
	}

	std::cout << dp[N] << "\n";
	
	return 0;
}
